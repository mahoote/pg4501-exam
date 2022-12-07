#include <Arduino.h>
#include <TFT_eSPI.h>

#include "main.h"
#include "donkeyKong/dkPlayer.h"
#include "donkeyKong/dkBarrel.h"
#include "donkeyKong/dkBoss.h"

#ifndef __DONKEY_KONG_GAME_H__
#define __DONKEY_KONG_GAME_H__

class DonkeyKongGame
{
public:
    void init();
    void play();

private:
    DK_Player player;
    DK_Boss boss;
    SpriteImage donkeyKongBackgroundImage;
};

#endif