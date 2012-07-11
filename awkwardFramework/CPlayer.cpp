#include "CPlayer.h"


CPlayer::CPlayer(){
	Add();
}

CPlayer::CPlayer(AFTexture t, float width, float height){
	sprite.texture.set(t);
	Width = width;
	Height = height;
	Add();
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


	CEntity::OnLoop(keys);

}

void CPlayer::OnRender(){
	Animation.Render(this->position, this->rotation, this->scale);
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