#include "subsystems/managers/LocalPlayerSubsystemsManager.h"

void LocalPlayerSubsystemsManager::AddSubsystem(std::unique_ptr<ISubsystem> subsystem)
{
    subsystems.push_back(std::move(subsystem));
}

void LocalPlayerSubsystemsManager::Init()
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Init();
    }
}

void LocalPlayerSubsystemsManager::Update(float dt)
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Update(dt);
    }
}

void LocalPlayerSubsystemsManager::Shutdown()
{
    for (auto it = subsystems.rbegin(); it != subsystems.rend(); ++it)
    {
        (*it)->Shutdown();
    }
}