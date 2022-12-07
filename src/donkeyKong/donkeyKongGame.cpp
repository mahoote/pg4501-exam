/* TODO: screenSizeHeight - MARIO_SIZE_Y make variable */

#include "donkeyKong/donkeyKongGame.h"

int barrelAmount = 5;

DK_Barrel barrels[5];
// DK_Barrel barrel;
// DK_Barrel barrelTwo;

void DonkeyKongGame::init()
{
    TFT_eSprite *screenSprite = display.getScreenSprite();

    memory.initSD();
    player.init();
    boss.init();

    memory.initSprite("/Donkey_Kong_Game/Donkey_Kong_Background_2", screenSprite, &donkeyKongBackgroundImage);
    screenSprite->setSwapBytes(true);

    for (int i = 0; i < barrelAmount; i++)
    {
        barrels[i].init();
    }

    // barrel.init();
    // barrelTwo.init();
}

void DonkeyKongGame::play()
{
    TFT_eSprite *screenSprite = display.getScreenSprite();
    joystick.setJoystickValues();

    screenSprite->fillScreen(TFT_BLACK);
    screenSprite->pushImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, *donkeyKongBackgroundImage.getBuffer());

    player.movement();
    boss.drawBoss();

    for (int i = 0; i < barrelAmount; i++)
    {
        barrels[i].dropBarrel();
    }

    // barrel.dropBarrel();
    // barrelTwo.dropBarrel();

    screenSprite->pushSprite(0, 0);
}