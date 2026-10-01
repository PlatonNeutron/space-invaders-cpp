#include "../../include/subsystems/EngineSubsystemManager.h"

void EngineSubsystemManager::AddSubsystem(std::unique_ptr<ISubsystem> subsystem)
{
    subsystems.push_back(std::move(subsystem));
}

void EngineSubsystemManager::Init()
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Init();
    }
}

void EngineSubsystemManager::Update(float dt)
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Update(dt);
    }
}

void EngineSubsystemManager::Shutdown()
{
    for (auto& subsystem : subsystems)
    {
        subsystem->Shutdown();
    }
}