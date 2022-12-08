#include "donkeyKong/score/dkScoreFile.h"

void DK_ScoreFile::getScoresFromFile(int **scores, int *size)
{
    File32 scoreFile = memory.readFile("/pg4501_exam/Donkey_Kong_Game/Donkey_Kong_Scores.txt");

    if (scoreFile)
    {
        if (scoreFile.available())
        {
            scoresAmount = 1;
        }

        while (scoreFile.available())
        {
            char c = scoreFile.read();

            if (c == '\n')
            {
                scoresAmount++;
            }
        }

        *size = scoresAmount;
        *scores = (int *)malloc(sizeof(int) * scoresAmount);

        if (scoresAmount > 0)
        {
            scoreFile.rewind();

            String line = "";
            int i = 0;
            while (scoreFile.available())
            {
                char c = scoreFile.read();

                if (c != '\n')
                {
                    line += c;
                }
                else
                {

                    (*scores)[i] = line.toInt();

                    line = "";
                    i++;
                }
            }

            (*scores)[i] = line.toInt();
        }

        scoreFile.close();
    }
    else
    {
        Serial.println(F("Error opening file!"));
    }
}