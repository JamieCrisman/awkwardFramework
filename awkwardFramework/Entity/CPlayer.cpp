#include "CPlayer.h"
#include "Collider\Collider.h"

CPlayer::CPlayer(){
	Entity::Add();
	sY, aY, sX, aX = 0.0f;
}

CPlayer::CPlayer(Shashin *t, float width, float height){
	//sprite.texture.set(t);
	graphic->setTexture(t);
	Width = width;
	Height = height;
	collider = new BlockCollider(getThis());
	sY, aY, sX, aX = 0.0f;
	Entity::Add();
}

void CPlayer::setDimensions(glm::vec2 dim){
	Width = dim.x;
	Height = dim.y;
	//Animation.setDimensions(dim);
}

bool CPlayer::OnLoad(char* File, float width, float height){
	if(!texture.Load(File)){
		return false;
	}else{
		//Animation.SetTexture(texture);
	}
	return true;
}

void CPlayer::OnLoop(Uint8 *keys){
	float maxXAccel = 4.0f;
	float maxYAccel = 4.0f;
	float maxXVel = 20.0f;
	float maxYVel = 50.0f;
	float accelRate = 4.0f;
	float jumpSpeed = GRAVITY + 5.0f;
	//decreases acceleration
	sX = sX * 0.5;
	sY = sY * 0.5;
	//just clean it up if it's less than 1
	sX = (glm::abs(sX) < 1.0)? 0 : sX;
	sY = (glm::abs(sY) < 1.0)? 0 : sY;

	if(keys[SDLK_LEFT]){
		//SetPos(glm::vec2(position.x - 5.0, (position.y)));
		//Animation.Play("walk");
		if(scale.x > 0)
			scale.x *= -1;

		sX -= accelRate * CFPS::FPSControl.GetSpeedFactor();
		
	}
	if(keys[SDLK_UP]){
		sY -= jumpSpeed * CFPS::FPSControl.GetSpeedFactor();
	}
	if(keys[SDLK_RIGHT]){
		//SetPos(glm::vec2((position.x + 5.0), (position.y)));
		//Animation.Play("walk");
		if(scale.x < 0)
			scale.x *= -1;

		sX += accelRate * CFPS::FPSControl.GetSpeedFactor();
	}
	if(keys[SDLK_DOWN]){
		sY += accelRate * CFPS::FPSControl.GetSpeedFactor();
	}
	//sY += GRAVITY * CFPS::FPSControl.GetSpeedFactor();

	sX = (sX < maxXVel)? sX : maxXVel;
	sX = (sX > -maxXVel)? sX : -maxXVel;
	sY = (sY < maxYVel)? sY : maxYVel;
	sY = (sY > -maxYVel)? sY : -maxYVel;
	
	SetPos(glm::vec2(position.x + sX, position.y+ sY));
	Entity::OnLoop(keys);

}

void CPlayer::OnCleanup(){
	Entity::OnCleanup();
}

void CPlayer::OnAnimate(){

	Entity::OnAnimate();
}

void CPlayer::handleCollision(std::vector<glm::vec2> pVec){
	//SetPos(getPosition() + pVec);
	float tX = 0, tY = 0; //total x/y
	for(int i = 0; i < pVec.size(); i++){
		if(pVec[i].x == 0 && pVec[i].y == 0)
			continue;
		
		if(glm::abs(pVec[i].x) < glm::abs(pVec[i].y)){
			tX += pVec[i].x;
		}else{
			tY += pVec[i].y;
		}
		
	}
	SetPos(glm::vec2(position.x + tX, position.y + tY));
	
}


bool CPlayer::OnCollision(Entity* Entity){
	return true;
}
