/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include "player.h"
#include "myscene.h"
#include "bullet.h"

int velocity = 0;
int walk = 300;
int sprint = 500;


MyScene::MyScene() : Scene()
{
	// create a single instance of player in the middle of the screen.
	// the Sprite is added in Constructor of player.
	player = new Player();
	player->position = Point2(SWIDTH/2, SHEIGHT/2);
	player->scale = Point(0.3f, 0.3f);

	bullet = new Bullet();
	bullet->position = Point2(SWIDTH/2, SHEIGHT/2);
	bullet->scale = Point(0.2f, 0.2f);

	velocity = walk;

	// create the scene 'tree'
	// add player to this Scene as a child.
	this->addChild(player);
	this->addChild(bullet);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);

	// delete player from the heap (there was a 'new' in the constructor)
	delete player;
}

void MyScene::update(float deltaTime)
{
	float mx = input()->getMouseX();
	float my = input()->getMouseY();
	Vector2 mouseLocation = Vector2(mx, my) - player->position;
	
	
	// CONTROLS
	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	// W / Up key lets player go up
	if (input()->getKey(KeyCode::W) || input()->getKey(KeyCode::Up)) {
		player->Move(Vector2(0, -velocity) * deltaTime);
	}

	// S / Down key lets player go down
	if (input()->getKey(KeyCode::S) || input()->getKey(KeyCode::Down)) {
		player->Move(Vector2(0, velocity) * deltaTime);
	}

	// A / Left key lets player go left
	if (input()->getKey(KeyCode::A) || input()->getKey(KeyCode::Left)) {
		player->Move(Vector2(-velocity, 0) * deltaTime);
	}

	// D / Right key lets player go right
	if (input()->getKey(KeyCode::D) || input()->getKey(KeyCode::Right)) {
		player->Move(Vector2(velocity, 0) * deltaTime);
	}

	// Shift key  lets player sprint
	if (input()->getKey(KeyCode::LeftShift)){
		velocity = sprint;
	}
	else{
		velocity = walk;
	}

	//Player looks at mouse
	player->rotation.z = mouseLocation.getAngle();

	//Player shoots
	if (input()->getKey(KeyCode::Space)){
		player->Shoot();
	}
}
