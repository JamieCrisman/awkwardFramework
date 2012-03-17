#ifndef _CAREA_H_
	#define _CAREA_H_

#include "CMap.h"

class CArea{
public:
	static CArea AreaControl;

	std::vector<CMap> MapList;

	CArea();
	bool OnLoad(char* File);
	void OnRender(SDL_Surface* Surf_Display, int CameraX, int CameraY);
	void OnCleanup();

	CMap* GetMap(int X, int Y);
	CTile* GetTile(int X, int Y);


private:
	int AreaSize;
	SDL_Surface* Surf_Tileset;


};


#endif