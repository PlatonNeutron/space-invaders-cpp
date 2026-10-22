#include "subsystems/managers/EngineSubsystemsManager.h"
#include "subsystems/subsystems/engine/EngineSubsystemsRegistry.h"

void EngineSubsystemsManager::AddSubsystem(std::unique_ptr<ISubsystem> subsystem)
{
    subsystems.push_back(std::move(subsystem));
}

void EngineSubsystemsManager::Init()
{
    // Création automatique des sous-systèmes via les factories enregistrés
    for (auto factory : EngineSubsystemsRegistry::GetFactories())
    {
        std::unique_ptr<ISubsystem> subsystem = factory();

        AddSubsystem(std::move(subsystem));
    }

    // Initialisation des sous-systèmes
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
    for (auto it = subsystems.rbegin(); it != subsystems.rend(); ++it)
    {
        (*it)->Shutdown();
    }
}