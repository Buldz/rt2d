/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 * 
 * - Copyright 2015 Rik Teerling <rik@onandoffables.com>
 *     - Initial commit
 * - Copyright 2015 Your Name <you@yourhost.com>
 *     - What you did
 */

#ifndef BOIDENTITY_H
#define BOIDENTITY_H

#include <rt2d/entity.h>

class BoidEntity: public Entity
{
	public:
		BoidEntity();
		virtual ~BoidEntity();
		
		virtual void update(float deltaTime);
		
		Vector2 velocity;
	
	private:
		/* add your private declarations */
};

#endif /* BOIDENTITY_H */ 
