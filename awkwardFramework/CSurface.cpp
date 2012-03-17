#include "CSurface.h"

CSurface::CSurface()
{

}

SDL_Surface* CSurface::OnLoad(char* File)
{
	SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* Surf_Return = NULL;

	if((Surf_Temp = IMG_Load(File)) == NULL)
	{
		return NULL;
	}

	Surf_Return = SDL_DisplayFormatAlpha(Surf_Temp);
	SDL_FreeSurface(Surf_Temp);

	return Surf_Return;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y)
{
	if(Surf_Dest == NULL || Surf_Src == NULL)
		return false;

	SDL_Rect DestR;

	DestR.x = x;
	DestR.y = y;

	SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);

	return true;
}

bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int x, int y, int x2, int y2, int w, int h)
{
	if(Surf_Dest == NULL || Surf_Src == NULL)
		return false;

	SDL_Rect DestR;

	DestR.x = x;
	DestR.y = y;
	
	SDL_Rect SrcR;
	SrcR.h = h;
	SrcR.x = x2;
	SrcR.y = y2;
	SrcR.w = w;

	SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

	return true;
}

bool CSurface::Transparent(SDL_Surface* Surf_Dest, int r, int g, int b)
{
	if(Surf_Dest == NULL)
		return false;

	SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format,r,g,b));
	return true;
}