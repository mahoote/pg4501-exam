#include <Arduino.h>
#include "io/joystick.h"
#include <TFT_eSPI.h>

#ifndef __DONKEY_KONG_GAME_H__
#define __DONKEY_KONG_GAME_H__

#define MARIO_SIZE_X 32
#define MARIO_SIZE_Y 32

class DonkeyKongGame
{
public:
    void initDisplay(TFT_eSPI *tft);
    void play(TFT_eSprite *screenSprite, Joystick *joystick);

private:
    void movement(int *stickValueX, int *stickValueY);
    void timeInAirDelay();
    void movementHorizontally(int *stickValueX);
    void movementJump(int *stickValueY);
    void enableGravity();
};

#endif