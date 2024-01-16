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
	MoveForward();
}

void Bullet::MoveForward(){
	double newX = this->position.x + cos(this->rotation.z) * bulletSpeed;
  	double newY = this->position.y + sin(this->rotation.z) * bulletSpeed;

	this->position.x = newX;
	this->position.y = newY;
}
