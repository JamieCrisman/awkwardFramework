#ifndef _SHASHIN_H_
	#define _SHASHIN_H_
#pragma once

#include <SDL_image.h>
#include <SDL_opengl.h>
#include "../Util/Transform.h"

class Shashin{
public:
	Shashin();
	Shashin(const char *fileName, float width, float height);
	GLuint GL_texture;
	float width, height;
	bool Load(const char *fileName, float width, float height);
	void set(Shashin t);
};

#endif