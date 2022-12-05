/* TODO: screenSizeHeight - MARIO_SIZE_Y make variable */

#include <Arduino.h>

#include "donkeyKong/donkeyKongGame.h"

DK_Player player;

void DonkeyKongGame::init()
{
    memory.initSD();
    player.init();
}

void DonkeyKongGame::play()
{
    TFT_eSprite *screenSprite = display.getScreenSprite();
    joystick.setJoystickValues();

    screenSprite->fillScreen(TFT_WHITE);
    player.movement();
    screenSprite->pushSprite(0, 0);
}