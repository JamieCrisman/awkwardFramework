#include "CAppStateGame.h"
#include "CAppStateManager.h"

CAppStateGame CAppStateGame::Instance;

CAppStateGame::CAppStateGame(){

}

void CAppStateGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){
	if(keys[SDLK_LEFT]){
		player.SetPos(Vector2((player.getX() - 5.0), (player.getY())));
		player.Animation.Play("walk");
		if(player.scale.x > 0)
			player.scale.x *= -1;

	}
	if(keys[SDLK_UP]){
		player.SetPos(Vector2((player.getX()), (player.getY() - 5.0)));
	}
	if(keys[SDLK_RIGHT]){
		player.SetPos(Vector2((player.getX() + 5.0), (player.getY())));
		player.Animation.Play("walk");
		if(player.scale.x < 0)
			player.scale.x *= -1;

	}
	if(keys[SDLK_DOWN]){
		player.SetPos(Vector2((player.getX()), (player.getY() + 5.0)));
	}
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
	player.Animation.Play("idle");
}

void CAppStateGame::OnActivate(){
	SDL_WM_SetCaption("Game State", NULL);

	our_font.init("Assets/Fonts/Arial.ttf",16);

	if( !texture.Load("Assets/Images/Sprites/placeholder_player.png", 256, 64) ){
		return;
	}

	floor.Load("Assets/Images/World/placeholder_grass.png", 140, 10, Vector2(320, 475));
	floor.scale.x = 5.0;
	floor.scale.y = 5.0;

	player.Animation.setTexture(texture, 32, 32);

	player.Animation.setColor(1.0, 1.0, 1.0);
	
	player.SetPos(Vector2(250, 300));
	
	player.scale.x = 5.0;
	player.scale.y = 5.0;

	player.Animation.Add("idle", 0, 0, 1.0);
	player.Animation.Add("walk", 8, 15, 10.0);
	player.Animation.Add("16", 16, 16, 8.0);

	//CEntity::EntityList.push_back(&player);
	//CEntity::EntityList.push_back(&floor);
}

void CAppStateGame::OnDeactivate(){
	for(int i = 0;i < CEntity::EntityList.size(); i++){
		if(!CEntity::EntityList[i])continue;
		CEntity::EntityList[i]->OnCleanup();
	}
	CEntity::EntityList.clear();

	our_font.clean();
}

void CAppStateGame::OnLoop(){
	keys = SDL_GetKeyState( NULL );
	for(int i = 0;i < CEntity::EntityList.size(); i++){
		if(!CEntity::EntityList[i])continue;
		CEntity::EntityList[i]->OnLoop(keys);
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

void CAppStateGame::OnRender(){
	for(int i = 0;i < CEntity::EntityList.size(); i++){
		if(!CEntity::EntityList[i])continue;
		CEntity::EntityList[i]->OnRender();
	}
	freetype::print(our_font, 200,200,"Bleep Bloop!");
	
}

CAppStateGame* CAppStateGame::GetInstance(){
	return &Instance;
}