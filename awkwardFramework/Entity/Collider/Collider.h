#ifndef _COLLIDER_H_
	#define _COLLIDER_H_

#include "../../Util/glm/glm.hpp"
enum {
	COLLIDER_TYPE_NONE = 0,
	COLLIDER_TYPE_SQUARE = 1,
	COLLIDER_TYPE_CIRCLE = 2,
	COLLIDER_TYPE_POLYGON = 3
};
class Entity;
class Collider {
public:
	Collider();
	int getShape();
	glm::vec2 colliderPosition();
	glm::vec2 getPosition();
	glm::vec2 getActualPosition();
	glm::vec4 getOffset();
	void setPosition(glm::vec2 &pos);
	void setOffset(glm::vec4 off);
	Entity* getEntity();
	Collider* getThis();
	glm::vec2 getDimensions();
	void setDimensions(glm::vec2 dim);
protected:
	//position is xy of entity, and offset is xy from topleft
	glm::vec2 position;
	glm::vec4 offset;
	Entity* entity;
	int shape;
	glm::vec2 dimensions;
};


class BlockCollider : public Collider{
public:
	BlockCollider();
	BlockCollider(Entity* e);
	BlockCollider(Entity* e, glm::vec2 dim, glm::vec4 off);
};

class CircleCollider : public Collider{
public:
	float getRadius();
private:
	float radius;
};




#endif