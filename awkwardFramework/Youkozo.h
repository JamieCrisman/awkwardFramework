#ifndef _CAPP_H_
	#define _CAPP_H_

#include <SDL.h>
#include <SDL_opengl.h>
#include "Core/CEvent.h"
//#include "CSurface.h"
#include "Core/Define.h"
//#include "CSoundBank.h"
#include "GameStates/CAppStateManager.h"
#include "Util/CFPS.h"
#include "Util/Vector2.h"

class Youkozo : public CEvent
{
private:
	bool Running;

	SDL_Surface* Surf_Display;
	

public:
	Youkozo();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnExit();

	void OnLoop();

	void OnRender();

	void OnCleanup();


};

#endif