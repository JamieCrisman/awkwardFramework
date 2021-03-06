#pragma once

#include "../Graphics/Sprite.h"
#include <cmath>

Sprite::Sprite(Shashin &texture, float width, float height){
	this->texture = texture;
	width = texture.textureWidth;
	height = texture.textureHeight;
	textureOffset = glm::vec2(0.0f, 0.0f);
	textureScale = glm::vec2(1.0f, 1.0f);
	RGB[0] = 1.0;
	RGB[1] = 1.0;
	RGB[2] = 1.0;
}

//need one with textureoffset for static sprites that share a sheet
Sprite::Sprite(Shashin &texture, glm::vec2 offset, float width, float height){
	this->texture = texture;
	width = texture.textureWidth;
	height = texture.textureHeight;
	textureOffset = offset;
	textureScale = glm::vec2(1.0f, 1.0f);
	RGB[0] = 1.0;
	RGB[1] = 1.0;
	RGB[2] = 1.0;
}


Sprite::Sprite(){
	width = 0.0f;
	height = 0.0f;
	this->texture.GL_texture = NULL;
	textureOffset = glm::vec2(0.0f, 0.0f);
	textureScale = glm::vec2(1.0f, 1.0f);
	RGB[0] = 1.0;
	RGB[1] = 1.0;
	RGB[2] = 1.0;
}

void Sprite::setTexture(Shashin t){
	width = t.textureWidth;
	height = t.textureHeight;
	texture.set(t.getThis());
}

glm::vec2 Sprite::getDimensions(){
	return glm::vec2(this->width * this->scale.x, this->height * this->scale.y);
}

void Sprite::setColor(float r, float g, float b){
	RGB[0] = r;
	RGB[1] = g;
	RGB[2] = b;
	
}

void Sprite::setDimensions(glm::vec2 dim){
	width = dim.x;
	height = dim.y;
}

Sprite::~Sprite(){
	glDeleteTextures(1, &texture.GL_texture);
}

//r (rotation) should come in as a radian, but GL uses degree
void Sprite::Render(glm::vec2 p, float r, glm::vec2 s){
	bool hasTexture = (texture.GL_texture != NULL);
	
	r = r * (180/(4.0*atan(1.0)));
	glLoadIdentity();
	glBindTexture( GL_TEXTURE_2D, texture.GL_texture);
	float w = width*s.x;
	float h = height*s.y;
	if(s.x < 0){
		p.x += width * glm::abs(s.x);
	}

	if(r != 0.0){ //no idea how much this will actually trim off but lettuce try it.
		glTranslatef((p.x), (p.y), 0); //allows rotation to occur at center rather than at top left
		glRotatef(r, 0,0, 1.0);
		glTranslatef(-(p.x), -(p.y), 0); //allows rotation to occur at center rather than at top left
	}
	//renders a quad
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	if(hasTexture){
		glBegin(GL_QUADS);
			// bottom left
			glColor3f(RGB[0], RGB[1], RGB[2]);
			glTexCoord2f(textureOffset.x, textureOffset.y + textureScale.y);
			glVertex3f(p.x, h + p.y, 0.0f);
			

			// top left
			glTexCoord2f(textureOffset.x, textureOffset.y);
			glColor3f(RGB[0], RGB[1], RGB[2]);
			glVertex3f(p.x, p.y, 0.0f);

			// top right
			glTexCoord2f(textureOffset.x + textureScale.x, textureOffset.y);
			glColor3f(RGB[0], RGB[1], RGB[2]);
			glVertex3f(w + p.x, p.y, 0.0f);

			// bottom right
			glTexCoord2f(textureOffset.x + textureScale.x, textureOffset.y + textureScale.y);
			glColor3f(RGB[0], RGB[1], RGB[2]);
			glVertex3f(w + p.x, h + p.y, 0.0f);
			
		glEnd();
	}
	if(!hasTexture){ //|| debugmode == true
		glColor3f( RGB[0], RGB[1], RGB[2] );
		glBegin(GL_QUADS);
			// bottom left
			glVertex3f(p.x, h + p.y, 0.0f);

			// top left
			glVertex3f(p.x, p.y, 0.0f);

			// top right
			glVertex3f(w + p.x, p.y, 0.0f);

			// bottom right
			glVertex3f(w + p.x, h + p.y, 0.0f);
			
		glEnd();
	}
	glPopMatrix();
	

}


Animation::Animation(const std::string &name, int start, int end, float speed):
	name(name),
	isPlaying(false),
	frame(start),
	speed(speed),
	start(start),
	end(end){
}

AnimControl::AnimControl(Shashin &texture, float width, float height) : Sprite(texture, width, height){
	//this->texture.width = width;
	//this->texture.width = width;
}

AnimControl::AnimControl() : Sprite(){
	
}

void AnimControl::setTexture(Shashin t, float width, float height){
	this->width = width;
	this->height = height;
	this->texture.set(t.getThis());
}
void AnimControl::setTexture(Shashin t){
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
//void AnimControl::Stop(const std::string &name){ //why do I need to know what the name is?
void AnimControl::Stop(){
	//anim = GetAnimation(name);
	if(anim->isPlaying){
		anim->isPlaying = false;
	}
}

void AnimControl::Render(glm::vec2 p, float r, glm::vec2 s)
{
	int x = 0;
	int y = 0;

	if(anim)
	{
		if(anim->isPlaying)
		{
			anim->frame += anim->speed * CFPS::FPSControl.GetDeltaTime();
			if(anim->frame > anim->end) { anim->frame = anim->start; }
		}
		x = (int) anim->frame % (int) (texture.textureWidth / width);
		y = (int) anim->frame / (texture.textureWidth / width);
	}
	textureOffset = glm::vec2((x * width) / texture.textureWidth, (y * height) / texture.textureHeight);
	textureScale = glm::vec2(width / texture.textureWidth, height / texture.textureHeight);

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
