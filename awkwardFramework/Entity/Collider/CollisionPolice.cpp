#include "CollisionPolice.h"

CollisionPolice::CollisionPolice(){
}

void CollisionPolice::CheckCollision(Entity one, Entity two){
	//figure out what collision types and the run the correct function to manage them
	int ichi = one.getCollider().getShape();
	int ni = two.getCollider().getShape();

	if(ichi == COLLIDER_TYPE_NONE || ni == COLLIDER_TYPE_NONE){
		return; //don't waste time checking collision on things without colliders
	}
	if(ichi == COLLIDER_TYPE_SQUARE && ni == COLLIDER_TYPE_SQUARE){
		//we're expecting this type in most cases so do it first
		SquareSquareCollision(one, two);
		return;
	}
	//there's not that many cases, we can make this better if it gets too complicated
	if(ichi == COLLIDER_TYPE_SQUARE && ni == COLLIDER_TYPE_CIRCLE){
		SquareCircleCollision(one, two);
		return;
	}else if(ichi == COLLIDER_TYPE_CIRCLE && ni == COLLIDER_TYPE_SQUARE){
		SquareCircleCollision(two, one);
		return;
	}

	if(ichi == COLLIDER_TYPE_CIRCLE && ni == COLLIDER_TYPE_CIRCLE){
		CircleCircleCollision(one, two);
		return;
	}

	//if we get to here there's a collision type/pairing I didn't handle correctly
}

void CollisionPolice::SquareSquareCollision(Entity one, Entity two){
	Collider ichi = one.getCollider();
	Collider ni = two.getCollider();


}

void CollisionPolice::SquareCircleCollision(Entity one, Entity two){
	return; // not handling this right now
}

void CollisionPolice::CircleCircleCollision(Entity one, Entity two){
	return; //not handling this right now
}






CollisionVector::CollisionVector(){
	ResponseVector = glm::vec2(0.0f, 0.0f);
}
CollisionVector::CollisionVector(glm::vec2 v){
	ResponseVector = v;
}
glm::vec2 CollisionVector::getResponseVector(){
	return ResponseVector;
}
void CollisionVector::setResponseVector(glm::vec2 v){
	//might want to switch this to do it per component
	ResponseVector = v;
}