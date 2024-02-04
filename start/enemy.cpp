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
	this->position = Point2(-100, -100);

	alive = true;
	health = 25;

	RandomSpawn();
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

void Enemy::Health(int damage){
	health -= damage;
	if (health <= 0) alive = false; 
}

void Enemy::RandomSpawn()
{
	switch (rand() % 3)
        {
        case 0:
            this->position = Vector2(rand() % SWIDTH, SHEIGHT + 10);
            break;
        case 1:
            this->position = Vector2(rand() % SWIDTH, -10);
            break;
        case 2:
            this->position = Vector2(SWIDTH + 10, rand() % SHEIGHT);
            break;
        case 3:
            this->position = Vector2(-10, rand() % SHEIGHT);
            break;
		}
}