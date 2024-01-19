/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include "player.h"
#include "bullet.h"
#include "enemy.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();
	std::vector<Bullet*> bullets;


	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	void Movement(float deltaTime);
	void Shoot();
	bool AABB(Entity *rect1, Entity *rect2);

private:
	// Pointers
	Player* player;
	Enemy* enemy;
	Vector2 playerPosition;

	// Variables movement
	int velocity = 0;
	int walk = 300;
	int sprint = 500;
};

#endif /* SCENE00_H */
