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
	SDL_WM_SetCaption("Game State", NULL);

	

	//if(Entity.OnLoad("Assets/Images/Sprites/yoshi.png", 64, 64, 8) == false){
	//	return;
	//}
	
	if( !texture.Load("Assets/Images/Sprites/yoshi.png", 128, 512) ){
		//SDL_WM_SetCaption("Didn't load texture", NULL);
		return;
	}
	player.setTexture(texture);
	player.SetPos(Vector2(200, 300));
	player.rotation = 20.0;
	//player.Animation.Add("S", 0, 2, 1.0);
	//player.Animation.Play("S");

	CEntity::EntityList.push_back(&player);

	CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
	CCamera::CameraControl.SetTarget(&player.X, &player.Y);
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
	player.OnRender();
	/*
	CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
	*/
	for(int i = 0;i < CEntity::EntityList.size(); i++){
		if(!CEntity::EntityList[i])continue;
		CEntity::EntityList[i]->OnRender();
	}
	
}

CAppStateGame* CAppStateGame::GetInstance(){
	return &Instance;
}