#pragma once

#include "subsystems/ISubsystem.h"

#include <memory>
#include <vector>

class EngineSubsystemsRegistry
{
public:
    using Factory = std::unique_ptr<ISubsystem>(*)();

    static std::vector<Factory>& GetFactories()
    {
        static std::vector<Factory> factories;
        return factories;
    }

    static bool Register(Factory factory)
    {
        GetFactories().push_back(factory);
        return true;
    }
};

#define REGISTER_ENGINE_SUBSYSTEM(Type)                 \
    namespace                                           \
    {                                                   \
        std::unique_ptr<ISubsystem> Create##Type()      \
        {                                               \
            return std::make_unique<Type>();            \
        }                                               \
                                                        \
        const bool registered##Type =                   \
            EngineSubsystemsRegistry::Register(&Create##Type); \
    }