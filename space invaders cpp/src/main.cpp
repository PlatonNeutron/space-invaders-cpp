#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Space Invaders");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Space Invaders", 300, 280, 30, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}