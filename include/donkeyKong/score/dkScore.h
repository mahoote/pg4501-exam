#include "Arduino.h"

#ifndef __DK_SCORE_H__
#define __DK_SCORE_H__

class DK_Score
{
public:
    unsigned int *getHighScore();
    void resetCurrentScore();
    void updateHighScore();
    void resetBonus();
    void dropBonus();
    int *getBonus();
    unsigned int *getCurrentScore();
    void setCurrentScore(unsigned int _score);
    void setHighScore(unsigned int _score);
    unsigned int *addCurrentScore(unsigned int _points);
    int **getScores();
    int *getScoreListSize();

private:
    unsigned int highScore = 0;
    unsigned int currentScore = 0;
    int bonus;
    int startBonus = 5000;
    int *scores;
    int scoreListSize = 0;
};

#endif