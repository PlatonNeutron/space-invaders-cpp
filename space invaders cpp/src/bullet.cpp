#include "Bullet.h"

void UpdateBullets(Bullet bullets[], float dt)
{
    for (int i = 0; i < MAX_BULLETS; ++i)
    {
        if (bullets[i].active)
        {
            // met en mouvement les bullets
            bullets[i].position.y -= bullets[i].speed * dt;

            // désactive les bullets qui sortent de l'écran
            if (bullets[i].position.y + bullets[i].size.y < 0.0f)
            {
                bullets[i].active = false;
            }
        }
    }
}

void DrawBullets(const Bullet bullets[])
{
    for (int i = 0; i < MAX_BULLETS; ++i)
    {
        if (bullets[i].active)
        {
            DrawRectangle(
                static_cast<int>(bullets[i].position.x),
                static_cast<int>(bullets[i].position.y),
                static_cast<int>(bullets[i].size.x),
                static_cast<int>(bullets[i].size.y),
                WHITE
            );
        }
    }
}