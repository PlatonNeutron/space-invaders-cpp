#pragma once

#include "subsystems/ISubsystem.h"
#include "subsystems/subsystems/engine/WindowSubsystem.h"
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
    std::vector<std::type_index> GetDependencies() const override
    {
        return {typeid(WindowSubsystem)};
    }
    
    void Init() override;
    void Update(float dt) override;
    void Shutdown() override;

    void PlayLaser();
    void PlayAlienDestroyed();
    void PlayFleetStep();
    void PlayWin();
    void PlayLose();
};