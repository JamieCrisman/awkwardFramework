#include "CollisionPolice.h"

CollisionPolice::CollisionPolice(){
}

void CollisionPolice::CheckCollision(Collider* ichi, Collider* ni){
	//figure out what collision types and the run the correct function to manage them

	if(ichi->getShape() == COLLIDER_TYPE_NONE || ni->getShape() == COLLIDER_TYPE_NONE){
		return; //don't waste time checking collision on things without colliders
	}
	if(ichi->getShape() == COLLIDER_TYPE_SQUARE && ni->getShape() == COLLIDER_TYPE_SQUARE){
		//we're expecting this type in most cases so do it first
		SquareSquareCollision((BlockCollider*)ichi, (BlockCollider*)ni);
		return;
	}
	/*
	//there's not that many cases, we can make this better if it gets too complicated
	if(ichi->getShape() == COLLIDER_TYPE_SQUARE && ni->getShape() == COLLIDER_TYPE_CIRCLE){
		SquareCircleCollision(ichi, ni);
		return;
	}else if(ichi->getShape() == COLLIDER_TYPE_CIRCLE && ni->getShape() == COLLIDER_TYPE_SQUARE){
		SquareCircleCollision(ichi, ni);
		return;
	}
	
	if(ichi->getShape() == COLLIDER_TYPE_CIRCLE && ni->getShape() == COLLIDER_TYPE_CIRCLE){
		CircleCircleCollision(ichi, ni);
		return;
	}
	*/
	//if we get to here there's a collision type/pairing I didn't handle correctly
}

void CollisionPolice::SquareSquareCollision(BlockCollider* ichi, BlockCollider* ni){
	//ichi->getDimensions();

	return;
}
/*
void CollisionPolice::SquareCircleCollision(Collider* ichi, Collider* ni){
	return; // not handling this right now
}

void CollisionPolice::CircleCircleCollision(Collider* ichi, Collider* ni){
	return; //not handling this right now
}
*/