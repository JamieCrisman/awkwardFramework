#ifndef _COLLIDERPOLICE_H_
	#define _COLLIDERPOLICE_H_
#include "../../Util/glm/glm.hpp"
#include "../Entity.h"
#include "Collider.h"

class CollisionPolice{
public:
	CollisionPolice();
	glm::vec2 CheckCollision(Collider* ichi, Collider* ni);
private:
	glm::vec2 SquareSquareCollision(BlockCollider* ichi, BlockCollider* ni);
	//not going to bother with these for now.. but it'll be possible atleast
	/*
	void SquareCircleCollision(Collider* ichi, Collider* ni);
	void CircleCircleCollision(Collider* ichi, Collider* ni);
	*/
	//collision on a single axis for box
	float penetrationAmount(float aH, float aD, float bH, float bD);
};

#endif