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
	player.Animation.Play("idle");
}

void CAppStateGame::OnActivate(){
	SDL_WM_SetCaption("Game State", NULL);

	//player.body->GetPosition();
	our_font.init("Assets/Fonts/Arial.ttf",16);

	if( !texture.Load("Assets/Images/Sprites/placeholder_player.png", 256, 64) ){
		return;
	}

	floor.Load("Assets/Images/World/placeholder_grass.png", 140, 10, Vector2(320, 475));
	floor.Add();
	//floor.scale.x = 5.0;
	//floor.scale.y = 5.0;

	player.Animation.setTexture(texture, 32, 32);

	player.Animation.setColor(1.0, 1.0, 1.0);
	
	//player.SetPos(Vector2(1, 1));
	
	//player.scale.x = 5.0;
	//player.scale.y = 5.0;

	//b2BodyDef Pbody;

	//Pbody.userData = player.getThis();
	//Pbody.position.Set(1, 2);
	//Pbody.fixedRotation = true;

	//b2Body* dbody = world.CreateBody(&Pbody);
	//player.body = dbody;
	player.SetPos(Vector2(200,300));
	player.Animation.Add("idle", 0, 0, 1.0);
	player.Animation.Add("walk", 8, 15, 10.0);
	player.Animation.Add("16", 16, 16, 8.0);
	player.Add();
	//Entity::EntityList.push_back(&player);
	//Entity::EntityList.push_back(&floor);
}

void CAppStateGame::OnDeactivate(){
	for(int i = 0;i < Entity::EntityList.size(); i++){
		if(!Entity::EntityList[i])continue;
		Entity::EntityList[i]->OnCleanup();
	}
	Entity::EntityList.clear();

	our_font.clean();
}

void CAppStateGame::OnLoop(){
	keys = SDL_GetKeyState( NULL );
	for(int i = 0;i < Entity::EntityList.size(); i++){
		if(!Entity::EntityList[i])continue;
		Entity::EntityList[i]->OnLoop(keys);
	}

	for(int i = 0; i < EntityCol::EntityColList.size(); i++){
		Entity* EntityA = EntityCol::EntityColList[i].EntityA;
		Entity* EntityB = EntityCol::EntityColList[i].EntityB;

		if(EntityA == NULL || EntityB == NULL)continue;

		if(EntityA->OnCollision(EntityB)){
			EntityB->OnCollision(EntityA);
		}

	}
	EntityCol::EntityColList.clear();

}

void CAppStateGame::OnRender(){
	for(int i = 0;i < Entity::EntityList.size(); i++){
		if(!Entity::EntityList[i])continue;
		Entity::EntityList[i]->OnRender();
	}

	char *test = "the quick brown fox\njumped over the lazy dog.\nYay this is on the last line now! :D";
	freetype::print(our_font, 200,200, test);
}

CAppStateGame* CAppStateGame::GetInstance(){
	return &Instance;
}