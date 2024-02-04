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
#include "rt2d/timer.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();
	std::vector<Bullet*> bullets;
	std::vector<Enemy*> enemys;

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	void Movement(float deltaTime);
	void Shoot();
	void PlayerDamage(float deltaTime);
	void SpawnManager();

	bool RectCollision(Entity *rect1, Entity *rect2);

private:
	// Pointers
	Player* player;
	//Enemy* enemy;
	Timer* timer;
	Vector2 playerPosition;

	// Variables movement
	int velocity = 0;
	int walk = 300;
	int sprint = 500;
	double spawnRate = 0.5;
};

#endif /* SCENE00_H */
