#include "cstuff.h"
#include "doomtype.h"
#include "doomstat.h"
#include "m_random.h"
#include "d_player.h"
#include "g_game.h"
#include "lprintf.h"
#include "p_saveg.h"
#include "p_map.h"
#include "r_demo.h"
#include "r_draw.h"
#include "r_fps.h"
#include "r_main.h"
#include "s_sound.h"
#include "s_advsound.h"

#include "stdio.h"
#include "p_tick.h"

extern void RecalculateDrawnSubsectors(void);
extern int totalleveltimes;
extern int numlines;
extern line_t* lines;
extern dboolean setsizeneeded;
extern byte* savebuffer;
extern size_t savegamesize;

extern int xLineId;
extern int xLineCrossed;
extern int xLineVertexes[2][2];

typedef struct {
    int tic;
    byte* save;
} xSavepoint_t;

static xSavepoint_t savepoints[40]; //autosavepoint at 0

int playeringameGet(int plr) {
    if (plr < 0 || plr > 3) {
        return 0;
    }

    return playeringame[plr];
}

void playeringameSet(int plr, int val) {
    if (plr < 0 || plr > 3) {
        return;
    }

    playeringame[plr] = val == 0 ? 0 : 1;
}

void x_setLinedefCheck(int linedef) {
    int i;
    if (linedef == -1) {
        linedef = xLineId;
    }
    xLineId = -1;

    for (i = 0; i < numlines; ++i) {
        if (linedef == lines[i].iLineID) {
            xLineId = lines[i].iLineID;
            xLineVertexes[0][0] = lines[i].v1->x;
            xLineVertexes[0][1] = lines[i].v1->y;
            xLineVertexes[1][0] = lines[i].v2->x;
            xLineVertexes[1][1] = lines[i].v2->y;
            break;
        }
    }

    if (xLineId == -1) {
        xLineVertexes[0][0] = 0;
        xLineVertexes[0][1] = 0;
        xLineVertexes[1][0] = 0;
        xLineVertexes[1][1] = 0;
    }
}

int x_getRngIndex(void) {
    return rng.rndindex;
}

double x_getXPos(void) {
    if (gamestate != GS_LEVEL) return 0;
    return players[displayplayer].mo->x / (double)0x10000;
}

double x_getYPos(void) {
    if (gamestate != GS_LEVEL) return 0;
    return players[displayplayer].mo->y / (double)0x10000;
}

double x_getZPos(void) {
    if (gamestate != GS_LEVEL) return 0;
    return players[displayplayer].mo->z / (double)0x10000;
}

double x_getPrevXPos(void) {
    if (gamestate != GS_LEVEL) return 0;
    return players[displayplayer].mo->PrevX / (double)0x10000;
}

double x_getPrevYPos(void) {
    if (gamestate != GS_LEVEL) return 0;
    return players[displayplayer].mo->PrevY / (double)0x10000;
}

double x_getXMom(void) {
    if (gamestate != GS_LEVEL) return 0;
    return players[displayplayer].mo->momx / (double)0x10000;
}

double x_getYMom(void) {
    if (gamestate != GS_LEVEL) return 0;
    return players[displayplayer].mo->momy / (double)0x10000;
}

double x_getZMom(void) {
    if (gamestate != GS_LEVEL) return 0;
    return players[displayplayer].mo->momz / (double)0x10000;
}

signed char x_getAngle(void) {
    if (gamestate != GS_LEVEL) return 0;
    return players[displayplayer].mo->angle * (-64.0 / ANG90) + 128;
}

void x_initHeader(unsigned char* header) {
    int i;
    if (!header) {
        return;
    }

    *header++ = 109;
    *header++ = gameskill;
    *header++ = gameepisode;
    *header++ = gamemap;
    *header++ = deathmatch;
    *header++ = respawnparm;
    *header++ = fastparm;
    *header++ = nomonsters;
    *header++ = consoleplayer;
    for (i = 0; i < 4; ++i) {
        *header++ = playeringame[i];
    }
}

void x_clearMapSavepoints(void) {
    int i;
    for (i = 1; i < 40; ++i) {
        free(savepoints[i].save);
        savepoints[i].save = NULL;
        savepoints[i].tic = 0;
    }
}

void x_clearUserSavepoint() {
    free(savepoints[0].save);
    savepoints[0].save = NULL;
    savepoints[0].tic = 0;
}

static int x_getSavepointIndex(int dest) {
    int index = -1;
    int savetic = 0;
    int map = gamemap;

    if (map > 39) {
        map = 39;
    }

    if (savepoints[0].save && savepoints[0].tic < dest) {
        index = 0;
        savetic = savepoints[0].tic;
    }

    for (; map > 0; --map) {
        if (savetic < savepoints[map].tic && savepoints[map].tic < dest) {
            index = map;
            break;
        }
    }

    return index;
}

int x_getSavepointTic(int dest) {
    int index = x_getSavepointIndex(dest);
    if (index < 0) {
        return 0;
    }

    return savepoints[index].tic;
}

int x_setSavepoint(int isUserSave) {
    int map = gamemap;

    if (map < 0 || map > 39 || gamestate != GS_LEVEL || gameaction != ga_nothing) {
        return 1;
    }

    if (leveltime != 1 || isUserSave != 0) {
        map = 0;
    }

    if (savepoints[map].save) {
        free(savepoints[map].save);
        savepoints[map].save = NULL;
    }

    savepoints[map].save = malloc(savegamesize);
    savepoints[map].tic = gametic;
    save_p = savebuffer = savepoints[map].save;


    // do save
    {
        int i;
        *save_p++ = compatibility_level;

        *save_p++ = gameskill;
        *save_p++ = gameepisode;
        *save_p++ = gamemap;

        for (i = 0; i < MAXPLAYERS; ++i) {
            *save_p++ = playeringame[i];
        }

        for (; i < 32; ++i) { //32 = MIN_MAXPLAYERS in g_game.c
            *save_p++ = 0;
        }

        *save_p++ = idmusnum;

        save_p = G_WriteOptions(save_p);

        memcpy(save_p, &leveltime, sizeof leveltime);
        save_p += sizeof leveltime;

        memcpy(save_p, &totalleveltimes, sizeof totalleveltimes);
        save_p += sizeof totalleveltimes;

        *save_p++ = (gametic - basetic) & 255;

        Z_CheckHeap();
        P_ArchivePlayers();
        Z_CheckHeap();

        P_ThinkerToIndex();

        P_ArchiveWorld();
        Z_CheckHeap();
        P_ArchiveThinkers();
        Z_CheckHeap();
        P_ArchiveSpecials();

        P_IndexToThinker();

        P_ArchiveRNG();
        Z_CheckHeap();
        P_ArchiveMap();

        *save_p++ = 0xe6;

        Z_CheckHeap();
    }
    // done


    savepoints[map].save = savebuffer; //incase checksavegame reallocated savebuffer
    save_p = savebuffer = NULL;
    return 0;
}

//modified G_DoLoadGame
int x_loadSavepoint(int dest) {
    int i;
    save_p = NULL;
    int map = x_getSavepointIndex(dest);

    if (map < 0) {
        return 1;
    }

    if (map != 0) {
        x_clearUserSavepoint();
    }

    save_p = savepoints[map].save;
    gametic = savepoints[map].tic;

    gameaction = ga_nothing;

    compatibility_level = *save_p++;

    gameskill = *save_p++;
    gameepisode = *save_p++;
    gamemap = *save_p++;

    for (i = 0; i < MAXPLAYERS; ++i) {
        playeringame[i] = *save_p++;
    }

    save_p += 28; //28 = MIN_MAXPLAYERS - MAXPLAYERS in g_game.c

    idmusnum = *save_p++;
    if (idmusnum == 255)
        idmusnum = -1;

    save_p += (G_ReadOptions(save_p) - save_p);


    G_InitNew(gameskill, gameepisode, gamemap);

    memcpy(&leveltime, save_p, sizeof leveltime);
    save_p += sizeof leveltime;

    memcpy(&totalleveltimes, save_p, sizeof totalleveltimes);
    save_p += sizeof totalleveltimes;

    basetic = gametic - *save_p++;

    P_MapStart();
    P_UnArchivePlayers();
    P_UnArchiveWorld();
    P_UnarchiveThinkersAndSpecials();
    P_UnArchiveRNG();
    P_UnArchiveMap();
    P_MapEnd();
    R_ActivateSectorInterpolations();
    R_SmoothPlaying_Reset(NULL);

    if (musinfo.current_item != -1) {
        S_ChangeMusInfoMusic(musinfo.current_item, true);
    }

    RecalculateDrawnSubsectors();

    if (*save_p != 0xe6)
        I_Error("x_loadSavepoint: Bad savepoint on map %i", map);

    if (setsizeneeded)
        R_ExecuteSetViewSize();

    R_FillBackScreen();

    save_p = NULL;

    return 0;
}
