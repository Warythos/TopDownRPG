#include "Enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
	worldPos = pos;
	texture = idle_texture;
	idle = idle_texture;
	run = run_texture;
	width = texture.width / maxFrames;
	height = texture.height;
	speed = 2.f;
}

Vector2 Enemy::getScreenPos()
{
	return Vector2Subtract(worldPos, target->getWorldPos());
}

void Enemy::tick(float deltaTime)
{
	velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
	BaseCharacter::tick(deltaTime);
}


