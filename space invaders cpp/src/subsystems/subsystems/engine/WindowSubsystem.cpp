#include "subsystems/subsystems/engine/WindowSubsystem.h"

void WindowSubsystem::Init()
{
    InitWindow(800, 600, "Space Invaders");
    SetTargetFPS(60);
}

void WindowSubsystem::Update(float dt)
{
    // Rien à faire pour le moment.
    (void)dt;
}

void WindowSubsystem::Shutdown()
{
    CloseWindow();
}