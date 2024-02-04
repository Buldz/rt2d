// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>
#include "bullet.h"

class Player: public Entity
{
public:
	Player();
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	Bullet* Shoot();
	void Move(Vector2 vector);
	void Health(float damage);\

	bool PlayerIsAlive() { return alive; }

private:
	/* add your private declarations */
	float health;
	bool alive;
};

#endif /* PLAYER_H */
