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
	// Spawns player
	player = new Player();
	player->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	// Spawns enemy
	// enemy = new Enemy(player);
	// addChild(enemy);
	// enemys.push_back(enemy);

	// Create timer
	timer = new Timer();

	timer->start();
	// create the scene 'tree'
	// add player to this Scene as a child.
	this->addChild(player);
}

MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);

	// delete player from the heap (there was a 'new' in the constructor)
	delete player;
	delete timer;
}

void MyScene::update(float deltaTime)
{
	Movement(deltaTime);
	Shoot();
	PlayerDamage(deltaTime);
	SpawnManager();

	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}
}

void MyScene::Movement(float deltaTime)
{
	// Gets position of mouse
	float mx = input()->getMouseX();
	float my = input()->getMouseY();
	Vector2 mouseLocation = Vector2(mx, my) - player->position;

	// Player looks at mouse
	player->rotation.z = mouseLocation.getAngle();

	// CONTROLS
	// W / Up key lets player go up
	if (input()->getKey(KeyCode::W) || input()->getKey(KeyCode::Up))
	{
		player->Move(Vector2(0, -velocity) * deltaTime);
	}

	// S / Down key lets player go down
	if (input()->getKey(KeyCode::S) || input()->getKey(KeyCode::Down))
	{
		player->Move(Vector2(0, velocity) * deltaTime);
	}

	// A / Left key lets player go left
	if (input()->getKey(KeyCode::A) || input()->getKey(KeyCode::Left))
	{
		player->Move(Vector2(-velocity, 0) * deltaTime);
	}

	// D / Right key lets player go right
	if (input()->getKey(KeyCode::D) || input()->getKey(KeyCode::Right))
	{
		player->Move(Vector2(velocity, 0) * deltaTime);
	}

	// Shift key  lets player sprint
	if (input()->getKey(KeyCode::LeftShift))
	{
		velocity = sprint;
	}
	else
	{
		velocity = walk;
	}
}

void MyScene::Shoot()
{
	// Player shoots and spawns a bullet
	if (input()->getKeyDown(KeyCode::Space))
	{
		Bullet *bullet = player->Shoot();
		addChild(bullet);
		bullets.push_back(bullet);
	}

	// delete bullet backwards from list
	for (int i = bullets.size() - 1; i >= 0; i--)
	{
		if (!bullets[i]->BulletIsAlive())
		{
			removeChild(bullets[i]);
			delete bullets[i];					// delete from the heap first
			bullets.erase(bullets.begin() + i); // then, remove from the list
		}

		// Iterate over enemies
		for (int j = enemys.size() - 1; j >= 0; j--)
		{
			if (RectCollision(bullets[i], enemys[j]))
			{
				// Damage or delete the enemy
				enemys[j]->Health(5);
				if (!enemys[j]->EnemyIsAlive())
				{
					removeChild(enemys[j]);
					delete enemys[j];				  // delete from the heap first
					enemys.erase(enemys.begin() + j); // then, remove from the list
				}


				if (bullets[i] == nullptr) return;

				// deletes bullet on collision with enemy
				removeChild(bullets[i]);
				delete bullets[i];					// delete from the heap first
				bullets.erase(bullets.begin() + i); // then, remove from the list
				bullets[i] = nullptr;
			}
		}
	}
}


void MyScene::PlayerDamage(float deltaTime)
{
	if (player == nullptr) return;

	// Iterate over enemies
	for (int i = enemys.size() - 1; i >= 0; i--)
	{
		// deletes player if player !PlayerIsAlive
		if (RectCollision(enemys[i], player))
		{
			player->Health(5 * deltaTime);
			if (!player->PlayerIsAlive())
			{
				removeChild(player);
				delete player;
				player = nullptr;
			}
		}
	}
}

void MyScene::SpawnManager()
{
	if (timer->seconds() >= spawnRate)
	{
		timer->start();

		Enemy *enemy;
		enemy = new Enemy(player);
		addChild(enemy);
		enemys.push_back(enemy);
	}
}

bool MyScene::RectCollision(Entity *rect1, Entity *rect2)
{
	return (rect1->position.x < rect2->position.x + rect2->sprite()->size.x * rect2->scale.x &&
			rect1->position.x + rect1->sprite()->size.x * rect1->scale.x > rect2->position.x &&
			rect1->position.y < rect2->position.y + rect2->sprite()->size.y * rect2->scale.y &&
			rect1->position.y + rect1->sprite()->size.y * rect1->scale.y > rect2->position.y);
}