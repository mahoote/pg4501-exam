#include "donkeyKong/dkBarrel.h"

void DK_Barrel::init()
{
    memory.initSprite("/Donkey_Kong_Game/Barrel/Barrel_1", &barrelSprite, &barrelSpriteImage);
    randomPositionY(&barrelPositionY);
    randomPositionX(&barrelPositionX);
    startDropBarrelFrame = random(800);
}

void DK_Barrel::dropBarrel()
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
}

void DK_Barrel::randomPositionY(int *positionY)
{
    *positionY = -random(100);
}

void DK_Barrel::randomPositionX(int *positionX)
{
    *positionX = random(SCREEN_WIDTH - 35) + 10;
}