#include "CAppStateGame.h"
#include "CAppStateManager.h"

CAppStateGame CAppStateGame::Instance;

CAppStateGame::CAppStateGame(){

}

void CAppStateGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){
	if(keys[SDLK_LEFT]){
		player.SetPos(Vector2((player.getX() - 5.0), (player.getY())));
	}
	if(keys[SDLK_UP]){
		player.SetPos(Vector2((player.getX()), (player.getY() - 5.0)));
	}
	if(keys[SDLK_RIGHT]){
		player.SetPos(Vector2((player.getX() + 5.0), (player.getY())));
	}
	if(keys[SDLK_DOWN]){
		player.SetPos(Vector2((player.getX()), (player.getY() + 5.0)));
	}
	switch(sym){
		case SDLK_1: {
			CAppStateManager::SetActiveAppState(APPSTATE_INTRO);
			break;
		}
		/*
		case SDLK_UP: {
			 player.SetPos(Vector2((player.getX()), (player.getY() - 5.0)));
			 player.Animation.Play("S");
			break;
		}
		case SDLK_DOWN: {
			 player.SetPos(Vector2((player.getX()), (player.getY() + 5.0)));
			 player.Animation.Play("S");
			break;
		}
		case SDLK_LEFT: {
			 player.SetPos(Vector2((player.getX() - 5.0), (player.getY())));
			 player.Animation.Play("S");
			 if(player.scale.x > 0)
				player.scale.x *= -1;
			break;
		}
		case SDLK_RIGHT: {
			 player.SetPos(Vector2((player.getX() + 5.0), (player.getY())));
			 player.Animation.Play("S");
			 if(player.scale.x < 0)
				player.scale.x *= -1;
			break;
		}*/
		default:{
		}
	}

}
void CAppStateGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode){
}

void CAppStateGame::OnActivate(){
	SDL_WM_SetCaption("Game State", NULL);

	our_font.init("Test.ttf",16);

	//if(Entity.OnLoad("Assets/Images/Sprites/yoshi.png", 64, 64, 8) == false){
	//	return;
	//}
	
	if( !texture.Load("Assets/Images/Sprites/player.png", 64, 32) ){
		//SDL_WM_SetCaption("Didn't load texture", NULL);
		return;
	}


	player.Animation.setTexture(texture, 8, 8);
	player2.Animation.setTexture(texture, 8, 8);

	player.Animation.setColor(1.0, 0.0, 1.0);
	player2.Animation.setColor(1.0, 0.0, 0.0);
	
	player.SetPos(Vector2(250, 300));
	player2.SetPos(Vector2(200, 300));

	player2.rotation = 45.0;
	
	player.scale.x = 10.0;
	player.scale.y = 10.0;

	player2.scale.x = 10.0;
	player2.scale.y = 10.0;
	
	player2.Animation.Add("S", 0, 3, 10.0);
	player2.Animation.Play("S");

	player.Animation.Add("S", 0, 3, 10.0);
	player.Animation.Play("S");
	player.Animation.Stop();

	CEntity::EntityList.push_back(&player);
	CEntity::EntityList.push_back(&player2);

	//CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
	//CCamera::CameraControl.SetTarget(&player.X, &player.Y);
}

void CAppStateGame::OnDeactivate(){
	//CArea::AreaControl.OnCleanup();
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
	/*SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.h = WHEIGHT;
	Rect.w = WWIDTH;
	*/
	//SDL_FillRect(Surf_Display, &Rect, 0);
	//player.OnRender();
	/*
	CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
	*/
	for(int i = 0;i < CEntity::EntityList.size(); i++){
		if(!CEntity::EntityList[i])continue;
		CEntity::EntityList[i]->OnRender();
	}
	freetype::print(our_font, 200,200,"testing font rendering :O");
	
}

CAppStateGame* CAppStateGame::GetInstance(){
	return &Instance;
}