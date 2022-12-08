#include "Arduino.h"
#include "main.h"

#ifndef __DK_SCORE_FILE_H__
#define __DK_SCORE_FILE_H__

class DK_ScoreFile
{
public:
    void getScoresFromFile(int **scores, int *size);
    void saveScoreToFile(int _score);
    void initFile();

private:
    String getFilePath();
    int scoresAmount = 0;
};

#endif