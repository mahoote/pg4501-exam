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

private:
    void createBarrels();
    void resetGame();
    void gameOver();
    void printPoints(String value);
    void printDefaultUI();
    void printHighScores();
    void printPressToPlay();

    int barrelAmount = 5;

    DK_Player player;
    DK_Boss boss;
    DK_Barrel **barrels;
    SpriteImage donkeyKongBackgroundImage;
    TFT_Text text;

    bool startGame = false;
    byte playerHit;
    unsigned int prevScore;
    byte prevScoreSet = 0;
    short levelCounter;
};

#endif