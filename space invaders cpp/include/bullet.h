#pragma once

#include "raylib.h"

struct Bullet
{
    Vector2 position;
    Vector2 size;
    float speed;
    bool active;
};

constexpr int MAX_BULLETS = 10;

void UpdateBullets(Bullet bullets[], float dt);
void DrawBullets(const Bullet bullets[]);