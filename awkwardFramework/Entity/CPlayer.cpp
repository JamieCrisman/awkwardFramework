#include "CPlayer.h"


CPlayer::CPlayer(){
	Entity::Add();
}

CPlayer::CPlayer(Shashin t, float width, float height){
	sprite.texture.set(t);
	Width = width;
	Height = height;
	Entity::Add();
}

bool CPlayer::OnLoad(char* File, float width, float height){
	if(!texture.Load(File, width, height)){
		return false;
	}else{
		//Animation.SetTexture(texture);
	}
	return true;
}

void CPlayer::OnLoop(Uint8 *keys){

	float desiredVelX = 0;
	float baseSpeed = 30.0f;
	if(keys[SDLK_LEFT]){
		//SetPos(Vector2((getX() - 5.0), (getY())));
		Animation.Play("walk");
		if(scale.x > 0)
			scale.x *= -1;
		
		desiredVelX += -baseSpeed;
	}
	if(keys[SDLK_UP]){
		//SetPos(Vector2((getX()), (getY() - 5.0)));
		//player.body->SetTransform(b2Vec2(10.0f, 20.0f), 0.0f);
		//player.body->ApplyForce(b2Vec2(0.0f, 10.0f), b2Vec2(0.0f, 0.0f));
	}
	if(keys[SDLK_RIGHT]){
		//SetPos(Vector2((getX() + 5.0), (getY())));
		Animation.Play("walk");
		if(scale.x < 0)
			scale.x *= -1;

		desiredVelX += baseSpeed;
	}
	if(keys[SDLK_DOWN]){
		//SetPos(Vector2((getX()), (getY() + 5.0)));
	}
	//float deltaVelocity = desiredVelX - vel.x;
	//gradual
	/*
	case desiredVel = b2Max( vel.x - 0.1f, -5.0f ); break;
    case MS_STOP:  desiredVel = vel.x * 0.98f; break;
    case MS_RIGHT: desiredVel = b2Min( vel.x + 0.1f,  5.0f ); break;
	*/
	Entity::OnLoop(keys);

}

void CPlayer::OnRender(){
	Animation.Render(this->position, this->rotation, this->scale);
	//Animation.Render(this->body->GetPosition(), this->body->GetAngle(), this->scale);
}

void CPlayer::OnCleanup(){
	Entity::OnCleanup();
}

void CPlayer::OnAnimate(){

	Entity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity* Entity){
	return true;
}

void CPlayer::setTexture(Shashin t){
	Animation.setTexture(t);
}