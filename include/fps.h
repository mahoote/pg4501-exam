/*
    Inspired code from MakingGamesWithBen on youtube.
    https://www.youtube.com/watch?v=4cwpXJIHaMo&ab_channel=MakingGamesWithBen
*/

#include <Arduino.h>

#ifndef __FPS_H__
#define __FPS_H__

class FPS
{
public:
    void initFPS(int _maxFPS);
    void calculateFPS();
    void limitFPS(float *_startMillis);
    void debugFPS();

private:
    float fps, frameTime, maxFPS;
};

#endif