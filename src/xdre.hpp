/*
 * controls the program
 */

#ifndef __XDRE_HPP
#define __XDRE_HPP

#include <string>
#include <vector>
#include <functional>
#include <cstdio>

enum SpStyle {
    SP_NOSAVE = -1,
    SP_USER = 0,
    SP_START = 1,
    SP_AUTO = 2
};

struct BruteTic {
    unsigned int tic;
    int fire; //-1=no, 0=both, 1=yes
    int use; //-1=no, 0=both, 1=yes
    bool turnsAreAngles; // use absolute angles instead of turns
    std::vector<signed char> turnCmds;
    std::vector<signed char> runCmds;
    std::vector<signed char> strafeCmds;
};

struct BruteCheck {
    unsigned int tic;
    bool use;
    std::function<bool(int)> rngFunc;
    std::function<bool(int)> damageFunc;
    std::function<bool(double)> xPosFunc;
    std::function<bool(double)> yPosFunc;
    std::function<bool(double)> xMomFunc;
    std::function<bool(double)> yMomFunc;
    std::function<bool(double)> speedFunc;
};

namespace xdre {
    //you better call this
    void init();
    //
    bool bruteForce(std::vector<BruteTic> bruteTics, BruteCheck const& bruteCheck, bool const& abort);
    //does sdl events, mainly moving window and resize, maybe in future walkcam
    //currently shuts down whole program without asking anything if you close
    //xdre through sdl window
    void doSdlEvents();
    //better be in "wb"/"rb" mode
    bool save(std::FILE* file);
    bool load(std::FILE* file);
    void setSavepoint();
    void unsetSavepoint();
    //goes fwd/bwd numTics
    void seekDemo(int numTics);
    void copyTic();
    void deleteTic();
    void newTic();
    //changes displayplayer, does NOT change consoleplayer
    void changePlayerView(unsigned int plr);
    //set palette shit on/off (blood, pickups etc)
    void toggleBlood();
    void toggleFire();
    void toggleUse();
    void changeWeapon(char wpn);
    void run(signed char val);
    void strafe(signed char val);
    void turn(signed char val);
    void turnStepLeft();
    void turnStepRight();

    void setSavepointStyle(int style);
    void setLinedefCheck(int linedef);

    std::string getTicString(unsigned int n);
    unsigned int getTiclistSize();
    int getRngIndex();
    double getXPos();
    double getYPos();
    double getZPos();
    double getXMom();
    double getYMom();
    double getZMom();
    double getDistanceMoved();
    double getDirectionMoved();
    signed char getAngle();
    bool getUseSuccess();
    bool getLinedefCrossed();
    double getLinedefVertex(int n, int xy);
    double getDistanceFromLine();
    int getDoneDamage();
    float getTime();
    unsigned int getCurrentTic();
    unsigned int getSavepointTic();
    int getSavepointStyle();
    bool getBlood();
};


#endif // __XDRE_HPP
