// enemy.h

#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/entity.h>
#include "player.h"

class Enemy: public Entity
{
public: 
	Enemy(Player* player);
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void MoveToTarget(float deltaTime);
	void Health(int damage);
	void RandomSpawn();
	bool EnemyIsAlive() { return alive; }

private:
	/* add your private declarations */
	float enemySpeed = 75.0f;
	bool alive;
	int health;

	Player* player;
};

#endif /* ENEMY_H */
