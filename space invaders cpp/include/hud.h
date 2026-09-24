#pragma once

#include "raylib.h"
#include <string>

struct HUD
{
    int score;
    int aliensAlives;
};

void DrawHUD(HUD& hud);