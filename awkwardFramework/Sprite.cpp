#pragma once

#include "Sprite.h"
#include "CEntity.h"

Sprite::Sprite(const char *fileName, float width, float height){
	if(!Load(fileName, width, height)){
		//if it fails to load do something
	}
	rotation = 0.0f;

}

Sprite::Sprite(){
	width = 0.0f;
	height = 0.0f;
	rotation = 0.0f;

	texture = NULL;
	textureOffset = Vector2::zero;
	textureScale = Vector2::one;

}

bool Sprite::Load(const char *fileName, float width=-1, float height=-1){
	SDL_Surface *textureTest;
	GLenum texture_format;
	GLint nOfColors;

	if((textureTest = IMG_Load(fileName) )){
		nOfColors = textureTest->format->BytesPerPixel;
		if(nOfColors == 4){
			if(textureTest->format->Rmask == 0x000000ff){
				texture_format = GL_RGBA;
			}else
				texture_format = GL_BGRA;
		}else if(nOfColors == 3){
			if(textureTest->format->Rmask == 0x000000ff){
				texture_format = GL_RGB;
			}else
				texture_format = GL_BGR;
		}else{
			//not true color, guess just not use it?
			return false;
		}
		//generate obj and bind
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		//stretch properties
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, nOfColors, textureTest->w, textureTest->h,0, texture_format, GL_UNSIGNED_BYTE, textureTest->pixels);
		this->width = width;
		this->height = height;
	
	}else{
		return false;
	}
	//don't actually use it after this point
	if(textureTest){
		SDL_FreeSurface(textureTest);
	}
	return true;

}