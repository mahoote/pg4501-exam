#include <Arduino.h>

#ifndef __DK_PLAYER_PLATFORM_H__
#define __DK_PLAYER_PLATFORM_H__

class DK_PlayerPlatform
{
public:
    void getPlayerValues(int *_playerPositionX,
                         int *_playerPositionY,
                         int *_addPlatformYValue,
                         bool *_isMovingX,
                         bool *_isMovingY,
                         bool *_playerLeft,
                         bool *_playerRight,
                         bool *_playerUp,
                         bool *_gravityEnabled);
    void changePlatformY();
    int *getAddPlatformYValue();
    bool *getGravityEnabled();

private:
    void moveOnPlatform(int floorY[],
                        int latterX[],
                        int floorSlopeStart,
                        int currentPlatformYValue,
                        int updateFrame,
                        byte slopeRight);
    void climbLatter(int latterStart, int latterEnd, int latterTop, int newPlatformYValue);

    int *playerPositionX,
        *playerPositionY,
        *addPlatformYValue;

    bool *isMovingX,
        *isMovingY,
        *playerLeft,
        *playerRight,
        *playerUp,
        *playerDown,
        *gravityEnabled;

    bool climbLatterUp = false;
    bool climbLatterDown = false;
    int frameCounter = 0;
};

#endif