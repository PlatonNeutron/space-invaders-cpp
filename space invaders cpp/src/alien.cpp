#include "alien.h"

namespace
{
    float fleetStepTimer = 0.0f;
    float fleetDirection = 1.0f;
}

int CountAliveAliens(const Alien aliens[])
{
    int count = 0;

    for (int i = 0; i < MAX_ALIENS; ++i)
    {
        if (aliens[i].alive)
        {
            ++count;
        }
    }

    return count;
}

void UpdateAliens(Alien aliens[], float dt)
{
    fleetStepTimer -= dt;

    if (fleetStepTimer <= 0.0f)
    {
        int aliveAliens = CountAliveAliens(aliens);
        float interval = 0.05f + 0.45f * (static_cast<float>(aliveAliens) / MAX_ALIENS);
        fleetStepTimer = interval;

        bool hitEdge = false;

        // Check si le flotte d'aliens touche le bord de l'écran
        for (int i = 0; i < MAX_ALIENS; ++i)
        {
            if (aliens[i].alive)
            {
                float nextMove = aliens[i].position.x + fleetDirection * 10.0f;

                if (nextMove < 0.0f || nextMove + aliens[i].size.x > 800.0f)
                {
                    hitEdge = true;
                    fleetDirection *= -1.0f;
                }
            }
        }

        // Descend la flotte si le bord est touché
        if (hitEdge)
        {
            for (int i = 0; i < MAX_ALIENS; ++i)
            {
                aliens[i].position.y += 18.0f;
            }
        }
        else{
            // Déplacement de la flotte
            for (int i = 0; i < MAX_ALIENS; ++i)
            {
                aliens[i].position.x += fleetDirection * 10.0f;
            }
        }
    }
}

void DrawAliens(const Alien aliens[])
{
    for (int row = 0; row < ALIEN_ROWS; ++row)
    {
        for (int col = 0; col < ALIEN_COLS; ++col)
        {
            int index = row * ALIEN_COLS + col;

            if (aliens[index].alive)
            {
                Color color;
                
                switch(row) {
                case 0:
                    color = RED;
                    break;
                case 1:
                    color = BLUE;
                    break;
                case 2:
                    color = YELLOW;
                    break;
                case 3:
                    color = GREEN;
                    break;
                default:
                    color = ORANGE;
                }

                DrawRectangle(
                    static_cast<int>(aliens[index].position.x),
                    static_cast<int>(aliens[index].position.y),
                    static_cast<int>(aliens[index].size.x),
                    static_cast<int>(aliens[index].size.y),
                    color
                );
            }
        }
    }
}

void CheckBulletAlienCollisions(Bullet bullets[], Alien aliens[], HUD& hud){
    for (int i = 0; i < MAX_BULLETS; ++i)
    {
        if (bullets[i].active)
        {
            Rectangle bulletRect = {
                bullets[i].position.x,
                bullets[i].position.y,
                bullets[i].size.x,
                bullets[i].size.y
            };

            for (int j = 0; j < MAX_ALIENS; ++j)
            {
                if (aliens[j].alive)
                {
                    Rectangle alienRect = {
                        aliens[j].position.x,
                        aliens[j].position.y,
                        aliens[j].size.x,
                        aliens[j].size.y
                    };

                    if (CheckCollisionRecs(bulletRect, alienRect))
                    {
                        bullets[i].active = false;
                        aliens[j].alive = false;

                        hud.score += 10;
                        hud.aliensAlives -= 1;

                        break;
                    }
                }
            }
        }   
    }
}