#include "Arduino.h"
#include "sound/pitches.h"

#ifndef __SOUND_H__
#define __SOUND_H__

class Sound
{
public:
    void playTone(unsigned int frequency, long interval, bool *canPlay, bool *nextCanPlay, unsigned long duration = 0);

private:
    int speakerPin = 6;
};

#endif