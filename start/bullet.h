// bullet.h

#ifndef BULLET_H
#define BULLET_H

#include <rt2d/entity.h>
#include <rt2d/timer.h>

class Bullet: public Entity
{
public:
	Bullet();
	virtual ~Bullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	bool isAlive() { return alive; }
	Timer timer;
private:
	// 

	/* add your private declarations */
	void Move(Vector2 vector);

	// Variable movement
	int velocity = 700;

	float deleteBulletTime = 10.00f;
	bool alive;
};

#endif /* BULLET_H */
