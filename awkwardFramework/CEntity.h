#ifndef _CENTITY_H_
	#define _CENTITY_H_

#include "CAnimation.h"
#include <vector>
//#include "CArea.h"
#include "CFPS.h"
#include "CCamera.h"
#include <SDL_opengl.h>
#include <SDL_image.h>

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

class CEntity{
public:
	static std::vector<CEntity*> EntityList;

protected:
	CAnimation Anim_Control;

	GLuint texture;
	float SpeedX;
	float SpeedY;
	float AccelX;
	float AccelY;

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

	int Width;
	int Height;
	bool MoveLeft;
	bool MoveRight;
	int Type;
	bool Dead;
	int Flags;

	float MaxSpeedX;
	float MaxSpeedY;


	int AnimState;
	


	CEntity();
	virtual ~CEntity();

	virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);
	virtual void OnLoop();
	virtual void OnRender(SDL_Surface* Surf_Display);
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