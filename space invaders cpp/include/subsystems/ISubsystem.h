#pragma once

class ISubsystem
{
public:
    virtual ~ISubsystem() = default;

    virtual void Init() = 0;
    virtual void Update(float dt) = 0;
    virtual void Shutdown() = 0;
};