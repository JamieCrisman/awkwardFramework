#ifndef _SHASHIN_H_
	#define _SHASHIN_H_
#pragma once

#include <SDL_image.h>
#include <SDL_opengl.h>

class Shashin{
public:
	Shashin();
	Shashin(const char *fileName, float width, float height);
	~Shashin();
	GLuint GL_texture;
	float textureWidth, textureHeight;
	void set(Shashin *t);
	bool Load(const char *fileName);
	Shashin *getThis();
};

#endif