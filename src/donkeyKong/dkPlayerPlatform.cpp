#include "donkeyKong/dkPlayerPlatform.h"

void DK_PlayerPlatform::getPlayerValues(int *_playerPositionX,
                                        int *_playerPositionY,
                                        int *_addPlatformYValue,
                                        bool *_isMovingX,
                                        bool *_isMovingY,
                                        bool *_playerLeft,
                                        bool *_playerRight,
                                        bool *_playerUp,
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
    gravityEnabled = _gravityEnabled;
}

void DK_PlayerPlatform::changePlatformY()
{
    frameCounter++;

    int firstFloorY[2] = {240, 194};
    int latterX[2] = {100, 120};
    int firstFloorSlopeStart = 56;
    int firstPlatformYValue = 8;

    int secondFloorY[2] = {195, 138};
    int secondLatterX[2] = {45, 65};
    int secondFloorSlopeStart = 120;
    int secondPlatformYValue = 35;
    int secondFloorLatterTop = 189;

    int thirdPlatformYValue = 70;

    // First floor
    moveOnPlatform(firstFloorY, latterX, firstFloorSlopeStart, firstPlatformYValue, 5, 1);
    climbLatter(latterX[0], latterX[1], secondFloorLatterTop, secondPlatformYValue);

    // Second floor
    moveOnPlatform(secondFloorY, secondLatterX, secondFloorSlopeStart, secondPlatformYValue, 6, 0);
    // climbLatter(secondLatterX[0], secondLatterX[1], secondFloorY[1], thirdPlatformYValue);
}

void DK_PlayerPlatform::moveOnPlatform(int floorY[],
                                       int latterX[],
                                       int floorSlopeStart,
                                       int currentPlatformYValue,
                                       int updateFrame,
                                       byte slopeRight)
{
    static int lastPlayerPosX;

    if (*playerPositionY < floorY[0] && *playerPositionY > floorY[1])
    {
        Serial.print("Running");
        Serial.println(currentPlatformYValue);

        if (gravityEnabled)
        {
            if (*isMovingX && lastPlayerPosX != *playerPositionX)
            {
                if (slopeRight == 1)
                {

                    if (*playerPositionX > floorSlopeStart)
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
                        *addPlatformYValue = currentPlatformYValue;
                    }
                }
                else if (slopeRight == 0)
                {
                    if (*playerPositionX < floorSlopeStart)
                    {
                        if (frameCounter == updateFrame)
                        {
                            if (*playerLeft)
                            {
                                *addPlatformYValue = *addPlatformYValue + 1;
                            }
                            else if (*playerRight)
                            {
                                *addPlatformYValue = *addPlatformYValue - 1;
                            }
                        }
                    }
                    else
                    {
                        *addPlatformYValue = currentPlatformYValue;
                    }
                }
            }

            if (*playerPositionX > latterX[0] && *playerPositionX < latterX[1])
            {
                if (*playerUp)
                {
                    *gravityEnabled = false;
                }
            }
        }

        if (!*gravityEnabled)
        {
            if (*playerUp)
            {
                climbLatterUp = true;
            }
        }

        if (frameCounter >= updateFrame)
        {
            frameCounter = 0;
        }

        lastPlayerPosX = *playerPositionX;
    }
}

void DK_PlayerPlatform::climbLatter(int latterStart, int latterEnd, int latterTop, int newPlatformYValue)
{
    if (climbLatterUp)
    {
        if (*playerPositionX > latterStart && *playerPositionX<latterEnd && * playerPositionY> latterTop)
        {
            *addPlatformYValue = *addPlatformYValue + 1;
        }
        else
        {
            climbLatterUp = false;
            *gravityEnabled = true;
            *addPlatformYValue = newPlatformYValue;
        }
    }
}

int *DK_PlayerPlatform::getAddPlatformYValue()
{
    return addPlatformYValue;
}

bool *DK_PlayerPlatform::getGravityEnabled()
{
    return gravityEnabled;
}