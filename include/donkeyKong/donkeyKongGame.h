#include <Arduino.h>
#include <TFT_eSPI.h>

#include "main.h"
#include "io/tftText.h"
#include "donkeyKong/player/dkPlayer.h"
#include "donkeyKong/dkBarrel.h"
#include "donkeyKong/dkBoss.h"
#include "donkeyKong/score/dkScoreBoard.h"

#ifndef __DONKEY_KONG_GAME_H__
#define __DONKEY_KONG_GAME_H__

class DonkeyKongGame
{
public:
    void init();
    void play();
    void resetGame();

private:
    void printPoints(String value, unsigned int *prevScore, byte *prevScoreSet);
    void printDefaultUI();
    void printHighScores();
    void printPressToPlay();

    DK_Player player;
    DK_Boss boss;
    SpriteImage donkeyKongBackgroundImage;
    TFT_Text text;

    bool startGame = false;
};

#endif