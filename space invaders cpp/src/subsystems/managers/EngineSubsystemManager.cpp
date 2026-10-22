#include "subsystems/managers/EngineSubsystemsManager.h"

void EngineSubsystemsManager::AddSubsystem(std::unique_ptr<ISubsystem> subsystem)
{
    subsystems.push_back(std::move(subsystem));
}

void EngineSubsystemsManager::Init()
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Init();
    }
}

void EngineSubsystemsManager::Update(float dt)
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Update(dt);
    }
}

void EngineSubsystemsManager::Shutdown()
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Shutdown();
    }
}