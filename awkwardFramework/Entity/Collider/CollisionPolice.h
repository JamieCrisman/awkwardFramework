#ifndef _COLLIDERPOLICE_H_
	#define _COLLIDERPOLICE_H_
#include "../../Util/glm/glm.hpp"
#include "../Entity.h"
#include "Collider.h"
class CollisionPolice{
public:
	CollisionPolice();
private:
	void CheckCollision(Entity one, Entity two);
	void SquareSquareCollision(Entity one, Entity two);
	//not going to bother with these for now.. but it'll be possible atleast
	void SquareCircleCollision(Entity one, Entity two);
	void CircleCircleCollision(Entity one, Entity two);
	
	//collision on a single axis for box
	bool OneAxisCollisionBox();
};

#endif