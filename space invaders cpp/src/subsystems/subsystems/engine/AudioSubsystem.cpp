#include "subsystems/subsystems/engine/AudioSubsystem.h"
#include "subsystems/subsystems/engine/EngineSubsystemsRegistry.h"

REGISTER_ENGINE_SUBSYSTEM(AudioSubsystem)

void AudioSubsystem::Init()
{
    InitAudioDevice();

    laser = LoadSound("../../assets/laser.wav");
    alienDestroyed = LoadSound("../../assets/alien_destroyed.wav");
    fleetStep = LoadSound("../../assets/fleet_step.wav");
    win = LoadSound("../../assets/win.wav");
    lose = LoadSound("../../assets/lose.wav");
}

void AudioSubsystem::Update(float dt)
{
    // Rien à faire pour le moment.
    (void)dt;
}

void AudioSubsystem::Shutdown()
{
    UnloadSound(laser);
    UnloadSound(alienDestroyed);
    UnloadSound(fleetStep);
    UnloadSound(win);
    UnloadSound(lose);

    CloseAudioDevice();
}

void AudioSubsystem::PlayLaser()
{
    PlaySound(laser);
}

void AudioSubsystem::PlayAlienDestroyed()
{
    PlaySound(alienDestroyed);
}

void AudioSubsystem::PlayFleetStep()
{
    PlaySound(fleetStep);
}

void AudioSubsystem::PlayWin()
{
    PlaySound(win);
}

void AudioSubsystem::PlayLose()
{
    PlaySound(lose);
}