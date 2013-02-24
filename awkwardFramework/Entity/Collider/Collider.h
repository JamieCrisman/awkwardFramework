#ifndef _COLLIDER_H_
	#define _COLLIDER_H_
#include "../../Util/glm/glm.hpp"
class Collider {
public:
	Collider(){
		type = COLLIDER_TYPE_NONE;
	}
	int getType();
	glm::vec2 getPosition();
	glm::vec2 getDimensions();
	glm::vec2 getOffset();
	enum {
		COLLIDER_TYPE_NONE = 0,
		COLLIDER_TYPE_SQUARE = 1,
		COLLIDER_TYPE_CIRCLE = 2,
		COLLIDER_TYPE_POLYGON = 3
	};
private:
	//position is xy of entity, dimensions is wh of entity, and offset is xy from topleft
	glm::vec2 &position, &dimensions, offset;
	int type;
}
#endif