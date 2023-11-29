// bullet.cpp

#include "bullet.h"

Bullet::Bullet()
	: Entity()
{
	this->addSprite("assets/bullet.tga");
	this->sprite()->color = YELLOW;
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{

}
