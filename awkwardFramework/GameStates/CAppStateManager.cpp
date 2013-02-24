#include "CAppStateManager.h"

//include other appstates here
#include "CAppStateIntro.h"
#include "CAppStateGame.h"


CAppState* CAppStateManager::ActiveAppState = 0;

void CAppStateManager::OnEvent(SDL_Event* EventHolder){
	if(ActiveAppState) ActiveAppState->OnEvent(EventHolder);
}

void CAppStateManager::OnLoop(){
	if(ActiveAppState) ActiveAppState->OnLoop();

}

void CAppStateManager::OnRender(){
	if(ActiveAppState) ActiveAppState->OnRender();

}

void CAppStateManager::SetActiveAppState(int AppStateID) {
    if(ActiveAppState) ActiveAppState->OnDeactivate();
 
    // Also, add your App State Here so that the Manager can switch to it
    if(AppStateID == APPSTATE_NONE)        ActiveAppState = 0;
    if(AppStateID == APPSTATE_INTRO)    ActiveAppState = CAppStateIntro::GetInstance();
    if(AppStateID == APPSTATE_GAME)        ActiveAppState = CAppStateGame::GetInstance();
 
    if(ActiveAppState) ActiveAppState->OnActivate();
}

CAppState* CAppStateManager::GetActiveAppState() {
    return ActiveAppState;
}
