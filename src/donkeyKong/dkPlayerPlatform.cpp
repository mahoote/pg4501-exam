#include "donkeyKong/dkPlayerPlatform.h"

void DK_PlayerPlatform::getPlayerValues(int *_playerPositionX,
                                        int *_playerPositionY,
                                        int *_addPlatformYValue,
                                        bool *_isMovingX,
                                        bool *_playerLeft,
                                        bool *_playerRight)
{
    playerPositionX = _playerPositionX;
    playerPositionY = _playerPositionY;
    addPlatformYValue = _addPlatformYValue;
    isMovingX = _isMovingX;
    playerLeft = _playerLeft;
    playerRight = _playerRight;
}

void DK_PlayerPlatform::changePlatformY()
{
    // First floor
    // if (*playerPositionY > 240 && *playerPositionY < 150)
    // {

    if (*playerPositionX > 56 && *isMovingX)
    {
        if (*playerRight)
        {
            *addPlatformYValue = *addPlatformYValue + 1;
        }
        if (*playerLeft)
        {
            *addPlatformYValue = *addPlatformYValue - 1;
        }
    }
    // }
}

int *DK_PlayerPlatform::getAddPlatformYValue()
{
    return addPlatformYValue;
}