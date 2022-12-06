#include "donkeyKong/dkPlayerPlatform.h"

int updateFrame = 5;

void DK_PlayerPlatform::getPlayerValues(int *_playerPositionX,
                                        int *_playerPositionY,
                                        int *_addPlatformYValue,
                                        bool *_isMovingX,
                                        bool *_isMovingY,
                                        bool *_playerLeft,
                                        bool *_playerRight,
                                        bool *_playerUp,
                                        bool *_playerDown,
                                        bool *_gravityEnabled)
{
    playerPositionX = _playerPositionX;
    playerPositionY = _playerPositionY;
    addPlatformYValue = _addPlatformYValue;
    isMovingX = _isMovingX;
    isMovingY = _isMovingY;
    playerLeft = _playerLeft;
    playerRight = _playerRight;
    playerUp = _playerUp;
    playerDown = _playerDown;
    gravityEnabled = _gravityEnabled;
}

void DK_PlayerPlatform::changePlatformY()
{
    static int frameCounter;
    frameCounter++;

    // First floor
    // if (*playerPositionY > 240 && *playerPositionY < 150)
    // {

    if (gravityEnabled)
    {
        if (*isMovingX)
        {
            if (*playerPositionX > 56)
            {
                if (frameCounter == updateFrame)
                {
                    if (*playerLeft)
                    {
                        *addPlatformYValue = *addPlatformYValue - 1;
                    }
                    else if (*playerRight)
                    {
                        *addPlatformYValue = *addPlatformYValue + 1;
                    }
                }
            }
            else
            {
                *addPlatformYValue = 8;
            }
        }

        if (*playerUp)
        {
            if (*playerPositionX > 100 && *playerPositionX < 120)
            {
                *gravityEnabled = false;
            }
        }
    }

    if (!*gravityEnabled)
    {
        // *addPlatformYValue = *addPlatformYValue + 1;

        if (*playerUp)
        {
            *addPlatformYValue = *addPlatformYValue + 1;
        }
        else if (*playerDown)
        {
            *addPlatformYValue = *addPlatformYValue - 1;
        }
    }

    if (frameCounter == updateFrame)
        frameCounter = 0;
}

int *DK_PlayerPlatform::getAddPlatformYValue()
{
    return addPlatformYValue;
}

bool *DK_PlayerPlatform::getGravityEnabled()
{
    return gravityEnabled;
}