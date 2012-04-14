#ifndef _TRANSFORM_H_
	#define _TRANSFORM_H_

#include "Vector2.h"
class Transform{
public:
	Transform();
	Transform(const Transform &transform);

	Vector2 position;
	float rotation;
	Vector2 scale;

};



#endif