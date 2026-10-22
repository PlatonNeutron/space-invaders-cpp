#include "subsystems/subsystems/engine/WindowSubsystem.h"
#include "subsystems/subsystems/engine/EngineSubsystemsRegistry.h"

REGISTER_ENGINE_SUBSYSTEM(WindowSubsystem)

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