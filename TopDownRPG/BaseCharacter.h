#include "raylib.h"
#include "raymath.h"
#pragma once
class BaseCharacter
{
public:
	BaseCharacter();
	Vector2 getWorldPos() { return worldPos; }
	void undoMovement();
	Rectangle getCollisionRect();
	virtual void tick(float deltaTime);
	virtual Vector2 getScreenPos() = 0;
protected:
	Texture2D texture{ LoadTexture("Characters/knight_idle_spritesheet.png") };
	Texture2D idle{ LoadTexture("Characters/knight_idle_spritesheet.png") };
	Texture2D run{ LoadTexture("Characters/knight_run_spritesheet.png") };
	Vector2 worldPos{};
	Vector2 worldPosLastFrame{ };
	Vector2 velocity{};
	// 1 : facing right, -1 : facing left
	float rightLeft{ 1.f };
	//animation variables
	float runningTime{};
	int frame{};
	int maxFrames{ 6 };
	float updateTime{ 1.f / 12.f };
	float speed{ 4.f };
	float width{ };
	float height{ };
	float scale{ 4.0f };
private:
};

