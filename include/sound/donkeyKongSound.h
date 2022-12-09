#include "Arduino.h"
#include "sound/sound.h"

#ifndef __DONKEY_KONG_SOUND_H__
#define __DONKEY_KONG_SOUND_H__

class DonkeyKongSound
{
public:
    void playBackgroundMusic();
    void playGameOver();
    void playLoading();
    void playSuperMario();
    void resetStartTones();

private:
    Sound sound;

    bool gameOverStartTone = false;
    bool loadingStartTone = false;
    bool superMarioStartTone = false;
};

#endif