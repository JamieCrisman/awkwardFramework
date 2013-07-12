#include "Collider.h"
#include "../Entity.h"
Collider::Collider(){
	entity = NULL;
	shape = COLLIDER_TYPE_NONE;
}

glm::vec2 Collider::getPosition(){
	if(entity != nullptr){
		return glm::vec2(entity->getPosition().x + entity->offset.x, entity->getPosition().y + entity->offset.y);
	}else{
		return glm::vec2(-1,-1);
	}
}
glm::vec4 Collider::getOffset(){
	return entity->getOffset();
}

Collider* Collider::getThis(){
	return this;
}

Entity* Collider::getEntity(){
	return entity;
}

int Collider::getShape(){
	return shape;
}

BlockCollider::BlockCollider() : Collider(){
	shape = COLLIDER_TYPE_SQUARE;
}
BlockCollider::BlockCollider(Entity* e) : Collider(){
	shape = COLLIDER_TYPE_SQUARE;
	entity = e;
}


glm::vec2 Collider::getDimensions(){
	return entity->getDimensions();
}

float CircleCollider::getRadius(){
	return radius;
}