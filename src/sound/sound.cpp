#include "sound/sound.h"

void Sound::playTone(unsigned int frequency, long interval, bool *canPlay, bool *nextCanPlay, unsigned long duration)
{
    static unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();

    if (*canPlay)
    {
        if (currentMillis - previousMillis >= interval)
        {
            previousMillis = currentMillis;
            *canPlay = false;
            *nextCanPlay = true;
            tone(speakerPin, frequency, duration);
        }
    }
}