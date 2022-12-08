#include "Arduino.h"

#ifndef __DK_SCORE_H__
#define __DK_SCORE_H__

class DK_Score
{
public:
    unsigned int *getCurrentScore();
    void setCurrentScore(unsigned int _score);
    unsigned int *addCurrentScore(unsigned int _points);
    int count_digit(int number);

private:
    unsigned int highScore = 0;
    unsigned int currentScore = 0;
};

#endif