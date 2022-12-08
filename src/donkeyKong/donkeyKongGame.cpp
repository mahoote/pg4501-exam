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
    memory.initSprite("/Donkey_Kong_Game/Donkey_Kong_Background_2", screenSprite, &donkeyKongBackgroundImage);
    screenSprite->setSwapBytes(true);

    player.init();
    boss.init();
    for (int i = 0; i < barrelAmount; i++)
    {
        barrels[i].init();
    }
}

void DonkeyKongGame::play()
{
    static byte playerHit;
    static unsigned int prevScore;
    static byte prevScoreSet = 0;

    TFT_eSprite *screenSprite = display.getScreenSprite();
    joystick.setJoystickValues();

    screenSprite->fillSprite(TFT_BLACK);

    // screenSprite->pushImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, *donkeyKongBackgroundImage.getBuffer());

    if (!startGame)
    {
        printPressToPlay();
        printHighScores();

        if (*joystick.getButtonState() == 0)
        {
            startGame = true;
        }
    }
    else
    {
        if (playerHit == 0)
        {
            screenSprite->pushImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, *donkeyKongBackgroundImage.getBuffer());

            player.movement();
            boss.drawBoss();

            for (int i = 0; i < barrelAmount; i++)
            {
                barrels[i].dropBarrel(&player, &playerHit);
            }

            printPoints("100", &prevScore, &prevScoreSet);
        }
        else
        {
            prevScore = 0;
            prevScoreSet = 0;
            playerHit = 0;
            startGame = false;
            resetGame();
        }
    }

    printDefaultUI();

    screenSprite->pushSprite(0, 0);
}

void DonkeyKongGame::resetGame()
{
    player.reset();
    for (int i = 0; i < barrelAmount; i++)
    {
        barrels[i].reset();
    }
}

void DonkeyKongGame::printPoints(String value, unsigned int *prevScore, byte *prevScoreSet)
{
    static bool printPoints;
    static int playerPosX;
    static int playerPosY;
    static int showPointsFrameCounter;

    unsigned int currentScore = *score.getCurrentScore();

    if (*prevScore == 0 && *prevScoreSet == 0)
    {
        *prevScoreSet = 1;
        *prevScore = currentScore;
    }

    if (*prevScore != currentScore)
    {
        printPoints = true;
        showPointsFrameCounter = 0;
        playerPosX = *player.getPositionX();
        playerPosY = *player.getPositionY();
    }

    if (printPoints && showPointsFrameCounter < 60)
    {
        showPointsFrameCounter++;
        text.writeText(value, playerPosX, playerPosY, TFT_WHITE);
    }
    else
    {
        printPoints = false;
        showPointsFrameCounter = 60;
    }

    *prevScore = currentScore;
}

void DonkeyKongGame::printDefaultUI()
{
    text.writeText("HIGH SCORE", 40, 0, TFT_RED);
    text.writeText("000000", 53, 10, TFT_WHITE);

    text.writeText("1UP", 14, 0, TFT_RED);

    int currentScore = *score.getCurrentScore();
    int scoreDigitCount = score.count_digit(currentScore);
    String scoreString = "";

    if (scoreDigitCount < 6)
    {
        int remainds = 6 - scoreDigitCount;
        for (int i = 0; i < remainds; i++)
        {
            scoreString += "0";
        }
    }
    if (currentScore != 0)
        scoreString += String(currentScore);

    text.writeText(scoreString, 3, 10, TFT_WHITE);

    text.writeText("L=00", 104, 22, TFT_BLUE);
}

void DonkeyKongGame::printHighScores()
{
    text.writeText("RANK", 3, 100, TFT_LIGHT_BLUE, 1);
    text.writeText("1ST", 3, 123, TFT_RED, 2);
    text.writeText("2ND", 3, 146, TFT_RED, 2);
    text.writeText("3RD", 3, 169, TFT_RED, 2);
    text.writeText("4TH", 3, 192, TFT_YELLOW, 2);
    text.writeText("5TH", 3, 215, TFT_YELLOW, 2);

    text.writeText("SCORE", 58, 100, TFT_LIGHT_BLUE, 1);
    text.writeText("000000", 58, 123, TFT_RED, 2);
    text.writeText("000000", 58, 146, TFT_RED, 2);
    text.writeText("000000", 58, 169, TFT_RED, 2);
    text.writeText("000000", 58, 192, TFT_YELLOW, 2);
    text.writeText("000000", 58, 215, TFT_YELLOW, 2);
}

void DonkeyKongGame::printPressToPlay()
{
    static int pressPlayFrameCounter;
    int showPressPlayFrame = 30;

    pressPlayFrameCounter++;

    if (pressPlayFrameCounter >= showPressPlayFrame)
    {
        text.writeText("PRESS PLAY TO START", 10, 60, TFT_LIGHT_BLUE);
    }
    if (pressPlayFrameCounter >= showPressPlayFrame * 2)
    {
        pressPlayFrameCounter = 0;
    }
}