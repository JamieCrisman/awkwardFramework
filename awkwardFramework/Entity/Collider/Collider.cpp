#include "Collider.h"

glm::vec2 Collider::getDimensions(){
	return dimensions;
}
glm::vec2 Collider::getPosition(){
	return position;
}
glm::vec2 Collider::getOffset(){
	return offset;
}
int Collider::getType(){
	return type;
}