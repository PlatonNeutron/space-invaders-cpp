#include "subsystems/managers/EngineSubsystemsManager.h"
#include "subsystems/subsystems/engine/EngineSubsystemsRegistry.h"

#include <algorithm>
#include <stdexcept>
#include <typeindex>
#include <vector>

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

        if (subsystem->ShouldCreateSubsystem(this))
        {
            AddSubsystem(std::move(subsystem));
        }
    }

    // Initialisation des sous-systèmes
    // Récupération de l'ordre d'initialisation
    auto& initialized = initializationOrder;

    while (initialized.size() < subsystems.size())
    {
        bool progress = false;

        // Parcours de tous les sous-systèmes pour vérifier leurs dépendances
        for (auto& subsystem : subsystems)
        {
            ISubsystem* current = subsystem.get();

            // Ignorer un sous-système déjà initialisé
            if (std::find(initialized.begin(), initialized.end(), current) != initialized.end())
            {
                continue;
            }

            // Vérification des dépendances du sous-système actuel
            bool dependenciesReady = true;

            for (const auto& dependency : current->GetDependencies())
            {
                bool found = false;

                for (ISubsystem* ready : initialized)
                {
                    if (std::type_index(typeid(*ready)) == dependency)
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    dependenciesReady = false;
                    break;
                }
            }

            // Si toutes les dépendances sont prêtes, initialiser le sous-système
            if (dependenciesReady)
            {
                current->Init();
                initialized.push_back(current);
                progress = true;
            }
        }

        if (!progress)
        {
            // ereur : il y a une dépendance circulaire ou un sous-système manquant
        }
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
    for (auto it = initializationOrder.rbegin(); it != initializationOrder.rend(); ++it)
    {
        (*it)->Shutdown();
    }
}