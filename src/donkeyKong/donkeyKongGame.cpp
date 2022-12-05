/* TODO: screenSizeHeight - MARIO_SIZE_Y make variable */

#include <Arduino.h>

#include "donkeyKong/donkeyKongGame.h"

DK_Player player;

SpriteImage donkeyKongBackgroundImage;

void DonkeyKongGame::init()
{
    TFT_eSprite *screenSprite = display.getScreenSprite();

    memory.initSD();
    player.init();

    memory.initSprite("/Donkey_Kong_Game/Donkey_Kong_Background", screenSprite, &donkeyKongBackgroundImage);
    screenSprite->setSwapBytes(true);
}

void DonkeyKongGame::play()
{
    TFT_eSprite *screenSprite = display.getScreenSprite();
    joystick.setJoystickValues();

    screenSprite->fillScreen(TFT_BLACK);
    screenSprite->pushImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, *donkeyKongBackgroundImage.getBuffer());

    player.movement();
    screenSprite->pushSprite(0, 0);
}