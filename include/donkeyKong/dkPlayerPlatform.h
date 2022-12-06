#include <Arduino.h>

#ifndef __DK_PLAYER_PLATFORM_H__
#define __DK_PLAYER_PLATFORM_H__

class DK_PlayerPlatform
{
public:
    void getPlayerValues(int *_playerPositionX,
                         int *_playerPositionY,
                         int *_addPlatformYValue,
                         bool *_isMoving,
                         bool *_playerLeft,
                         bool *_playerRight);
    void changePlatformY();
    int *getAddPlatformYValue();

private:
    int *playerPositionX,
        *playerPositionY,
        *addPlatformYValue;

    bool *isMovingX,
        *playerLeft,
        *playerRight;
};

#endif