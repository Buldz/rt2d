/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "myscene.h"

MyScene::MyScene() : Scene()
{
	//Spawns player
	player = new Player();
	player->position = Point2(SWIDTH/2, SHEIGHT/2);

	//Spawns enemy
	enemy = new Enemy(player);
	enemy->position = Point2(60, 60);

	// create the scene 'tree'
	// add player to this Scene as a child.
	this->addChild(player);
	this->addChild(enemy);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(enemy);

	// delete player from the heap (there was a 'new' in the constructor)
	delete player;
	delete enemy;
}

void MyScene::update(float deltaTime)
{
	Movement(deltaTime);
	Shoot();
}

void MyScene::Movement(float deltaTime)
{
	//Gets position of mouse
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
}

void MyScene::Shoot()
{
	//Player shoots and spawns a bullet
	if (input()->getKeyDown(KeyCode::Space)){
		Bullet* bullet = player->Shoot();
		addChild(bullet);
		bullets.push_back(bullet);
	}
		//delete bullet backwards from list
		for (int i = bullets.size() - 1; i >=0; i--) { // backwards
			if (!bullets[i]->isAlive()) {
				removeChild(bullets[i]);
				delete bullets[i]; // delete from the heap first
				bullets.erase(bullets.begin() + i); // then, remove from the list
			}
		}
}
