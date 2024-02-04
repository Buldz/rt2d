// bullet.cpp

#include "bullet.h"

Bullet::Bullet()
	: Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = YELLOW;
	this->scale = Point(0.25f, 0.125f);
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
