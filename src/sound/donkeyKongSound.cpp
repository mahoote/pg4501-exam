#include "sound/donkeyKongSound.h"

void DonkeyKongSound::playBackgroundMusic()
{
    static bool tone1 = true;
    static bool tone2 = false;
    static bool tone3 = false;
    static bool tone4 = false;
    static bool tone5 = false;

    sound.playTone(NOTE_FS3, 150, &tone1, &tone2, 1000 / 8);
    sound.playTone(NOTE_AS3, 500, &tone2, &tone3, 1000 / 8);
    sound.playTone(NOTE_CS4, 350, &tone3, &tone4, 1000 / 8);
    sound.playTone(NOTE_DS4, 150, &tone4, &tone5, 1000 / 8);
    sound.playTone(NOTE_CS4, 150, &tone5, &tone1, 1000 / 8);
}

void DonkeyKongSound::playGameOver()
{
    static bool tone2 = false;
    static bool tone3 = false;
    static bool dummy = false;

    sound.playTone(NOTE_D3, 0, &gameOverStartTone, &tone2, 1000 / 4);
    sound.playTone(NOTE_CS3, 300, &tone2, &tone3, 1000 / 4);
    sound.playTone(NOTE_C3, 300, &tone3, &dummy, 1000 / 1);
}

void DonkeyKongSound::playLoading()
{
    static bool tone2 = false;
    static bool tone3 = false;
    static bool tone4 = false;
    static bool dummy = false;

    sound.playTone(NOTE_D3, 0, &loadingStartTone, &tone2, 1000 / 4);
    sound.playTone(NOTE_D3, 400, &tone2, &tone3, 1000 / 8);
    sound.playTone(NOTE_D3, 200, &tone3, &tone4, 1000 / 8);
    sound.playTone(NOTE_G3, 200, &tone4, &dummy, 1000 / 1);
}

void DonkeyKongSound::playSuperMario()
{
    bool tone2 = false;
    bool tone3 = false;
    bool tone4 = false;
    bool tone5 = false;
    bool tone6 = false;
    bool dummy = false;

    sound.playTone(NOTE_E4, 0, &superMarioStartTone, &tone2, 1000 / 8);
    sound.playTone(NOTE_E4, 150, &tone2, &tone3, 1000 / 8);
    sound.playTone(NOTE_E4, 300, &tone3, &tone4, 1000 / 8);
    sound.playTone(NOTE_C4, 300, &tone4, &tone5, 1000 / 8);
    sound.playTone(NOTE_E4, 150, &tone5, &tone6, 1000 / 8);
    sound.playTone(NOTE_G4, 300, &tone6, &dummy, 1000 / 8);
}

void DonkeyKongSound::resetStartTones()
{
    gameOverStartTone = true;
    loadingStartTone = true;
    superMarioStartTone = true;
}