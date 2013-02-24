#include "Transform.h"

Transform::Transform(){
	position = Vector2(0,0);
	rotation = 0.0f;
	scale = Vector2(1.0, 1.0);
}

Transform::Transform(const Transform &transform){
	position = transform.position;
	rotation = transform.rotation;
	scale    = transform.scale;
}

