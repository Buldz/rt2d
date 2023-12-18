// bullet.cpp

#include "bullet.h"

Bullet::Bullet()
	: Entity()
{
	this->addSprite("assets/bullet.tga");
	this->sprite()->color = YELLOW;
	this->scale = Point(0.2f, 0.2f);
	alive = true;
	timer.start();
}

	Bullet::~Bullet(){

}

void Bullet::update(float deltaTime){
	if (timer.seconds() > deleteBulletTime) alive = false;
}

void Bullet::Move(Vector2 vector){
	this->position += vector;
}
