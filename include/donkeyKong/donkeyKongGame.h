#include <Arduino.h>
#include "donkeyKong/dkPlayer.h"
#include <TFT_eSPI.h>

#ifndef __DONKEY_KONG_GAME_H__
#define __DONKEY_KONG_GAME_H__

class DonkeyKongGame
{
public:
    void init(Memory *m);
    void play(Joystick *joystick);
};

#endif