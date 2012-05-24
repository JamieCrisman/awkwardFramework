#ifndef _CENTITY_H_
	#define _CENTITY_H_

//#include "CAnimation.h"
#include <vector>
#include "Transform.h"
//#include "CArea.h"
#include "CFPS.h"
#include "CCamera.h"
//#include <SDL_opengl.h>
//#include <SDL_image.h>
#include "Sprite.h"

enum {
	ENTITY_TYPE_GENERIC = 0,
	ENTITY_TYPE_PLAYER
};
enum {
	ENTITY_FLAG_NONE = 0,
	ENTITY_FLAG_GRAVITY= 0x00000001,
	ENTITY_FLAG_GHOST= 0x00000002,
	ENTITY_FLAG_MAPONLY= 0x00000004,

};

class Sprite;

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

	int CurrentFrameCol;
	int CurrentFrameRow;
	int Col_X;
	int Col_Y;
	int Col_Width;
	int Col_Height;
	bool CanJump;
	bool PosValid(int NewX, int NewY);
	//bool PosValidTile(CTile* Tile);
	//bool PosValidEntity(CEntity* Entity, int NewX, int NewY);

public:
	float X;
	float Y;
	bool Jump();
	float getX();
	float getY();
	void SetPos(Vector2 pos);
	int Width;
	int Height;
	bool MoveLeft;
	bool MoveRight;
	int Type;
	bool Dead;
	int Flags;
	Vector2 maxSpeed;
	//float MaxSpeedX;
	//float MaxSpeedY;

	int AnimState;
	


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