#ifndef _CMAP_H_
	#define _CMAP_H_

#include <SDL.h>
#include <vector>

#include "CTile.h"
#include "CSurface.h"

class CMap{
public:
	SDL_Surface* Surf_Tileset;
	CMap();
	bool OnLoad(char* File);
	void OnRender(SDL_Surface* Surf_Display, int MapX, int MapY);
	CTile* GetTile(int X, int Y);
private:
	std::vector<CTile> TileList;


};


#endif