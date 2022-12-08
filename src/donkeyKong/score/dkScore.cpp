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
    setCurrentScore(*getCurrentScore() += _points);
    return getCurrentScore();
}