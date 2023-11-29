// bullet.h

#ifndef BULLET_H
#define BULLET_H

#include <rt2d/entity.h>

class Bullet: public Entity
{
public:
	Bullet();
	virtual ~Bullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
private:
	/* add your private declarations */
};

#endif /* BULLET_H */
