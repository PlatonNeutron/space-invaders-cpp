#include "subsystems/managers/WorldSubsystemsManager.h"

void WorldSubsystemsManager::AddSubsystem(std::unique_ptr<ISubsystem> subsystem)
{
    subsystems.push_back(std::move(subsystem));
}

void WorldSubsystemsManager::Init()
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Init();
    }
}

void WorldSubsystemsManager::Update(float dt)
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Update(dt);
    }
}

void WorldSubsystemsManager::Shutdown()
{
    for (auto it = subsystems.rbegin(); it != subsystems.rend(); ++it)
    {
        (*it)->Shutdown();
    }
}