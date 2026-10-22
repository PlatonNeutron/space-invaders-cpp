#pragma once

#include "ISubsystem.h"
#include "raylib.h"

class WindowSubsystem : public ISubsystem
{
public:
    void Init() override;
    void Update(float dt) override;
    void Shutdown() override;
};