// Player.cpp

#include "player.h"

Player::Player(): Entity()
{
	this->addSprite("assets/square.tga");
	this->sprite()->color = GREEN;
}

Player::~Player()
{

}

void Player::Move(Vector2 vector){
	this->position += vector;
}

void Player::Shoot(){
	
}

void Player::update(float deltaTime)
{

}