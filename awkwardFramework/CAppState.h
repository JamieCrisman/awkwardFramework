#ifndef _CAPPSTATE_H_
	#define _CAPPSTATE_H_

#include "CEvent.h"

class CAppState : public CEvent {

public:
	CAppState();

	virtual void OnActivate() = 0;
	virtual void OnDeactivate() = 0;
	virtual void OnLoop() = 0;
	virtual void OnRender(SDL_Surface* Surf_Display) = 0;



};




#endif