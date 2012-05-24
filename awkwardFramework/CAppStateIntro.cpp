#include "CAppStateIntro.h"
#include "CAppStateManager.h"

CAppStateIntro CAppStateIntro::Instance;

CAppStateIntro::CAppStateIntro(){
	Surf_Logo = NULL;

}

void CAppStateIntro::OnActivate(){
	Surf_Logo = CSurface::OnLoad("test.bmp");

	StartTime = SDL_GetTicks();
	SDL_WM_SetCaption("Intro State", NULL);
}

void CAppStateIntro::OnDeactivate(){
	if(Surf_Logo){
		SDL_FreeSurface(Surf_Logo);
		Surf_Logo = NULL;
	
	}

}

void CAppStateIntro::OnLoop(){
	if(StartTime + 1000 < SDL_GetTicks()){
		CAppStateManager::SetActiveAppState(APPSTATE_GAME);
	}
}

void CAppStateIntro::OnRender(){
	/*if(Surf_Logo){
		CSurface::OnDraw(Surf_Display, Surf_Logo, 0, 0);
	}
	*/
}

CAppStateIntro* CAppStateIntro::GetInstance(){
	return &Instance;
}