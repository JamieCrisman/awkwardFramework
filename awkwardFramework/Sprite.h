#pragma once

#include <SDL_image.h>
#include <string>
#include <SDL_opengl.h>
#include "Vector2.h"

class Entity;
class Sprite{
public:
	Sprite(const char *fileName, float width=-1, float height=-1);
	Sprite();
	~Sprite();
	void Render();
	//void GetWidthHeight(int *width, int *height);
	GLuint texture;
	float width, height, rotation;
	Vector2 textureOffset;
	Vector2 textureScale;
	bool Load(const char *fileName, float width, float height);

};