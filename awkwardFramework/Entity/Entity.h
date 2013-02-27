#ifndef _ENTITY_H_
	#define _ENTITY_H_

#include "../Util/Transform.h"
#include "../Util/CFPS.h"
#include "../Util/CCamera.h"
//#include <SDL_opengl.h>
//#include <SDL_image.h>
#include "../Graphics/Sprite.h"
#include "Collider/Collider.h"
#include <vector>

class Sprite;

class EntityTagData
{
public:
	EntityTagData();
	EntityTagData(const std::string &name, bool save);
	EntityTagData(const EntityTagData &);

	std::string name;
	bool save;
};

typedef std::vector<EntityTagData> EntityTags;

class Entity : public Transform{
public:
	static std::vector<Entity*> EntityList;

protected:
	glm::vec2 Speed;
	glm::vec2 acceleration;
	Sprite sprite;
	Collider collider;
	std::vector<EntityTagData> tags;
public:
	void *getThis();
	void Add();
	float getX();
	float getY();
	void SetPos(glm::vec2 pos);
	int Width;
	int Height;
	glm::vec2 maxSpeed;
	//float MaxSpeedX;
	//float MaxSpeedY;

	int AnimState;

	//! Associates this entity with the given tag
	void AddTag(const std::string& tag, bool save=false);
	//! Checks whether this entity is associated with a given tag
	bool HasTag(const std::string& tag);
	//! Removes a tag from this Entity
	void RemoveTag(const std::string& tag);
	//! Gets the tag at the given offset from the list of tags
	const std::string& GetTag(int index);
	//! Gets the number of tags associated with this entity
	int GetNumberOfTags();

	//returns a collider obj
	Collider getCollider();
	//sets the collider duh
	void setCollider(int type, glm::vec2 offset);

	Entity();
	virtual ~Entity();

	virtual void handleCollision();
	virtual bool OnLoad(char* File, float width, float height, int MaxFrames);
	virtual void OnLoop(Uint8 *keys);
	virtual void OnRender();
	virtual void OnCleanup();
	virtual void OnAnimate();
	virtual bool OnCollision(Entity* Entity);


	void OnMove(float MoveX, float MoveY);
	void StopMove();

	bool Collides(int oX, int oY, int oW, int oH);

};


class EntityCol{
public:
	static std::vector<EntityCol> EntityColList;
	Entity* EntityA;
	Entity* EntityB;
	EntityCol();
};

#endif