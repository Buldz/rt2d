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

private:
	/* add your private declarations */
	float enemySpeed = 75.0f;

	Player* player;
};

#endif /* ENEMY_H */
