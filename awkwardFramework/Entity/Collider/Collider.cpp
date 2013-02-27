#include "Collider.h"

Collider::Collider(){
	shape = COLLIDER_TYPE_NONE;
	position = glm::vec2(0.0f, 0.0f);
	offset = glm::vec2(0.0f, 0.0f);
}

glm::vec2 Collider::getPosition(){
	return position;
}
glm::vec2 Collider::getOffset(){
	return offset;
}
void Collider::setPosition(glm::vec2 &pos){
	position = pos;
}
void Collider::setOffset(glm::vec2 off){
	offset = off;
}
glm::vec2 Collider::colliderPosition(){
	return glm::vec2(position.x + offset.x, position.y + offset.y);
}
int Collider::getShape(){
	return shape;
}

BlockCollider::BlockCollider(){
	shape = COLLIDER_TYPE_SQUARE;
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