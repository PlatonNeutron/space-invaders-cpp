#pragma once

#include <typeindex>
#include <vector>

class ISubsystem
{
public:
    virtual ~ISubsystem() = default;

    virtual bool ShouldCreateSubsystem(const void* outer) const
    {
        return true;
    }

    virtual std::vector<std::type_index> GetDependencies() const
    {
        return {};
    }

    virtual void Init() = 0;
    virtual void Update(float dt) = 0;
    virtual void Shutdown() = 0;
};