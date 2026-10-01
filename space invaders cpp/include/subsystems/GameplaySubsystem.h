#pragma once

#include "ISubsystem.h"
#include "raylib.h"
#include "../Player.h"
#include "../Bullet.h"
#include "../Alien.h"

class GameplaySubsystem : public ISubsystem
{
private:
    Player player;
    Bullet bullets;
    Alien aliens;

public:
    void Init() override;
    void Update(float dt) override;
    void Shutdown() override;
};