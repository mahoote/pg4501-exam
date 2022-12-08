#include "donkeyKong/dkBarrel.h"

void DK_Barrel::init()
{
    memory.initSprite("/Donkey_Kong_Game/Barrel/Barrel_1", &barrelSprite, &barrelSpriteImage);
    randomPositionY(&barrelPositionY);
    randomPositionX(&barrelPositionX);
    startDropBarrelFrame = random(800);
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
    }

    if (playerCollision(barrelPositionX, barrelPositionY,
                        player->getPositionX(), player->getPositionY(),
                        player->getWidth(), player->getHeight()))
    {
        Serial.println("Hit player!");
        *playerHit = 1;
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

bool DK_Barrel::playerCollision(int barrelX, int barrelY, int *playerX, int *playerY, short *playerWidth, short *playerHeight)
{
    boolean result = false;

    if ((barrelX >= *playerX && barrelX <= (*playerX + *playerWidth)) &&

        (barrelY >= *playerY && barrelY <= (*playerY + *playerHeight)))
    {
        result = true;
    }

    return result;
}