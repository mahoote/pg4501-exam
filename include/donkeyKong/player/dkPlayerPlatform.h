#include <Arduino.h>

#include "donkeyKong/score/dkScoreBoard.h"

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
                         bool *_gravityEnabled,
                         bool *_isGrounded,
                         bool *_isJumping);
    void changePlatformY();
    int *getAddPlatformYValue();
    bool *getGravityEnabled();
    bool *getIsGrounded();
    bool *getIsJumping();
    void reset();

private:
    void moveOnPlatform(int floorY[],
                        int latterX[],
                        int floorSlopeStart,
                        int currentPlatformYValue,
                        int updateFrame,
                        int slopeValue,
                        byte slopeRight);
    void climbLatter(int latterStart, int latterEnd, int latterTop, short floorLevel);

    int *playerPositionX,
        *playerPositionY,
        *addPlatformYValue;

    bool *isMovingX,
        *isMovingY,
        *playerLeft,
        *playerRight,
        *playerUp,
        *playerDown,
        *gravityEnabled,
        *isGrounded,
        *isJumping;

    bool climbLatterUp = false;
    int frameCounter = 0;
    int playerCurrentFloor = 0;
};

#endif