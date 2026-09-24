#pragma once

#include "raylib.h"
#include "bullet.h"
#include "hud.h"
#include "audio.h"

struct Alien
{
    Vector2 position;
    Vector2 size;
    bool alive;
};

constexpr int ALIEN_ROWS = 5;
constexpr int ALIEN_COLS = 11;
constexpr int MAX_ALIENS = ALIEN_ROWS * ALIEN_COLS;

void UpdateAliens(Alien aliens[], float dt, Audio& audio);
void DrawAliens(const Alien aliens[]);

int CountAliveAliens(const Alien aliens[]);
void CheckBulletAlienCollisions(Bullet bullets[], Alien aliens[], HUD& hud, Audio& audio);