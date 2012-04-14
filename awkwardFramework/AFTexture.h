#ifndef _AFTEXTURE_H_
	#define _AFTEXTURE_H_
#pragma once

#include <SDL_image.h>
#include <SDL_opengl.h>
#include "Transform.h"

class AFTexture : public Transform{
public:
	AFTexture();
	AFTexture(const char *fileName, float width, float height);
	GLuint GL_texture;
	float width, height;
	bool Load(const char *fileName, float width, float height);
};

#endif