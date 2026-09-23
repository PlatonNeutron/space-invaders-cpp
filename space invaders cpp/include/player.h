#pragma once

#include "raylib.h"

struct Player
{
    Vector2 position;
    Vector2 size;
    float speed;
};

void UpdatePlayer(Player& player, float dt);