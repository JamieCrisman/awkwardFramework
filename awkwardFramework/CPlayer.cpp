#include "CPlayer.h"


CPlayer::CPlayer(){

}

bool CPlayer::OnLoad(char* File, float width, float height, int MaxFrames){
	if(CEntity::OnLoad(File, width, height, MaxFrames) == false){
		return false;
	}
	return true;
}

void CPlayer::OnLoop(){
	CEntity::OnLoop();
}

void CPlayer::OnRender(SDL_Surface* Surf_Display){
	CEntity::OnRender();
}

void CPlayer::OnCleanup(){
	CEntity::OnCleanup();
}

void CPlayer::OnAnimate(){
	if(SpeedX != 0){
	//	Anim_Control.MaxFrames = 8;
	}else{
	//	Anim_Control.MaxFrames = 0;
	}
	CEntity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity* Entity){
	return true;
}
