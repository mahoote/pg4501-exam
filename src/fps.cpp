#include "fps.h"

void FPS::initFPS(int _maxFPS)
{
    maxFPS = _maxFPS;
}

void FPS::calculateFPS()
{
    static const int NUM_SAMPLES = 10;
    static float frameTimes[NUM_SAMPLES];
    static int currentFrame = 0;

    static float prevTicks = millis();
    float currentTicks;

    currentTicks = millis();

    frameTime = currentTicks - prevTicks;
    frameTimes[currentFrame % NUM_SAMPLES] = frameTime;

    prevTicks = currentTicks;

    int count;

    currentFrame++;

    if (currentFrame < NUM_SAMPLES)
    {
        count = currentFrame;
    }
    else
    {
        count = NUM_SAMPLES;
    }

    float frameTimeAvg = 0;
    for (int i = 0; i < count; i++)
    {
        frameTimeAvg += frameTimes[i];
    }

    frameTimeAvg /= count;

    if (frameTimeAvg > 0)
    {
        fps = 1000.0f / frameTimeAvg;
    }
    else
    {
        fps = 60.0f;
    }
}

void FPS::limitFPS(float *_startMillis)
{
    float frameMillis = millis() - *_startMillis;

    float millisPerFrame = 1000.0f / maxFPS;

    if (millisPerFrame > frameMillis)
    {
        delay(millisPerFrame - frameMillis);
    }
}

void FPS::debugFPS()
{
    static int frameCounter = 0;
    frameCounter++;

    if (frameCounter == 10)
    {
        Serial.print(F("FPS: "));
        Serial.println(fps);
        frameCounter = 0;
    }
}