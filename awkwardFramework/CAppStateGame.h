#ifndef _CAPPSTATEGAME_H_
	#define _CAPPSTATEGAME_H_
#include "CAppState.h"

//#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
//#include "CSurface.h"
#include "CPlayer.h"
#include "FreeType.h"
#include "WorldEntity.h"
#include <Box2D/Box2D.h>

class CAppStateGame : public CAppState{
private:
	static CAppStateGame Instance;
		AFTexture texture;
		CPlayer player;
		WorldEntity floor;
		bool doSleep;
		//CPlayer player2;
		//CEntity Entity;
		//CEntity Entity2;
		//b2Vec2 gravity(0.0f, -10.0f);
		b2World world;
		freetype::font_data our_font;
		b2Vec2 x;
		char* msg;
	CAppStateGame();

public:
	Uint8 *keys;
	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

	void OnActivate();
	void OnDeactivate();
	void OnLoop();
	void OnRender();
	static CAppStateGame* GetInstance();
};


#endif