#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"


int main()
{
	int windowWidth{ 500 };
	int windowHeight{ 500 };
	InitWindow(windowWidth, windowHeight, "Topdown Game");

	Texture2D levelMap = LoadTexture("TileMap/WorldMap.png");
	Vector2 mapPos{ 0.0,0.0 };
	float speed{ 4.0 };
	const float mapScale{ 2.0 };

	Character knight(windowWidth, windowHeight);
	Enemy goblin{ 
		Vector2{0.f, 0.f}, 
		LoadTexture("Characters/goblin_idle_spritesheet.png"),
		LoadTexture("Characters/goblin_run_spritesheet.png")
	};
	goblin.setTarget(&knight);

	Prop props[2]{
		Prop{ LoadTexture("nature_tileset/Rock.png"), Vector2{600.f,300.f} },
		Prop{ LoadTexture("nature_tileset/Log.png"), Vector2{400.f,500.f} }
	};

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		mapPos = Vector2Scale(knight.getWorldPos(), -1.f);
		//draw map
		DrawTextureEx(levelMap, mapPos, 0.0, mapScale, WHITE);

		for (auto prop : props)
		{
			prop.Render(knight.getWorldPos());
		}

		knight.tick(GetFrameTime());

		//check map bounds
		if (knight.getWorldPos().x < 0.f || knight.getWorldPos().y < 0.f ||
			knight.getWorldPos().x + windowWidth > levelMap.width * mapScale ||
			knight.getWorldPos().y + windowHeight > levelMap.height * mapScale)
		{
			knight.undoMovement();
		}
		//prop collisions
		for (auto prop : props)
		{
			if (CheckCollisionRecs(prop.getCollisionRect(knight.getWorldPos()), knight.getCollisionRect())) knight.undoMovement();
		}
		goblin.tick(GetFrameTime());
		EndDrawing();
	}
	CloseWindow();
}