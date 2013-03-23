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
	//this will need to be revised to use less placeholder obj, but this will help
	//sort out what needs to happen
	//xxxD is (dimensions/2)
	//xxxP is position (including offset)
	//xxxH is xxxP + xxxD being the center point of the collider
	glm::vec2 aS = ichi->getEntity()->scale;
	glm::vec2 bS = ni->getEntity()->scale;
	float aLeftOffset = ichi->getOffset().x * glm::abs(aS.x);
	float aTopOffset = ichi->getOffset().y * glm::abs(aS.y);
	float aRightOffset = ichi->getOffset().z * glm::abs(aS.x);
	float aBottomOffset = ichi->getOffset().w * glm::abs(aS.y);

	//half dimensions
	glm::vec2 oneD = ichi->getDimensions();
	oneD = glm::vec2((oneD.x * glm::abs(aS.x) - (aLeftOffset + aRightOffset)) * 0.5,
		(oneD.y * glm::abs(aS.y) - (aTopOffset + aBottomOffset)) * 0.5);

	float bLeftOffset = ni->getOffset().x * glm::abs(bS.x);
	float bTopOffset = ni->getOffset().y * glm::abs(bS.y);
	float bRightOffset = ni->getOffset().z * glm::abs(bS.x);
	float bBottomOffset = ni->getOffset().w * glm::abs(bS.y);

	//half dimensions
	glm::vec2 twoD = ni->getDimensions();
	twoD = glm::vec2(twoD.x * 0.5 * glm::abs(bS.x), twoD.y * 0.5 * glm::abs(bS.y));


	glm::vec2 oneP = glm::vec2(ichi->getPosition().x + aLeftOffset, ichi->getPosition().y + aTopOffset);
	glm::vec2 twoP = glm::vec2(ni->getPosition().x + bLeftOffset,	ni->getPosition().y + bTopOffset);
	glm::vec2 oneH = glm::vec2(oneD.x + oneP.x, oneD.y + oneP.y);
	glm::vec2 twoH = glm::vec2(twoD.x + twoP.x, twoD.y + twoP.y);
	if(glm::abs(oneH.y - twoH.y) > (oneD.y + twoD.y)){
		return;
	}
	if(glm::abs(oneH.x - twoH.x) > (oneD.x + twoD.x)){
		return;
	}
	//this point we know we have a collision
	float pX = penetrationAmount(oneH.x, oneD.x, twoH.x, twoD.x);
	pX = (oneP.x < twoP.x)? -1 * pX : pX;
	float pY = penetrationAmount(oneH.y, oneD.y, twoH.y, twoD.y);
	pY = (oneP.y < twoP.y)? -1 * pY : pY;
	if(ichi->getEntity() != NULL){
		//we choose the lower of the two displacements and only go on one axis
		if(glm::abs(pX) < glm::abs(pY)){
			//if x mag is less than y mag
			ichi->getEntity()->handleCollision(glm::vec2(pX, 0.0f));
		}else{
			//if y mag is less than x mag
			ichi->getEntity()->handleCollision(glm::vec2(0.0f, pY));
		}
		
	}
	return;
}

//for AABB SAT
float CollisionPolice::penetrationAmount(float aH, float aD, float bH, float bD){
	return (aD + bD) - glm::abs(aH - bH);
}

/*
void CollisionPolice::SquareCircleCollision(Collider* ichi, Collider* ni){
	return; // not handling this right now
}

void CollisionPolice::CircleCircleCollision(Collider* ichi, Collider* ni){
	return; //not handling this right now
}
*/
