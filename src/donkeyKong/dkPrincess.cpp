#include "donkeyKong/dkPrincess.h"

void DK_Princess::init()
{
    princessPositionX = 56;
    princessPositionY = 30;

    helpSignX = 73;
    helpSignY = 30;

    memory.initSprite("/Donkey_Kong_Game/Princess/Princess_Idle", &princessSprite, &princessSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Princess/Princess_Scream", &princessScreamSprite, &princessScreamSpriteImage);
    memory.initSprite("/Donkey_Kong_Game/Princess/Princess_Help_Text", &helpSprite, &helpSpriteImage);

    changeImageFrame = random(200);
}

void DK_Princess::drawPrincess()
{
    static int randomImage;
    frameCounter++;

    if (frameCounter < changeImageFrame)
    {
        display.drawImageToScreen(&princessPositionX, &princessPositionY, &princessSprite, &princessSpriteImage);
    }
    else
    {
        static int screamFrameCounter = 0;
        screamFrameCounter++;

        display.drawImageToScreen(&helpSignX, &helpSignY, &helpSprite, &helpSpriteImage);

        if (screamFrameCounter <= 5)
        {
            display.drawImageToScreen(&princessPositionX, &princessPositionY, &princessScreamSprite, &princessScreamSpriteImage);
        }
        else if (screamFrameCounter > 5 && screamFrameCounter <= 10)
        {
            display.drawImageToScreen(&princessPositionX, &princessPositionY, &princessSprite, &princessSpriteImage);
        }

        if (screamFrameCounter >= 10)
        {
            screamFrameCounter = 0;
        }

        if (frameCounter > changeImageFrame + 60)
        {
            frameCounter = 0;
        }
    }
}