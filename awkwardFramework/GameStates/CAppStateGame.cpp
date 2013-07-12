#include "CAppStateGame.h"
#include "CAppStateManager.h"
#define NO_STDIO_REDIRECT

CAppStateGame CAppStateGame::Instance;
Quadtree CAppStateGame::QTree = Quadtree(0, WWIDTH, 0, WHEIGHT);

CAppStateGame::CAppStateGame(){
}

void CAppStateGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){
	switch(sym){
		case SDLK_1: {
			CAppStateManager::SetActiveAppState(APPSTATE_INTRO);
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			SDL_GetMouseState(&mousex, &mousey);
			break;						  
		}
		default:{
		}
	}

}
void CAppStateGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode){
	//player.Animation.Play("idle");
}

void CAppStateGame::OnActivate(){
	SDL_WM_SetCaption("Game State", NULL);

	//player.body->GetPosition();
	our_font.init("Assets/Fonts/Arial.ttf",16);

	/*if( !texture.Load("Assets/Images/Sprites/placeholder_player.png", 256, 64) ){
		return;
	}*/

	/*floor.Load("Assets/Images/World/placeholder_grass.png", 640, 30, glm::vec2(0, 450));
	floor.Add();
	*/
	//player.Animation.setTexture(texture, 32, 32);
	player.setDimensions(glm::vec2(32, 32));
	/*for(int zz = 0; zz < 10; zz++){
		block[zz].Load("Assets/Images/World/block.png", 32, 32, glm::vec2(40 * (zz+1) + 40, 418));
		block[zz].Add();
		block[zz].setCollider(COLLIDER_TYPE_SQUARE);
	}
	*/

	//player.Animation.setColor(1.0, 1.0, 1.0);
	//floor.setCollider(COLLIDER_TYPE_SQUARE);

	//LOOK HERE
	//
	// MAKE IT SO IT WON'T RENDER IF THERE'S NO POINTER TO GRAPHIC IN ENTITY
	//
	//


	player.SetPos(glm::vec2(0,0));
	player.setOffset(glm::vec4(12.0f, 4.0f, 12.0f, 0.0f));
	player.setCollider(COLLIDER_TYPE_SQUARE);
	player.Add();
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
		QTree.AddObject(Entity::EntityList[i]->getCollider());
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
	for(int i = 0; i < Entity::EntityList.size(); i++){
		vector<Collider*> Objs = QTree.GetObjectsAt(Entity::EntityList[i]->getPosition().x, Entity::EntityList[i]->getPosition().y);
		if(Entity::EntityList[i]->getCollider() == nullptr){
			continue;
		}
		vector<glm::vec2> pierce;
		for(int q = 0; q < Objs.size(); q++){
			if(Entity::EntityList[i]->getCollider() == Objs[q]){ //don't check yourself
				continue;
			}else{
				glm::vec2 t = CP.CheckCollision(Entity::EntityList[i]->getCollider(), Objs[q]);
				if(t.x != 0 || t.y != 0){
					pierce.push_back(t);
				}
			}
		}
		if(pierce.size() > 0)
			Entity::EntityList[i]->handleCollision(pierce);///TODO MAKE HANDLE COLLISION TAKE ALL THE COLLISIONS
	}
	QTree.Clear();

	//CP.CheckCollision(player.getCollider(), floor.getCollider());
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
	//sprintf(tttt, "%.4g", player.getCollider()->getPosition().x ); 
	//test += "\nCollider X: ";// + posx;// +"\njumped over the lazy dog.\nYay this is on the last line now! :D";
	//test += tttt;
	sprintf(tttt, "%.4g", CFPS::FPSControl.GetSpeedFactor() ); 
	test2 = "SP FACT: ";// + posx;// +"\njumped over the lazy dog.\nYay this is on the last line now! :D";
	test += "\n"+test2 + tttt;
	delete tttt;
	//char *beep = test << posx;
	freetype::print(our_font, 200,200, test.c_str());
}

CAppStateGame* CAppStateGame::GetInstance(){
	return &Instance;
}