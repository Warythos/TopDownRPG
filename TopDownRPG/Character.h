#include "raylib.h"
#include "raymath.h"
#include "BaseCharacter.h"
#pragma once

class Character : public BaseCharacter
{
public:
	Character(int winWidth, int winHeight);
	virtual void tick(float deltaTime) override;
	virtual Vector2 getScreenPos() override;
private:
	int windowWidth{};
	int windowHeight{};
};