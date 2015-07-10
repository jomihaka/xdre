/*
 * avoiding macro minefield
 */
#ifndef __CSTUFF_H
#define __CSTUFF_H

int playeringameGet(int plr); //get
void playeringameSet(int plr, int val); //set
//-1 refreshes current line
void x_setLinedefCheck(int linedef);
int x_getRngIndex(void);
signed char x_getAngle(void);
double x_getXPos(void);
double x_getYPos(void);
double x_getZPos(void);
double x_getPrevXPos(void);
double x_getPrevYPos(void);
double x_getXMom(void);
double x_getYMom(void);
double x_getZMom(void);
void x_initHeader(unsigned char* header);
void x_clearMapSavepoints(void);
void x_clearUserSavepoint(void);
int x_getSavepointTic(int dest);
//try if saveing is feasible
//return 0 if good
int x_setSavepoint(int isUserSave);
//loads closest savepoint around gametic = tic
//return 0 if good
int x_loadSavepoint(int dest);


#endif // __CSTUFF_H
