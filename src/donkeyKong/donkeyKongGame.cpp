/* TODO: screenSizeHeight - MARIO_SIZE_Y make variable */

#include "donkeyKong/donkeyKongGame.h"

bool initBarrels = true;

void DonkeyKongGame::init()
{
    TFT_eSprite *screenSprite = display.getScreenSprite();

    memory.initSD();
    memory.initSprite("/Donkey_Kong_Game/Donkey_Kong_Background_2", screenSprite, &donkeyKongBackgroundImage);
    screenSprite->setSwapBytes(true);

    player.init();
    boss.init();
}

void DonkeyKongGame::play()
{
    TFT_eSprite *screenSprite = display.getScreenSprite();
    joystick.setJoystickValues();
    screenSprite->fillSprite(TFT_BLACK);

    // Menu
    if (!startGame)
    {
        if (initMenu)
        {
            initMenu = false;

            score.resetBonus();
            score.resetCurrentScore();

            int *scoreSize = score.getScoreListSize();
            int **scores = score.getScores();
            scoreFile.getScoresFromFile(scores, scoreSize);
            sorter.bubbleSort(*scores, *scoreSize);
            score.setHighScore((*scores)[0]);
        }

        printPressToPlay();
        printHighScores();

        if (*joystick.getButtonState() == 0)
        {
            startGame = true;
        }
    }
    // In game
    else
    {
        if (levelCounter <= 0)
            levelCounter = 1;

        createBarrels();

        if (playerHit != 0)
        {
            scoreFile.saveScoreToFile(*score.getCurrentScore());
            gameOver();
        }
        else if (*player.getPositionY() <= 36 && *player.getPositionX() > 60 && *player.getPositionX() < 90)
        {
            score.addCurrentScore(*score.getBonus());
            resetGame();
            levelCounter++;
            prevScore = *score.getCurrentScore();
            barrelAmount = barrelAmount + 2;
        }
        // Gameplay
        else
        {
            screenSprite->pushImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, *donkeyKongBackgroundImage.getBuffer());

            player.movement();
            boss.drawBoss();

            for (int i = 0; i < barrelAmount; i++)
            {
                barrels[i]->dropBarrel(&player, &playerHit);
            }

            score.dropBonus();
            String bonusString = text.leadingZerosString(4, *score.getBonus());
            text.writeText(bonusString, 106, 45, TFT_WHITE);

            printPoints("100");
            score.updateHighScore();
        }
    }

    printDefaultUI();

    screenSprite->pushSprite(0, 0);
}

void DonkeyKongGame::createBarrels()
{
    // Create all the instances of the barrel based on the amount.
    // This will increase per round.
    if (initBarrels)
    {
        initBarrels = false;
        barrels = new DK_Barrel *[barrelAmount];
        for (int i = 0; i < barrelAmount; i++)
        {
            barrels[i] = new DK_Barrel();
            barrels[i]->init();
        }
    }
}

void DonkeyKongGame::gameOver()
{
    initMenu = true;
    startGame = false;
    prevScore = 0;
    prevScoreSet = 0;
    playerHit = 0;
    barrelAmount = 5;
    levelCounter = 0;
    resetGame();
}

void DonkeyKongGame::resetGame()
{
    player.reset();
    for (int i = 0; i < barrelAmount; i++)
    {
        barrels[i]->reset();
        delete barrels[i];
    }
    delete[] barrels;

    initBarrels = true;
    score.resetBonus();
}

void DonkeyKongGame::printPoints(String value)
{
    static bool printPoints;
    static int playerPosX;
    static int playerPosY;
    static int showPointsFrameCounter;

    unsigned int currentScore = *score.getCurrentScore();

    if (prevScore == 0 && prevScoreSet == 0)
    {
        prevScoreSet = 1;
        prevScore = currentScore;
    }

    if (prevScore != currentScore)
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

    prevScore = currentScore;
}

void DonkeyKongGame::printDefaultUI()
{
    text.writeText("HIGH SCORE", 40, 0, TFT_RED);

    String highScoreString = text.leadingZerosString(6, *score.getHighScore());
    text.writeText(highScoreString, 53, 10, TFT_WHITE);

    text.writeText("1UP", 14, 0, TFT_RED);

    int currentScore = *score.getCurrentScore();

    String scoreString = text.leadingZerosString(6, currentScore);

    text.writeText(scoreString, 3, 10, TFT_WHITE);

    String levelString = text.leadingZerosString(2, levelCounter);
    String printLevelString = "L=" + levelString;

    text.writeText(printLevelString, 104, 22, TFT_BLUE);
}

void DonkeyKongGame::printHighScores()
{
    int *scores = *score.getScores();

    text.writeText("RANK", 3, 100, TFT_LIGHT_BLUE, 1);
    text.writeText("1ST", 3, 123, TFT_RED, 2);
    text.writeText("2ND", 3, 146, TFT_RED, 2);
    text.writeText("3RD", 3, 169, TFT_RED, 2);
    text.writeText("4TH", 3, 192, TFT_YELLOW, 2);
    text.writeText("5TH", 3, 215, TFT_YELLOW, 2);

    text.writeText("SCORE", 58, 100, TFT_LIGHT_BLUE, 1);

    String scoreString1 = text.leadingZerosString(6, scores[0]);
    text.writeText(scoreString1, 58, 123, TFT_RED, 2);

    String ScoreString2 = text.leadingZerosString(6, scores[1]);
    text.writeText(ScoreString2, 58, 146, TFT_RED, 2);

    String scoreString3 = text.leadingZerosString(6, scores[2]);
    text.writeText(scoreString3, 58, 169, TFT_RED, 2);

    String scoreString4 = text.leadingZerosString(6, scores[3]);
    text.writeText(scoreString4, 58, 192, TFT_YELLOW, 2);

    String scoreString5 = text.leadingZerosString(6, scores[4]);
    text.writeText(scoreString5, 58, 215, TFT_YELLOW, 2);
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