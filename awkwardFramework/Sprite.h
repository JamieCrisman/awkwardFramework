#ifndef _SPRITE_H_
	#define _SPRITE_H_

#pragma once

#include <SDL_image.h>
#include <string>
#include <SDL_opengl.h>
#include "Transform.h"
#include <list>
#include "CFPS.h"
#include "AFTexture.h"

class CEntity;
class Sprite : public Transform{
public:
	Sprite(AFTexture &texture, float width=-1, float height=-1);
	Sprite();
	~Sprite();
	void Render(Vector2 p, float r, Vector2 s);
	void setTexture(AFTexture t);
	//void GetWidthHeight(int *width, int *height);
	AFTexture texture;
	float width, height;
	Vector2 textureOffset;
	Vector2 textureScale;
	float RGBA[3];
	//bool Load(const char *fileName, float width, float height);
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
	AnimControl(AFTexture &texture, float width, float height);
	void SetTexture(AFTexture &texture);
	void Add(const std::string &name, int start, int end, float speed);
	void Play(const std::string &name);
	void Stop(const std::string &name);
	Animation* GetAnimation(const std::string &name);
	void Render(Vector2 p, float r, Vector2 s);
	std::list<Animation> animations;
	Animation* anim;
	float fullWidth, fullHeight;

};


#endif