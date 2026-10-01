#pragma once

#include "ISubsystem.h"
#include "raylib.h"

class AudioSubsystem : public ISubsystem
{
private:
    Sound laser;
    Sound alienDestroyed;
    Sound fleetStep;
    Sound win;
    Sound lose;

public:
    void Init() override;
    void Update(float dt) override;
    void Shutdown() override;

    void PlayLaser();
    void PlayAlienDestroyed();
    void PlayFleetStep();
    void PlayWin();
    void PlayLose();
};