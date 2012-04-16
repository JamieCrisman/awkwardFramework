#include "CPlayer.h"


CPlayer::CPlayer(){
	//texture.GL_texture = NULL;
	sprite.texture.GL_texture = NULL;
}

CPlayer::CPlayer(AFTexture t, float width, float height){
	sprite.texture.set(t);
	Width = width;
	Height = height;
}

bool CPlayer::OnLoad(char* File, float width, float height){
	if(!texture.Load(File, width, height)){
		return false;
	}else{
		//Animation.SetTexture(texture);
	}
	return true;
}

void CPlayer::OnLoop(){
	CEntity::OnLoop();
}

void CPlayer::OnRender(){
	//Animation.Render(this);
	sprite.Render(this);
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

void CPlayer::setTexture(AFTexture t){
	//texture.set(t);
	sprite.setTexture(t);
}