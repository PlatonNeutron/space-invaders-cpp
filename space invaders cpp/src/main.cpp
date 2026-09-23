#include "raylib.h"
#include "Player.h"

// Const de la taille de la fenêtre
constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;

int main()
{
    // Création de la fenêtre
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders");

    // Création du joueur
    Player player{
        {SCREEN_WIDTH / 2.0f - 25.0f, SCREEN_HEIGHT - 60.0f},
        {50.0f, 20.0f},
        300.0f
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
        DrawText("Space Invaders", 300, 280, 30, WHITE);

        // Update du joueur
        UpdatePlayer(player, dt);
        DrawRectangle(
            static_cast<int>(player.position.x),
            static_cast<int>(player.position.y),
            static_cast<int>(player.size.x),
            static_cast<int>(player.size.y),
            WHITE
        );

        // fin de la boucle de dessin
        EndDrawing();
    }

    CloseWindow();
    return 0;
}