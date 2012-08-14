#include "CAppStateGame.h"
#include "CAppStateManager.h"

CAppStateGame CAppStateGame::Instance;

CAppStateGame::CAppStateGame() : world(b2Vec2(0.0f, 10.0f)){

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

	//b2Vec2 gravity(0.0f, -10.0f);
	doSleep = true;
	//b2World world(gravity);
	world.SetAllowSleeping(doSleep);
	b2BodyDef groundBodyDef;

	groundBodyDef.position.Set(320.0f, 475.0f);

	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(140.0f, 10.0f);
	groundBodyDef.userData = floor.getThis();
	groundBody->CreateFixture(&groundBox,0.0f);
	floor.body = groundBody;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(320.0f, 4.0f);
	bodyDef.fixedRotation = true;
	b2Body* body = world.CreateBody(&bodyDef);
	//bodyDef.awake = true;
	bodyDef.userData = player.getThis();
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	
	body->CreateFixture(&fixtureDef);
	player.body = body;
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

	player.Animation.Add("idle", 0, 0, 1.0);
	player.Animation.Add("walk", 8, 15, 10.0);
	player.Animation.Add("16", 16, 16, 8.0);
	player.Add();
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

	world.Step((2.0f / 60.0f), 6, 2);
}

void CAppStateGame::OnRender(){
	for(int i = 0;i < CEntity::EntityList.size(); i++){
		if(!CEntity::EntityList[i])continue;
		CEntity::EntityList[i]->OnRender();
	}

	char *test = "the quick brown fox\n jumped over the lazy dog.\noh look another bug";
	freetype::print(our_font, 200,200, test);
}

CAppStateGame* CAppStateGame::GetInstance(){
	return &Instance;
}