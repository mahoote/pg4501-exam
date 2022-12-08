#include "donkeyKong/score/dkScoreFile.h"

String filePath = "/Donkey_Kong_Game/";
String filename = "Donkey_Kong_Scores.txt";

String DK_ScoreFile::getFilePath()
{
    return *memory.getSdSpriteGamePath() + filePath + filename;
}

void DK_ScoreFile::initFile()
{
    bool fileExists = memory.fileExists(getFilePath());

    Serial.print("File exists: ");
    Serial.println(fileExists);

    if (fileExists)
    {
        int *scores;
        int scoreAmount;

        getScoresFromFile(&scores, &scoreAmount);

        if (scoreAmount < 5)
        {
            int n = 5 - scoreAmount;
            for (int i = 0; i < n; i++)
            {
                saveScoreToFile(0);
            }
        }
    }
    else
    {
        File32 newFile = memory.writeFile(getFilePath());
        if (newFile)
        {
            Serial.println(F("Created new score saves file!"));

            newFile.println(0);
            newFile.println(0);
            newFile.println(0);
            newFile.println(0);
            newFile.print(0);

            newFile.close();
        }
        else
        {
            Serial.println(F("Error opening new file!"));
        }
    }
}

void DK_ScoreFile::saveScoreToFile(int _score)
{
    File32 scoreFile = memory.writeFile(getFilePath());

    if (scoreFile)
    {
        scoreFile.print("\n");
        scoreFile.print(_score);
        scoreFile.close();
    }
    else
    {
        Serial.println(F("Error opening file!"));
    }
}

void DK_ScoreFile::getScoresFromFile(int **scores, int *size)
{
    File32 scoreFile = memory.readFile(getFilePath());

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