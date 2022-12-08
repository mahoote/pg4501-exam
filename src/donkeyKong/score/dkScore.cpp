#include "donkeyKong/score/dkScore.h"

unsigned int *DK_Score::getCurrentScore()
{
    return &currentScore;
}
void DK_Score::setCurrentScore(unsigned int _score)
{
    currentScore = _score;
}

unsigned int *DK_Score::addCurrentScore(unsigned int _points)
{
    unsigned newScore = *getCurrentScore() += _points;

    if (newScore > 999999)
        newScore = 999999;

    setCurrentScore(newScore);
    return getCurrentScore();
}

void DK_Score::dropBonus()
{
    static int frameCounter;
    frameCounter++;

    // 30 frames in a second
    if (frameCounter >= 30 && bonus != 0)
    {
        frameCounter = 0;

        if (bonus > 0)
        {
            bonus = bonus - 100;
        }
        if (bonus <= 0)
        {
            bonus = 0;
        }
    }
}

int *DK_Score::getBonus()
{
    return &bonus;
}

void DK_Score::resetBonus()
{
    bonus = startBonus;
}

void DK_Score::resetCurrentScore()
{
    currentScore = 0;
}

void DK_Score::updateHighScore()
{
    if (currentScore > highScore)
    {
        highScore = currentScore;
    }
}

unsigned int *DK_Score::getHighScore()
{
    return &highScore;
}

void DK_Score::setHighScore(unsigned int _score)
{
    highScore = _score;
}

int **DK_Score::getScores()
{
    return &scores;
}

int *DK_Score::getScoreListSize()
{
    return &scoreListSize;
}
