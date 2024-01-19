// Player.cpp

#include "player.h"
#include "bullet.h"
#include "myscene.h"

Player::Player(): Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = GREEN;
	this->scale = Point(0.3f, 0.3f);
}

Player::~Player(){

}

void Player::Move(Vector2 vector){
	this->position += vector;
}

Bullet* Player::Shoot(){
	Bullet* bullet = new Bullet();
	bullet->position = this->position;
	bullet->rotation = this->rotation;

	return bullet;
}

void Player::update(float deltaTime)
{

}