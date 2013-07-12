#ifndef _SPRITE_H_
	#define _SPRITE_H_

#pragma once

#include <SDL_image.h>
#include <string>
#include <SDL_opengl.h>
#include "../Util/Transform.h"
#include <list>
#include "../Util/CFPS.h"
#include "../Graphics/Shashin.h"
#include "../Core/Define.h"
//#include "Box2D\Box2D.h"

class Entity;
class Sprite : public Transform{
public:
	Sprite(Shashin &texture, float width=-1, float height=-1);
	Sprite(Shashin &texture, glm::vec2 offset, float width=-1, float height=-1);
	Sprite();
	~Sprite();
	void Render(glm::vec2 p, float r, glm::vec2 s);
	void setTexture(Shashin t);
	void setColor(float r, float g, float b);
	Shashin texture;
	float width, height;
	glm::vec2 getDimensions();
	void setDimensions(glm::vec2);
	glm::vec2 textureOffset;
	glm::vec2 textureScale;
	float RGB[3];
};

class Animation{
public:
	Animation(const std::string &name, int start, int end, float speed);
	Animation();
	bool isPlaying;
	const std::string name;
	float frame, speed;
	int start, end;
};

class AnimControl : public Sprite{
public:
	AnimControl();
	AnimControl(Shashin &texture, float width, float height);
	//void SetTexture(AFTexture &texture);
	void Add(const std::string &name, int start, int end, float speed);
	void Play(const std::string &name);
	//void Stop(const std::string &name);
	void Stop();
	void setTexture(Shashin t, float width, float height);
	void setTexture(Shashin t);
	Animation* GetAnimation(const std::string &name);
	void Render(glm::vec2 p, float r, glm::vec2 s);
	std::list<Animation> animations;
	Animation* anim;
	//float fullWidth, fullHeight;

};


#endif