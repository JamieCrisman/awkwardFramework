#include "CPlayer.h"


CPlayer::CPlayer(){
	CEntity::Add();
}

CPlayer::CPlayer(AFTexture t, float width, float height){
	sprite.texture.set(t);
	Width = width;
	Height = height;
	CEntity::Add();
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

	b2Vec2 vel = body->GetLinearVelocity();
	float desiredVelX = 0;
	if(keys[SDLK_LEFT]){
		SetPos(Vector2((getX() - 5.0), (getY())));
		Animation.Play("walk");
		if(scale.x > 0)
			scale.x *= -1;
		
		desiredVelX = -5;
	}
	if(keys[SDLK_UP]){
		SetPos(Vector2((getX()), (getY() - 5.0)));
		//player.body->SetTransform(b2Vec2(10.0f, 20.0f), 0.0f);
		//player.body->ApplyForce(b2Vec2(0.0f, 10.0f), b2Vec2(0.0f, 0.0f));
	}
	if(keys[SDLK_RIGHT]){
		SetPos(Vector2((getX() + 5.0), (getY())));
		Animation.Play("walk");
		if(scale.x < 0)
			scale.x *= -1;

		desiredVelX = 5;
	}
	if(keys[SDLK_DOWN]){
		SetPos(Vector2((getX()), (getY() + 5.0)));
	}
	float deltaVelocity = desiredVelX - vel.x;
	float impulse = body->GetMass() * deltaVelocity;
	body->ApplyLinearImpulse(b2Vec2(impulse, 0.0f), body->GetWorldCenter());

	//gradual
	/*
	case desiredVel = b2Max( vel.x - 0.1f, -5.0f ); break;
    case MS_STOP:  desiredVel = vel.x * 0.98f; break;
    case MS_RIGHT: desiredVel = b2Min( vel.x + 0.1f,  5.0f ); break;
	*/
	CEntity::OnLoop(keys);

}

void CPlayer::OnRender(){
	//Animation.Render(this->position, this->rotation, this->scale);
	//Animation.Render(this->body->GetPosition(), this->rotation, this->scale);
	Animation.Render(this->body->GetPosition(), this->rotation, this->scale);
}

void CPlayer::OnCleanup(){
	CEntity::OnCleanup();
}

void CPlayer::OnAnimate(){

	CEntity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity* Entity){
	return true;
}

void CPlayer::setTexture(AFTexture t){
	Animation.setTexture(t);
}