#include "CAppStateGame.h"
#include "CAppStateManager.h"

CAppStateGame CAppStateGame::Instance;

CAppStateGame::CAppStateGame(){
}

void CAppStateGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){
	switch(sym){
		case SDLK_1: {
			CAppStateManager::SetActiveAppState(APPSTATE_INTRO);
			break;
		}
		default:{
		}
	
	}

}
void CAppStateGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode){
	
}

void CAppStateGame::OnActivate(){
	if(Entity.OnLoad("yoshi.png", 64, 64, 8) == false){
		return;
	}

	if(Entity2.OnLoad("test.png", 100, 100, 8) == false){
		return;
	}

	Entity.X = 100;
	Entity.Y = 100;

	Entity2.X = 300;
	Entity2.Y = 300;

	CEntity::EntityList.push_back(&Entity);
	CEntity::EntityList.push_back(&Entity2);

	CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
	CCamera::CameraControl.SetTarget(&Entity.X, &Entity.Y);
	SDL_WM_SetCaption("Game State", NULL);
}

void CAppStateGame::OnDeactivate(){
	//CArea::AreaControl.OnCleanup();
	for(int i = 0;i < CEntity::EntityList.size(); i++){
		if(!CEntity::EntityList[i])continue;
		CEntity::EntityList[i]->OnCleanup();
	}
	CEntity::EntityList.clear();
}

void CAppStateGame::OnLoop(){
	for(int i = 0;i < CEntity::EntityList.size(); i++){
		if(!CEntity::EntityList[i])continue;
		CEntity::EntityList[i]->OnLoop();
	}

	for(int i = 0; i < CEntityCol::EntityColList.size(); i++){
		CEntity* EntityA = CEntityCol::EntityColList[i].EntityA;
		CEntity* EntityB = CEntityCol::EntityColList[i].EntityB;

		if(EntityA == NULL || EntityB == NULL)continue;

		if(EntityA->OnCollision(EntityB)){
			EntityB->OnCollision(EntityA);
		}

	}
	CEntityCol::EntityColList.clear();
}

void CAppStateGame::OnRender(SDL_Surface* Surf_Display){
	SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.h = WHEIGHT;
	Rect.w = WWIDTH;

	SDL_FillRect(Surf_Display, &Rect, 0);
	/*
	CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
	*/
	for(int i = 0;i < CEntity::EntityList.size(); i++){
		if(!CEntity::EntityList[i])continue;
		CEntity::EntityList[i]->OnRender(Surf_Display);
	}
	
}

CAppStateGame* CAppStateGame::GetInstance(){
	return &Instance;
}