#ifndef _CAPPSTATEGAME_H_
	#define _CAPPSTATEGAME_H_
#include "CAppState.h"

//#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
#include "CSurface.h"
#include "CPlayer.h"

class CAppStateGame : public CAppState{
private:
	static CAppStateGame Instance;

		CEntity Entity;
		CEntity Entity2;

	CAppStateGame();

public:
	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

	void OnActivate();
	void OnDeactivate();
	void OnLoop();
	void OnRender(SDL_Surface* Surf_Display);
	static CAppStateGame* GetInstance();
};


#endif