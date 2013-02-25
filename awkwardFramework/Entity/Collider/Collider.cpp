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
int Collider::getShape(){
	return shape;
}

glm::vec2 BlockCollider::getDimensions(){
	return dimensions;
}

float CircleCollider::getRadius(){
	return radius;
}