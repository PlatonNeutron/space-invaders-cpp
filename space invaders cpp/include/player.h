#pragma once

#include "raylib.h"
#include "bullet.h"

struct Player
{
    Vector2 position;
    Vector2 size;
    float speed;
    float fireCooldown;
};

void UpdatePlayer(Player& player, Bullet bullets[], float dt);
void DrawPlayer(Player& player);