#ifndef _CAPP_H_
	#define _CAPP_H_
#include <SDL.h>
#include <SDL_opengl.h>
#include "CEvent.h"
//#include "CSurface.h"
#include "Define.h"
//#include "CSoundBank.h"
#include "CAppStateManager.h"
#include "CFPS.h"
#include "Vector2.h"

class CApp : public CEvent
{
private:
	bool Running;

	SDL_Surface* Surf_Display;
	

public:
	CApp();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnExit();

	void OnLoop();

	void OnRender();

	void OnCleanup();


};

#endif