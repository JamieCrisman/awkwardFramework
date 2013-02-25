#include "Transform.h"

Transform::Transform(){
	position = glm::vec2(0.0f,0.0f);
	rotation = 0.0f;
	scale = glm::vec2(0.0f,0.0f);
}

Transform::Transform(const Transform &transform){
	position = transform.position;
	rotation = transform.rotation;
	scale    = transform.scale;
}

