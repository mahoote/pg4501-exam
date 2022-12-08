#include "donkeyKong/dkBarrel.h"

void DK_Barrel::init()
{
    memory.initSprite("/Donkey_Kong_Game/Barrel/Barrel_1", &barrelSprite, &barrelSpriteImage);
    reset();
}

void DK_Barrel::reset()
{
    startDropBarrelFrame = random(400);
    randomPositionY(&barrelPositionY);
    randomPositionX(&barrelPositionX);
    frameCounter = 0;
}

void DK_Barrel::dropBarrel(DK_Player *player, byte *playerHit)
{
    if (frameCounter < startDropBarrelFrame)
    {
        frameCounter++;
    }
    else
    {
        if (barrelPositionY < 250)
        {
            barrelPositionY = barrelPositionY + 2;
        }
        else
        {
            randomPositionY(&barrelPositionY);
            randomPositionX(&barrelPositionX);
        }

        display.drawImageToScreen(&barrelPositionX, &barrelPositionY, &barrelSprite, &barrelSpriteImage);

        if (playerCollision(player->getPositionX(), player->getPositionY(),
                            player->getWidth(), player->getHeight(),
                            &barrelPositionX, &barrelPositionY,
                            barrelSpriteImage.getWidth(), barrelSpriteImage.getHeight()))
        {
            *playerHit = 1;
        }
    }
}

void DK_Barrel::randomPositionY(int *positionY)
{
    *positionY = -random(100);
}

void DK_Barrel::randomPositionX(int *positionX)
{
    *positionX = random(SCREEN_WIDTH - 35) + 10;
}

bool DK_Barrel::playerCollision(int *playerX, int *playerY, short *playerWidth, short *playerHeight,
                                int *barrelX, int *barrelY, short *barrelWidth, short *barrelHeight)
{
    boolean result = false;

    // Top left corner
    if ((*playerX >= *barrelX && *playerX <= (*barrelX + *barrelWidth)) &&

        (*playerY >= *barrelY && *playerY <= (*barrelY + *barrelHeight)))
    {
        result = true;
    }

    // Bottom Right corner.
    if (((*playerX + *playerWidth) >= *barrelX && (*playerX + *playerWidth) <= (*barrelX + *barrelWidth)) &&

        ((*playerY + *playerHeight) >= *barrelY && (*playerY + *playerHeight) <= (*barrelY + *barrelHeight)))
    {
        result = true;
    }

    return result;
}