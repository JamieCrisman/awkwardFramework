#ifndef _TRANSFORM_H_
	#define _TRANSFORM_H_

//#include "Vector2.h"
#include "glm\glm.hpp"
class Transform{
public:
	Transform();
	Transform(const Transform &transform);

	//Vector2 position;
	//float rotation;
	//Vector2 scale;
	glm::vec2 position;
	glm::vec2 scale;
	float rotation;


};



#endif