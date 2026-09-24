#include "raylib.h"
#include "player.h"
#include "bullet.h"
#include "alien.h"
#include "hud.h"

int main()
{
    SetTargetFPS(60);

    // Const de la taille de la fenêtre
    constexpr int SCREEN_WIDTH = 800;
    constexpr int SCREEN_HEIGHT = 600;

    // Création de la fenêtre
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders");

    // Initialisation des assets
        // Joueur
    Player player{
        {SCREEN_WIDTH / 2.0f - 25.0f, SCREEN_HEIGHT - 60.0f},
        {50.0f, 20.0f},
        300.0f,
        0.0f
    };

        // Bullets
    Bullet bullets[MAX_BULLETS] = {};
    for (int i = 0; i < MAX_BULLETS; ++i)
    {
        bullets[i].size = {5.0f, 15.0f};
        bullets[i].speed = 500.0f;
    }

        // Aliens
    Alien aliens[MAX_ALIENS] = {};

    for (int row = 0; row < ALIEN_ROWS; ++row)
    {
        for (int col = 0; col < ALIEN_COLS; ++col)
        {
            int index = row * ALIEN_COLS + col;

            aliens[index].position = {
                125.0f + col * 50.0f,
                50.0f + row * 35.0f
            };

            aliens[index].size = {30.0f, 20.0f};
            aliens[index].alive = true;
        }
    }

        // HUD
    HUD hud{
        0,
        MAX_ALIENS
    };


    // Boucle de jeu
    while (!WindowShouldClose())
    {
        // Delta Time
        float dt = GetFrameTime();

        // début de la boucle de dessin
        BeginDrawing();
        ClearBackground(BLACK);

        // Update du jeu
            // Joueur
        UpdatePlayer(player, bullets, dt, hud);
        DrawPlayer(player);

            // Bullets
        UpdateBullets(bullets, dt);
        DrawBullets(bullets);

        CheckBulletAlienCollisions(bullets, aliens, hud);

            // Aliens
        UpdateAliens(aliens, dt);
        DrawAliens(aliens);
        
            // HUD
        DrawHUD(hud);

        // fin de la boucle de dessin
        EndDrawing();
    }

    CloseWindow();
    return 0;
}