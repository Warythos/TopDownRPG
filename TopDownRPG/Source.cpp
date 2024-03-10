#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

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
	Prop rock{ LoadTexture("nature_tileset/Rock.png"), Vector2{0.f,0.f} };

	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);

		mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

		//draw map
		DrawTextureEx(levelMap, mapPos, 0.0, mapScale, WHITE);

		rock.Render(knight.getWorldPos());
		knight.tick(GetFrameTime());
		if (knight.getWorldPos().x < 0.f || knight.getWorldPos().y < 0.f ||
			knight.getWorldPos().x + windowWidth > levelMap.width * mapScale ||
			knight.getWorldPos().y + windowHeight > levelMap.height * mapScale)
		{
			knight.undoMovement();
		}

		EndDrawing();
	}
	CloseWindow();
}