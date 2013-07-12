#ifndef _GRAPHIC_H_
	#define _GRAPHIC_H_
#pragma once

//#include <SDL_image.h>
//#include <string>
#include <SDL_opengl.h>
//#include <list>
#include "../Util/CFPS.h"
#include "../Entity/Entity.h"
#include "../Core/Define.h"
#include "Shashin.h"

class Entity;
class Graphic{
public:
	Graphic();
	Graphic(Entity *e);
	~Graphic();
	void setColor(int R, int G, int B);
	int *getColor();
	void setTexture(Shashin *txtr);
	Shashin *getTexture();
	void render();
	glm::vec2 getFrameDimensions();
	void setFrame(float fWidth, float fHeight);
	Graphic *getThis();
private:
	Shashin *texture;
	Entity *entity;
	//frame of sprite, defaults to texture w/h, is referenced for rendering
	float frameWidth, frameHeight;
	//frame offset is the xy on the spritesheet
	//frame scale is for scaling the texture for GL
	glm::vec2 frameOffset, frameScale;
	int RGB[3]; //defaults 255,255,255

};


#endif