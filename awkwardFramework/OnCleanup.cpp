#include "CApp.h"

void CApp::OnCleanup()
{
	CAppStateManager::SetActiveAppState(APPSTATE_NONE);
	//CSoundBank::SoundControl.OnCleanup();
	//Mix_CloseAudio();

	SDL_Quit();

}