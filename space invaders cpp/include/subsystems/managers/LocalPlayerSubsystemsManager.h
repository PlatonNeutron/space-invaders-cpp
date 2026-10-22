#pragma once

#include "subsystems/ISubsystem.h"
#include <memory>
#include <vector>

class LocalPlayerSubsystemsManager
{
private:
    std::vector<std::unique_ptr<ISubsystem>> subsystems;

public:
    void AddSubsystem(std::unique_ptr<ISubsystem> subsystem);

    void Init();
    void Update(float dt);
    void Shutdown();
};