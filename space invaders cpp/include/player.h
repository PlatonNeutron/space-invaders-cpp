#pragma once

#include "raylib.h"
#include "bullet.h"
#include "audio.h"

struct Player
{
    Vector2 position;
    Vector2 size;
    float speed;
    float fireCooldown;
};

void UpdatePlayer(Player& player, Bullet bullets[], float dt, Audio& audio);
void DrawPlayer(Player& player);