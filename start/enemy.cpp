// enemy.cpp

#include "enemy.h"	
#include "player.h"

Enemy::Enemy(Player* player)
	: Entity()
{
	this->player = player;
	this->addSprite("assets/square.tga");
	this->sprite()->color = RED;
	this->scale = Point(0.5f, 0.5f);
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	MoveToTarget(deltaTime);
}

void Enemy::MoveToTarget(float deltaTime)
{
	Vector2 direction = player->position - this->position;
	direction.normalize();

  	this->position += direction * enemySpeed * deltaTime;
}