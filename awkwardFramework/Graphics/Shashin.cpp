//shashin means picture in japanese :D
//using as base file of images. sets it up as a GL_texture

#include "Shashin.h"

Shashin::Shashin(const char *fileName, float width=-1, float height=-1){
	Load(fileName);
}
Shashin::Shashin(){
	GL_texture = NULL;
	textureWidth = 0;
	textureHeight = 0;
}

void Shashin::set(Shashin *t){
	GL_texture = t->GL_texture;
	textureWidth = t->textureWidth;
	textureWidth = t->textureWidth;
}

Shashin::~Shashin(){
	glDeleteTextures(1, &GL_texture);
}
bool Shashin::Load(const char *fileName){
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
		glGenTextures(1, &GL_texture);
		glBindTexture(GL_TEXTURE_2D, GL_texture);

		//stretch properties
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, nOfColors, textureTest->w, textureTest->h,0, texture_format, GL_UNSIGNED_BYTE, textureTest->pixels);
		textureWidth = textureTest->w;
		textureHeight = textureTest->h;
	
	}else{
		GL_texture = NULL;
		return false;
	}
	//don't actually use it after this point
	if(textureTest){
		SDL_FreeSurface(textureTest);
	}
	return true;

}

Shashin *Shashin::getThis(){
	return this;
}