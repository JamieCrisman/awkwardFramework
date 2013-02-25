#ifndef _WORLDENTITY_H_
	#define _WORLDENTITY_H_

#include <vector>
#include "../Util/Transform.h"
#include "../Util/CFPS.h"
#include "../Graphics/Sprite.h"
#include "../Entity/Entity.h"

class Sprite;

class WorldEntity : public Entity{
public:
	//static std::vector<WorldEntity*> WorldEntityList;

protected:
	Sprite sprite;
public:
	float getX();
	float getY();
	void SetPos(glm::vec2 pos);
	int Width;
	int Height;
	glm::vec2 maxSpeed;
	Shashin worldTexture;
	//float MaxSpeedX;
	//float MaxSpeedY;



	WorldEntity();
	WorldEntity(char* File, float width, float height, glm::vec2 pos);
	virtual ~WorldEntity();

	virtual bool Load(char* File, float width, float height, glm::vec2 pos);
	virtual void OnRender();

};

#endif