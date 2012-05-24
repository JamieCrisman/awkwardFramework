#ifndef _CAPPSTATEINTRO_H_
	#define _CAPPSTATEINTRO_H_

#include "CAppState.h"
#include "CSurface.h"

class CAppStateIntro : public CAppState{
private:
	static CAppStateIntro Instance;
	SDL_Surface* Surf_Logo;
	int StartTime;

	CAppStateIntro();

public:
	void OnActivate();
	void OnDeactivate();
	void OnLoop();
	void OnRender();
	static CAppStateIntro* GetInstance();


};


#endif