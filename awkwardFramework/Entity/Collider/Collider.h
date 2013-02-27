#ifndef _COLLIDER_H_
	#define _COLLIDER_H_
#include "../../Util/glm/glm.hpp"
enum {
	COLLIDER_TYPE_NONE = 0,
	COLLIDER_TYPE_SQUARE = 1,
	COLLIDER_TYPE_CIRCLE = 2,
	COLLIDER_TYPE_POLYGON = 3
};
class Collider {
public:
	Collider();
	int getShape();
	glm::vec2 colliderPosition();
	glm::vec2 getPosition();
	glm::vec2 getOffset();
	void setPosition(glm::vec2 &pos);
	void setOffset(glm::vec2 off);
protected:
	//position is xy of entity, and offset is xy from topleft
	glm::vec2 position, offset;
	int shape;
};


class BlockCollider : public Collider{
public:
	BlockCollider();
	glm::vec2 getDimensions();
	void setDimensions(glm::vec2 dim);
private:
	glm::vec2 dimensions;
};

class CircleCollider : public Collider{
public:
	float getRadius();
private:
	float radius;
};




#endif