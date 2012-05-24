#include "CPlayer.h"


CPlayer::CPlayer(){
	//texture.GL_texture = NULL;
	//sprite.texture.GL_texture = NULL;
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

void CPlayer::OnLoop(Uint8 *keys){
	/*
	if(keys[SDLK_LEFT]){
		SetPos(Vector2((getX() - 5.0), (getY())));
	}
	if(keys[SDLK_UP]){
		SetPos(Vector2((getX()), (getY() - 5.0)));
	}
	if(keys[SDLK_RIGHT]){
		SetPos(Vector2((getX() + 5.0), (getY())));
	}
	if(keys[SDLK_DOWN]){
		SetPos(Vector2((getX()), (getY() + 5.0)));
	}
	*/
	CEntity::OnLoop(keys);

}

void CPlayer::OnRender(){
	//Animation.Render(this);
	Animation.Render(this->position, this->rotation, this->scale);
}

void CPlayer::OnCleanup(){
	CEntity::OnCleanup();
}

void CPlayer::OnAnimate(){
//	if(SpeedX != 0){
	//	Anim_Control.MaxFrames = 8;
//	}else{
	//	Anim_Control.MaxFrames = 0;
//	}
	CEntity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity* Entity){
	return true;
}

void CPlayer::setTexture(AFTexture t){
	//texture.set(t);
	//sprite.setTexture(t);
	Animation.setTexture(t);

}