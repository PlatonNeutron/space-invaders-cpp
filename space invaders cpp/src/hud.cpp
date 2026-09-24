#include "hud.h"

void DrawHUD(HUD& hud){
    DrawText(TextFormat("Score: %d", hud.score), 20, 20, 15, WHITE);
    DrawText(TextFormat("Aliens Alive: %d", hud.aliensAlives), 675, 20, 15, WHITE);
}