#include "raylib.h"
#include "player.h"
#include "bullet.h"
#include "alien.h"
#include "hud.h"
#include "audio.h"

int main()
{
    SetTargetFPS(60);

    // Const de la taille de la fenêtre
    constexpr int SCREEN_WIDTH = 800;
    constexpr int SCREEN_HEIGHT = 600;

    // Création de la fenêtre
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Invaders");
    InitAudioDevice();

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

        // GameStates
    enum class GameState
    {
        Playing,
        Won,
        Lost
    };
    GameState gameState = GameState::Playing;

        // Audio
    Audio audio{};
    InitGameAudio(audio);
    

    
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
        UpdatePlayer(player, bullets, dt, audio);
        DrawPlayer(player);

            // Bullets
        UpdateBullets(bullets, dt);
        DrawBullets(bullets);

        CheckBulletAlienCollisions(bullets, aliens, hud, audio);

        // Check condition de victoire
        if (CountAliveAliens(aliens) == 0)
        {
            gameState = GameState::Won;
        }

            // Aliens
        UpdateAliens(aliens, dt, audio);
        DrawAliens(aliens);

        // Check condition de défaite
        for (int i = 0; i < MAX_ALIENS; ++i)
        {
            if (aliens[i].alive)
            {
                if (aliens[i].position.y + aliens[i].size.y >= player.position.y)
                {
                    gameState = GameState::Lost;
                    break;
                }
            } 
        }
        
            // HUD
        DrawHUD(hud);

        // Affichage du message de victoire ou de défaite
        if (gameState == GameState::Won)
        {
            DrawText("VICTOIRE !", 300, 250, 40, GREEN);
            PlaySound(audio.win);
        }
        else if (gameState == GameState::Lost)
        {
            DrawText("DEFAITE !", 300, 250, 40, RED);
            PlaySound(audio.lose);
        }

        // fin de la boucle de dessin
        EndDrawing();
    }

    UnloadGameAudio(audio);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}