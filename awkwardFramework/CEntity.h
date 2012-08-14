#ifndef _CENTITY_H_
	#define _CENTITY_H_

#include <vector>
#include "Transform.h"
#include "CFPS.h"
#include "CCamera.h"
//#include <SDL_opengl.h>
//#include <SDL_image.h>
#include "Sprite.h"
#include <vector>
#include <Box2D\Box2D.h>

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

class CEntity : public Transform{
public:
	static std::vector<CEntity*> EntityList;

protected:
	//float SpeedX;
	//float SpeedY;
	Vector2 Speed;
	float AccelX;
	float AccelY;
	Sprite sprite;

	std::vector<EntityTagData> tags;

public:
	b2Body *body;
	void *getThis();
	void Add();
	float X;
	float Y;
	float getX();
	float getY();
	void SetPos(Vector2 pos);
	int Width;
	int Height;
	int Type;
	Vector2 maxSpeed;
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


	CEntity();
	virtual ~CEntity();

	virtual bool OnLoad(char* File, float width, float height, int MaxFrames);
	virtual void OnLoop(Uint8 *keys);
	virtual void OnRender();
	virtual void OnCleanup();
	virtual void OnAnimate();
	virtual bool OnCollision(CEntity* Entity);


	void OnMove(float MoveX, float MoveY);
	void StopMove();

	bool Collides(int oX, int oY, int oW, int oH);

};


class CEntityCol{
public:
	static std::vector<CEntityCol> EntityColList;
	CEntity* EntityA;
	CEntity* EntityB;
	CEntityCol();
};

#endif