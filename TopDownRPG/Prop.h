#include "raylib.h"
#include "raymath.h"
#pragma once
class Prop
{
public:
	Prop(Texture2D tex, Vector2 pos);
	void Render(Vector2 playerPos);
private:
	Texture2D texture{};
	Vector2 worldPos{};
	float scale{ 4.f };
};

