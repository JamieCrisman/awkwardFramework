#ifndef _CPLAYER_H_
	#define _CPLAYER_H_

#include "CEntity.h"

class CPlayer : public CEntity {
public:
	CPlayer();
	CPlayer(AFTexture t, float width, float height );
	bool OnLoad(char* File, float width, float height);
	void OnLoop(Uint8 *keys);

	void OnRender();

	void OnCleanup();
	void OnAnimate();
	bool OnCollision(CEntity* Entity);
	AFTexture texture;
	AnimControl Animation;
	//Sprite sprite;

	void setTexture(AFTexture t);

};












#endif