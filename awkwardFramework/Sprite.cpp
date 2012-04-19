#pragma once

#include "Sprite.h"
//#include "CEntity.h"

Sprite::Sprite(AFTexture &texture, float width, float height){
	//if(!Load(fileName, width, height)){
		//if it fails to load do something
	//}
	this->texture = texture;
	//width = 0.0f;
	//height = 0.0f;
	width = texture.width;
	height = texture.height;
	textureOffset = Vector2(0, 0);
	textureScale = Vector2(1.0, 1.0);
	RGB[0] = 1.0;
	RGB[1] = 1.0;
	RGB[2] = 1.0;
}

Sprite::Sprite(){
	width = 0.0f;
	height = 0.0f;
	this->texture.GL_texture = NULL;
	textureOffset = Vector2(0, 0);
	textureScale = Vector2(1.0, 1.0);
	RGB[0] = 1.0;
	RGB[1] = 1.0;
	RGB[2] = 1.0;
}

void Sprite::setTexture(AFTexture t){
	width = t.width;
	height = t.height;
	texture.set(t);
}

void Sprite::setColor(float r, float g, float b){
	RGB[0] = r;
	RGB[1] = g;
	RGB[2] = b;
	
}

Sprite::~Sprite(){
	//glDeleteTextures(1, &texture);
}


void Sprite::Render(Vector2 p, float r, Vector2 s){
	if(texture.GL_texture == NULL)
		return;
	
	//old
	//CSurface::OnDraw(Surf_Display, Surf_Entity, X - CCamera::CameraControl.GetX(), Y - CCamera::CameraControl.GetY(), CurrentFrameCol * Width, (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height, Width, Height);
	
	glLoadIdentity();
	//glBindTexture( GL_TEXTURE_2D, texture.GL_texture);
	//no idea
	//glScalef(s.x, s.y, 1.0);
	//glTranslatef(p.x, p.y , 0.0f); //get entity position and add it to w and h
	
	/*glBegin(GL_QUADS);
        glTexCoord2i(0,0); glVertex3f(0, 0, 0);
        glTexCoord2i(1,0);glColor3f(1, 1, 0); glVertex3f(width, 0, 0);
        glTexCoord2i(1,1);glColor3f(1, 0, 1); glVertex3f(width, height, 0);
        glTexCoord2i(0,1);glColor3f(1, 1, 1); glVertex3f(0, height, 0);
    glEnd();
	*/
	float halfWidth = width*0.5f*s.x;
	float halfHeight = height*0.5f*s.y;
	if(r != 0.0){ //no idea how much this will actually trim off but lettuce try it.
		glTranslatef((p.x), (p.y), 0); //allows rotation to occur at center rather than at top left
		glRotatef(r, 0,0, 1.0);
		glTranslatef(-(p.x), -(p.y), 0); //allows rotation to occur at center rather than at top left
	}
	//renders a quad
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
		glBegin(GL_QUADS);
			// bottom left
			glColor3f(RGB[0], RGB[1], RGB[2]);
			glTexCoord2f(textureOffset.x, textureOffset.y + textureScale.y);
			glVertex3f(-halfWidth + p.x, halfHeight + p.y, 0.0f);


			// top left
			glTexCoord2f(textureOffset.x, textureOffset.y);
			glColor3f(RGB[0], RGB[1], RGB[2]);
			glVertex3f(-halfWidth + p.x, -halfHeight + p.y, 0.0f);

			// top right
			glTexCoord2f(textureOffset.x + textureScale.x, textureOffset.y);
			glColor3f(RGB[0], RGB[1], RGB[2]);
			glVertex3f(halfWidth + p.x, -halfHeight + p.y, 0.0f);

			// bottom right
			glTexCoord2f(textureOffset.x + textureScale.x, textureOffset.y + textureScale.y);
			glColor3f(RGB[0], RGB[1], RGB[2]);
			glVertex3f(halfWidth + p.x, halfHeight + p.y, 0.0f);
			
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
	//this->texture.width = width;
	//this->texture.width = width;
}

AnimControl::AnimControl() : Sprite(){
	
}

void AnimControl::setTexture(AFTexture t, float width, float height){
	this->width = width;
	this->height = height;
	this->texture.set(t);
}
void AnimControl::setTexture(AFTexture t){
	//this->width = width;
	//this->height = height;
	Sprite::setTexture(t);
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

void AnimControl::Render(Vector2 p, float r, Vector2 s)
{
	int x = 0;
	int y = 0;

	if(anim)
	{
		if(anim->isPlaying)
		{
			anim->frame += anim->speed * CFPS::FPSControl.GetDeltaTime();
			if(anim->frame > anim->end + 1) { anim->frame = anim->start; }
		}
		x = (int) anim->frame % (int) (texture.width / width);
		y = (int) anim->frame / (texture.width / width);
	}
	textureOffset = Vector2((x * width) / texture.width, (y * height) / texture.height);
	textureScale = Vector2(width / texture.width, height / texture.height);

	Sprite::Render(p, r, s);
}

Animation* AnimControl::GetAnimation(const std::string &name){
	for(std::list<Animation>::iterator i = animations.begin(); i != animations.end(); ++i){
		if(i->name == name){
			return &(*i);
		}
	}
	return NULL;
}