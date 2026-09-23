#include "raylib.h"
#include "player.h"
#include "bullet.h"

// Const de la taille de la fenêtre
constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

int main()
{
    // Création de la fenêtre
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders");

    // Création des assets
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

    // Boucle de jeu
    while (!WindowShouldClose())
    {
        // Delta Time
        float dt = GetFrameTime();

        // début de la boucle de dessin
        BeginDrawing();
        ClearBackground(BLACK);

        // Update du jeu
        DrawText("Space Invaders", 300, 280, 30, WHITE);

            // Joueur
        UpdatePlayer(player, bullets, dt);
        DrawPlayer(player);

            // Bullets
        UpdateBullets(bullets, dt);
        DrawBullets(bullets);

        // fin de la boucle de dessin
        EndDrawing();
    }

    CloseWindow();
    return 0;
}