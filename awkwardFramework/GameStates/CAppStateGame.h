#ifndef _CAPPSTATEGAME_H_
	#define _CAPPSTATEGAME_H_
#include "CAppState.h"

//#include "CArea.h"
#include "../Util/CCamera.h"
#include "../Entity/Entity.h"
//#include "CSurface.h"
#include "../Entity/CPlayer.h"
#include "../Entity/Collider/Collider.h"
#include "../Entity/Collider/CollisionPolice.h"
#include "../Graphics/Fonts/FreeTypeFont.h"
#include "../Entity/WorldEntity.h"
#include "../Util/Quadtree.h"

class CAppStateGame : public CAppState{
private:
	static CAppStateGame Instance;
		Shashin texture;
		CPlayer player;
		WorldEntity floor, spire;
		WorldEntity block[10];
		CollisionPolice CP;
		Quadtree QTree;
		bool doSleep;
		//CPlayer player2;
		//CEntity Entity;
		//CEntity Entity2;
		//b2Vec2 gravity(0.0f, -10.0f);
		freetype::font_data our_font;
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