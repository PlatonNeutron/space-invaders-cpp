#include "player.h"
#include "audio.h"

void UpdatePlayer(Player& player, Bullet bullets[], float dt, Audio& audio)
{
    // Déplacement du joueur
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        player.position.x -= player.speed * dt;
    }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        player.position.x += player.speed * dt;
    }

    // Limitation du joueur à l'intérieur de la fenêtre
    if (player.position.x < 0.0f)
    {
        player.position.x = 0.0f;
    }

    if (player.position.x > 800.0f - player.size.x)
    {
        player.position.x = 800.0f - player.size.x;
    }

    // Gestion du cooldown de tir
    if (player.fireCooldown > 0.0f)
    {
        player.fireCooldown -= dt;
    }

    // Tir du joueur
    if (IsKeyPressed(KEY_SPACE) && player.fireCooldown <= 0.0f)
    {
        // Trouver un bullet inactif
        for (int i = 0; i < MAX_BULLETS; ++i)
        {
            if (!bullets[i].active)
            {
                bullets[i].position = { player.position.x + player.size.x / 2.0f - bullets[i].size.x / 2.0f, player.position.y };
                bullets[i].active = true;
                PlaySound(audio.laser);
                player.fireCooldown = 0.5f; // Cooldown de tir de 0.5 secondes
                break;
            }
        }
    }
}

void DrawPlayer(Player& player){
    DrawRectangle(
        static_cast<int>(player.position.x),
        static_cast<int>(player.position.y),
        static_cast<int>(player.size.x),
        static_cast<int>(player.size.y),
        WHITE
    );
}