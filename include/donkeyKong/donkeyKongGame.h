#include <Arduino.h>
#include <TFT_eSPI.h>

#include "main.h"
#include "io/tftText.h"
#include "donkeyKong/player/dkPlayer.h"
#include "donkeyKong/dkBarrel.h"
#include "donkeyKong/dkBoss.h"
#include "donkeyKong/dkPrincess.h"
#include "donkeyKong/score/dkScoreBoard.h"
#include "donkeyKong/score/dkScoreFile.h"
#include "array/sorter.h"
#include "sound/donkeyKongSound.h"

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
    void showLoadingScreen(TFT_eSprite *screenSprite);
    void showGameOverScreen(TFT_eSprite *screenSprite);

    int defaultBarrelAmount = 3;
    int barrelAmount;

    Sorter sorter;
    DK_ScoreFile scoreFile;
    DK_Player player;
    DK_Boss boss;
    DK_Princess princess;
    DK_Barrel **barrels;
    SpriteImage donkeyKongBackgroundImage;
    TFT_Text text;
    DonkeyKongSound dkSound;

    bool showLoader = true;
    bool showGameOver = false;
    bool startGame = false;
    bool initMenu = true;
    byte playerHit;
    unsigned int prevScore;
    byte prevScoreSet = 0;
    short levelCounter;
};

#endif