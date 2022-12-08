/* ==================================================
    This class is used to make the player "interact" with the platforms
    and latters. There is no collision detection, but code that makes it seem
    like he is walking on the platforms.
   ================================================== */

#include "donkeyKong/player/dkPlayerPlatform.h"

void DK_PlayerPlatform::getPlayerValues(int *_playerPositionX,
                                        int *_playerPositionY,
                                        int *_addPlatformYValue,
                                        bool *_isMovingX,
                                        bool *_isMovingY,
                                        bool *_playerLeft,
                                        bool *_playerRight,
                                        bool *_playerUp,
                                        bool *_gravityEnabled,
                                        bool *_isGrounded,
                                        bool *_isJumping)
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
    isJumping = _isJumping;
    isGrounded = _isGrounded;
}

void DK_PlayerPlatform::changePlatformY()
{
    frameCounter++;

    int firstFloorY[2] = {240, 194};
    int latterX[2] = {105, 115};
    int firstFloorSlopeStartX = 56;
    int firstFloorLatterTop = -1;
    int firstPlatformYValue = 8;

    int secondFloorY[2] = {194, 164};
    int secondLatterX[2] = {50, 60};
    int secondFloorSlopeStartX = 118;
    int secondFloorLatterTop = 189;
    int secondPlatformYValue = 35;

    int thirdFloorY[2] = {164, 134};
    int thirdLatterX[2] = {105, 115};
    int thirdFloorSlopeStartX = 18;
    int thirdFloorLatterTop = 154;
    int thirdPlatformYValue = 65;

    int fourthFloorY[2] = {134, 99};
    int fourthLatterX[2] = {10, 20};
    int fourthFloorSlopeStartX = 118;
    int fourthFloorLatterTop = 127;
    int fourthPlatformYValue = 96;

    int fifthFloorY[2] = {100, 71};
    int fifthLatterX[2] = {105, 115};
    int fifthFloorSlopeStartX = 18;
    int fifthFloorLatterTop = 96;
    int fifthPlatformYValue = 127;

    int sixthFloorY[2] = {71, 0};
    int sixthLatterX[2] = {-1, -1};
    int sixthFloorSlopeStartX = 88;
    int sixthFloorLatterTop = 62;
    int sixthPlatformYValue = 162;

    // First floor
    moveOnPlatform(firstFloorY, latterX, firstFloorSlopeStartX, firstPlatformYValue, 5, 1, 1);
    climbLatter(latterX[0], latterX[1], secondFloorLatterTop, secondPlatformYValue, 0);

    // Second floor
    moveOnPlatform(secondFloorY, secondLatterX, secondFloorSlopeStartX, secondPlatformYValue, 6, 1, 0);
    climbLatter(secondLatterX[0], secondLatterX[1], thirdFloorLatterTop, thirdPlatformYValue, 1);

    // Third floor
    moveOnPlatform(thirdFloorY, thirdLatterX, thirdFloorSlopeStartX, thirdPlatformYValue, 5, 1, 1);
    climbLatter(thirdLatterX[0], thirdLatterX[1], fourthFloorLatterTop, fourthPlatformYValue, 2);

    // Fourth floor
    moveOnPlatform(fourthFloorY, fourthLatterX, fourthFloorSlopeStartX, fourthPlatformYValue, 5, 1, 0);
    climbLatter(fourthLatterX[0], fourthLatterX[1], fifthFloorLatterTop, fifthPlatformYValue, 3);

    // Fifth floor
    moveOnPlatform(fifthFloorY, fifthLatterX, fifthFloorSlopeStartX, fifthPlatformYValue, 5, 1, 1);
    climbLatter(fifthLatterX[0], fifthLatterX[1], sixthFloorLatterTop, sixthPlatformYValue, 4);

    // Sixth floor
    moveOnPlatform(sixthFloorY, sixthLatterX, sixthFloorSlopeStartX, sixthPlatformYValue, 5, -1, 1);
}

void DK_PlayerPlatform::moveOnPlatform(int floorY[],
                                       int latterX[],
                                       int floorSlopeStart,
                                       int currentPlatformYValue,
                                       int updateFrame,
                                       int slopeValue,
                                       byte slopeRight)
{
    static int lastPlayerPosX;

    if (*playerPositionY < floorY[0] && *playerPositionY > floorY[1])
    {
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
                                *addPlatformYValue = *addPlatformYValue - slopeValue;
                            }
                            else if (*playerRight)
                            {
                                *addPlatformYValue = *addPlatformYValue + slopeValue;
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
                                *addPlatformYValue = *addPlatformYValue + slopeValue;
                            }
                            else if (*playerRight)
                            {
                                *addPlatformYValue = *addPlatformYValue - slopeValue;
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
                    *isJumping = false;
                    *isGrounded = true;
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

void DK_PlayerPlatform::climbLatter(int latterStart, int latterEnd, int latterTop, int newPlatformYValue, short floorLevel)
{
    if (climbLatterUp && playerCurrentFloor == floorLevel)
    {
        if (*playerPositionX > latterStart && *playerPositionX<latterEnd && * playerPositionY> latterTop)
        {
            *addPlatformYValue = *addPlatformYValue + 1;
        }
        else
        {
            score.addCurrentScore(100);
            climbLatterUp = false;
            *gravityEnabled = true;
            playerCurrentFloor++;
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

bool *DK_PlayerPlatform::getIsGrounded()
{
    return isGrounded;
}

bool *DK_PlayerPlatform::getIsJumping()
{
    return isJumping;
}
