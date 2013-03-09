#include "CPlayer.h"
#include "Collider\Collider.h"

CPlayer::CPlayer(){
	Entity::Add();
}

CPlayer::CPlayer(Shashin t, float width, float height){
	sprite.texture.set(t);
	Width = width;
	Height = height;
	collider = new BlockCollider(getThis());
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
		SetPos(glm::vec2(position.x - 5.0, (position.y)));
		Animation.Play("walk");
		if(scale.x > 0)
			scale.x *= -1;
		
		desiredVelX += -baseSpeed;
	}
	if(keys[SDLK_UP]){
		SetPos(glm::vec2(position.x, (position.y - 5.0)));
		//player.body->SetTransform(b2Vec2(10.0f, 20.0f), 0.0f);
		//player.body->ApplyForce(b2Vec2(0.0f, 10.0f), b2Vec2(0.0f, 0.0f));
	}
	if(keys[SDLK_RIGHT]){
		SetPos(glm::vec2((position.x + 5.0), (position.y)));
		Animation.Play("walk");
		if(scale.x < 0)
			scale.x *= -1;

		desiredVelX += baseSpeed;
	}
	if(keys[SDLK_DOWN]){
		SetPos(glm::vec2((position.x), (position.y + 5.0)));
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
glm::vec2 CPlayer::getDimensions(){
	return Animation.getDimensions();
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

void CPlayer::handleCollision(glm::vec2 pVec){
	SetPos(getPosition() + pVec);
}


bool CPlayer::OnCollision(Entity* Entity){
	return true;
}

void CPlayer::setTexture(Shashin t){
	Animation.setTexture(t);
}