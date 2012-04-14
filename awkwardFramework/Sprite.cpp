#pragma once

#include "Sprite.h"
//#include "CEntity.h"

Sprite::Sprite(AFTexture &texture, float width, float height){
	//if(!Load(fileName, width, height)){
		//if it fails to load do something
	//}
	this->texture = texture;
	width = 0.0f;
	height = 0.0f;
	textureOffset = Vector2::zero;
	textureScale = Vector2::one;
	float RGBA[4] = {1.0, 1.0, 1.0, 1.0};
}

Sprite::Sprite(){
	width = 0.0f;
	height = 0.0f;
	this->texture.GL_texture = NULL;
	textureOffset = Vector2::zero;
	textureScale = Vector2::one;
	float RGBA[4] = {1.0, 1.0, 1.0, 1.0};
}

Sprite::~Sprite(){
	//glDeleteTextures(1, &texture);
}


void Sprite::Render(CEntity *entity){
	if(texture.GL_texture == NULL)
		return;

	//CSurface::OnDraw(Surf_Display, Surf_Entity, X - CCamera::CameraControl.GetX(), Y - CCamera::CameraControl.GetY(), CurrentFrameCol * Width, (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height, Width, Height);
	glLoadIdentity();

	glBindTexture( GL_TEXTURE_2D, texture.GL_texture);
	//float posx = position.x + (width * 0.5f);
	//float posy = position.y (height * 0.5f);
	glTranslatef(position.x, position.y , 0.0f); //get entity position and add it to w and h
	glRotatef(rotation, 0,0,1);

	glPushMatrix();
		glTranslatef(-(width * 0.5f), -(height * 0.5f), 0); //allows rotation to occur at center rather than at top left
		glBegin(GL_QUADS);
			glTexCoord2i(0,0);
			glVertex3f(0, 0, 0);

			glTexCoord2i(1,0);
			glVertex3f(width, 0, 0);

			glTexCoord2i(1,1);
			glVertex3f(width, height, 0);

			glTexCoord2i(0,1);
			glVertex3f(0, height, 0);
		glEnd();
	glPopMatrix();
}

Animation::Animation(const std::string &name, int start, int end, float speed):
	name(name),
	isPlaying(false),
	frame(0),
	speed(speed),
	start(start),
	end(end){
}

AnimControl::AnimControl(AFTexture &texture, float width, float height) : Sprite(texture, width, height){
	
}

void AnimControl::Add(const std::string &name, int start, int end, float speed){
	Animation a = Animation(name, start, end, speed);
	animations.push_back(a);
}
void AnimControl::Play(const std::string &name){
	anim = GetAnimation(name);
	if(anim){
		anim->isPlaying = true;
	}
}
void AnimControl::Stop(const std::string &name){
	anim = GetAnimation(name);
	if(anim){
		anim->isPlaying = false;
	}
}

void AnimControl::Render(CEntity *entity)
{
	int x = 0;
	int y = 0;

	if(anim)
	{
		if(anim->isPlaying)
		{
			anim->frame += anim->speed * CFPS::FPSControl.GetSpeedFactor();
			if(anim->frame > anim->end + 1) { anim->frame = anim->start; }
		}
		x = (int) anim->frame % (int) (texture.width / width);
		y = (int) anim->frame / (texture.width / width);
	}
	textureOffset = Vector2((x * width) / texture.width, (y * height) / texture.height);
	textureScale = Vector2(width / texture.width, height / texture.height);

	Sprite::Render(entity);
}

Animation* AnimControl::GetAnimation(const std::string &name){
	for(std::list<Animation>::iterator i = animations.begin(); i != animations.end(); ++i){
		if(i->name == name){
			return &(*i);
		}
	}
	return NULL;
}