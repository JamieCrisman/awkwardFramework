#include "Collider.h"
#include "../Entity.h"
Collider::Collider(){
	entity = NULL;
	shape = COLLIDER_TYPE_NONE;
	position = glm::vec2(0.0f, 0.0f);
	offset = glm::vec2(0.0f, 0.0f);
}

glm::vec2 Collider::getPosition(){
	if(entity != nullptr){
		return entity->getPosition();
	}else{
		return position;
	}
	
}
glm::vec2 Collider::getOffset(){
	return offset;
}
void Collider::setPosition(glm::vec2 &pos){
	position = pos;
}
Collider* Collider::getThis(){
	return this;
}
void Collider::setOffset(glm::vec2 off){
	offset = off;
}
glm::vec2 Collider::colliderPosition(){
	//TODO:: make this do entity position + offset if there's an entity
	return glm::vec2(position.x + offset.x, position.y + offset.y);
}
int Collider::getShape(){
	return shape;
}
BlockCollider::BlockCollider(){
	shape = COLLIDER_TYPE_SQUARE;
}
BlockCollider::BlockCollider(Entity* e){
	shape = COLLIDER_TYPE_SQUARE;
	entity = e;
	dimensions = glm::vec2(e->getWidth(), e->getHeight());
	position = glm::vec2(0.0f, 0.0f);
	offset = glm::vec2(0.0f, 0.0f);
}

glm::vec2 BlockCollider::getDimensions(){
	return dimensions;
}
void BlockCollider::setDimensions(glm::vec2 &dim){
	dimensions = dim;
}

float CircleCollider::getRadius(){
	return radius;
}