#include "Collider.h"
#include "../Entity.h"
Collider::Collider(){
	entity = NULL;
	shape = COLLIDER_TYPE_NONE;
	position = glm::vec2(0.0f, 0.0f);
	offset = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

glm::vec2 Collider::getPosition(){
	if(entity != nullptr){
		return entity->getPosition();
	}else{
		return position;
	}
	
}
glm::vec4 Collider::getOffset(){
	return offset;
}
void Collider::setPosition(glm::vec2 &pos){
	position = pos;
}
Collider* Collider::getThis(){
	return this;
}
void Collider::setOffset(glm::vec4 off){
	offset = off;
}
Entity* Collider::getEntity(){
	return entity;
}
glm::vec2 Collider::colliderPosition(){
	//TODO:: make this do entity position + offset if there's an entity
	return glm::vec2(position.x + offset.x, position.y + offset.y);
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
	dimensions = glm::vec2(e->getWidth(), e->getHeight());
	position = glm::vec2(0.0f, 0.0f);
	offset = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

BlockCollider::BlockCollider(Entity* e, glm::vec2 dim, glm::vec4 off) : Collider(){
	shape = COLLIDER_TYPE_SQUARE;
	entity = e;
	dimensions = dim;
	position = glm::vec2(0.0f, 0.0f); //should output from entity anyways
	offset = off;
}


glm::vec2 BlockCollider::getDimensions(){
	return dimensions;
}
void BlockCollider::setDimensions(glm::vec2 dim){
	dimensions = dim;
}

float CircleCollider::getRadius(){
	return radius;
}