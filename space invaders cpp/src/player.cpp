#include "player.h"

void UpdatePlayer(Player& player, float dt)
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
}