#ifndef _CPLAYER_H_
	#define _CPLAYER_H_

#include "CEntity.h"

class CPlayer : public CEntity {
public:
	CPlayer();
	bool OnLoad(char* File, float width, float height, int MaxFrames);
	void OnLoop();

	void OnRender(SDL_Surface* Surf_Display);

	void OnCleanup();
	void OnAnimate();
	bool OnCollision(CEntity* Entity);


};












#endif