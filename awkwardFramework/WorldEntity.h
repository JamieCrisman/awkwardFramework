#ifndef _WORLDENTITY_H_
	#define _WORLDENTITY_H_

#include <vector>
#include "Transform.h"
#include "CFPS.h"
#include "Sprite.h"
#include "CEntity.h"

class Sprite;

class WorldEntity : public CEntity{
public:
	//static std::vector<WorldEntity*> WorldEntityList;

protected:
	Sprite sprite;
public:
	float getX();
	float getY();
	void SetPos(Vector2 pos);
	int Width;
	int Height;
	Vector2 maxSpeed;
	AFTexture worldTexture;
	//float MaxSpeedX;
	//float MaxSpeedY;



	WorldEntity();
	WorldEntity(char* File, float width, float height, Vector2 pos);
	virtual ~WorldEntity();

	virtual bool Load(char* File, float width, float height, Vector2 pos);
	virtual void OnRender();

};

#endif