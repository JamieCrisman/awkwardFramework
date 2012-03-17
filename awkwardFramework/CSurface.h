#ifndef _CSURFACE_H_
	#define _CSURFACE_H_

#include <SDL.h>
#include <SDL_image.h>

class CSurface
{
public:
	CSurface();

	static SDL_Surface* OnLoad(char* File);

	static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y);

	static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y, int x2, int y2, int w, int h);

	static bool Transparent(SDL_Surface* Surf_Dest, int r, int g, int b);
};



#endif