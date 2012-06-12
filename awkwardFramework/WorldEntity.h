#ifndef _WORLDENTITY_H_
	#define _WORLDENTITY_H_

#include <vector>
#include "Transform.h"
#include "CFPS.h"
#include "Sprite.h"

class Sprite;

class WorldEntity : public Transform{
public:
	//static std::vector<CEntity*> EntityList;

protected:
	Sprite sprite;

public:
	float getX();
	float getY();
	void SetPos(Vector2 pos);
	int Width;
	int Height;
	int Type;
	int Flags;
	Vector2 maxSpeed;
	AFTexture worldTexture;
	//float MaxSpeedX;
	//float MaxSpeedY;



	WorldEntity();
	WorldEntity(char* File, float width, float height, Vector2 pos);
	virtual ~WorldEntity();

	virtual bool Load(char* File, float width, float height, Vector2 pos);
	virtual void OnLoop(Uint8 *keys);
	virtual void OnRender();
	virtual void OnCleanup();
	virtual void OnAnimate();
	//virtual bool OnCollision(CEntity* Entity);

	//bool Collides(int oX, int oY, int oW, int oH);

};

#endif