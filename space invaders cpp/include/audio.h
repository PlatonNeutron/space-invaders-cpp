#pragma once

#include "raylib.h"

struct Audio
{
    Sound laser;
    Sound alienDestroyed;
    Sound fleetStep;
    Sound win;
    Sound lose;
};

bool InitGameAudio(Audio& audio);
void UnloadGameAudio(Audio& audio);