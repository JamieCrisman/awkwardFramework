#include "CAppStateGame.h"
#include "CAppStateManager.h"
#define NO_STDIO_REDIRECT

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

	floor.Load("Assets/Images/World/placeholder_grass.png", 140, 10, glm::vec2(400, 100));
	floor.Add();
	//floor.scale.x = 1.0;
	//floor.scale.y = 1.0;
	player.Animation.setTexture(texture, 32, 32);

	player.Animation.setColor(1.0, 1.0, 1.0);
	floor.setCollider(COLLIDER_TYPE_SQUARE, floor.getDimensions(), glm::vec4(0.0f, 0.0f, 0.0f, 0.0f));
	//player.SetPos(Vector2(1, 1));
	
	//player.scale.x = 2.0;
	//player.scale.y = 2.0;

	//b2BodyDef Pbody;

	//Pbody.userData = player.getThis();
	//Pbody.position.Set(1, 2);
	//Pbody.fixedRotation = true;

	//b2Body* dbody = world.CreateBody(&Pbody);
	//player.body = dbody;
	player.SetPos(glm::vec2(0,0));
	player.Animation.Add("idle", 0, 0, 1.0);
	player.Animation.Add("walk", 8, 15, 10.0);
	player.Animation.Add("16", 16, 16, 8.0);
	player.setCollider(COLLIDER_TYPE_SQUARE, player.getDimensions(), glm::vec4(12.0f, 4.0f, 12.0f, 0.0f));
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
	/*
	for(int i = 0; i < EntityCol::EntityColList.size(); i++){
		Entity* EntityA = EntityCol::EntityColList[i].EntityA;
		Entity* EntityB = EntityCol::EntityColList[i].EntityB;

		if(EntityA == NULL || EntityB == NULL)continue;

		if(EntityA->OnCollision(EntityB)){
			EntityB->OnCollision(EntityA);
		}

	}
	EntityCol::EntityColList.clear();
	*/
	CP.CheckCollision(player.getCollider(), floor.getCollider());
}

void CAppStateGame::OnRender(){
	for(int i = 0;i < Entity::EntityList.size(); i++){
		if(!Entity::EntityList[i])continue;
		Entity::EntityList[i]->OnRender();
	}
	std::string test,test2;
	//char x = player.getX();
	char* tttt = new char[30];
	sprintf(tttt, "%.4g", player.getPosition().x ); 
	test = "Player X: ";// + posx;// +"\njumped over the lazy dog.\nYay this is on the last line now! :D";
	test += tttt;
	sprintf(tttt, "%.4g", player.getPosition().y ); 
	test2 = "Player Y: ";// + posx;// +"\njumped over the lazy dog.\nYay this is on the last line now! :D";
	test += "\n"+test2 + tttt;
	sprintf(tttt, "%.4g", player.getCollider()->getPosition().x ); 
	test += "\nCollider X: ";// + posx;// +"\njumped over the lazy dog.\nYay this is on the last line now! :D";
	test += tttt;
	sprintf(tttt, "%.4g", player.getCollider()->getPosition().y ); 
	test2 = "Collider Y: ";// + posx;// +"\njumped over the lazy dog.\nYay this is on the last line now! :D";
	test += "\n"+test2 + tttt;
	delete tttt;
	//char *beep = test << posx;
	freetype::print(our_font, 200,200, test.c_str());
}

CAppStateGame* CAppStateGame::GetInstance(){
	return &Instance;
}