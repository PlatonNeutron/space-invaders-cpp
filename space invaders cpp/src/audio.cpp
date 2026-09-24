#include "Audio.h"

bool InitGameAudio(Audio& audio)
{
    audio.laser = LoadSound("../../assets/laser.wav");
    audio.alienDestroyed = LoadSound("../../assets/alien_destroyed.wav");
    audio.fleetStep = LoadSound("../../assets/fleet_step.wav");
    audio.win = LoadSound("../../assets/win.wav");
    audio.lose = LoadSound("../../assets/lose.wav");

    return true;
}

void UnloadGameAudio(Audio& audio)
{
    UnloadSound(audio.laser);
    UnloadSound(audio.alienDestroyed);
    UnloadSound(audio.fleetStep);
    UnloadSound(audio.win);
    UnloadSound(audio.lose);
}