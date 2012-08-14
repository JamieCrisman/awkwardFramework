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
#include "Define.h"
#include "Box2D\Box2D.h"

class CEntity;
class Sprite : public Transform{
public:
	Sprite(AFTexture &texture, float width=-1, float height=-1);
	Sprite(AFTexture &texture, Vector2 offset, float width=-1, float height=-1);
	Sprite();
	~Sprite();
	void Render(Vector2 p, float r, Vector2 s);
	void Render(b2Vec2 p, float r, Vector2 s);
	void setTexture(AFTexture t);
	void setColor(float r, float g, float b);
	AFTexture texture;
	float width, height;
	Vector2 textureOffset;
	Vector2 textureScale;
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
	AnimControl(AFTexture &texture, float width, float height);
	//void SetTexture(AFTexture &texture);
	void Add(const std::string &name, int start, int end, float speed);
	void Play(const std::string &name);
	//void Stop(const std::string &name);
	void Stop();
	void setTexture(AFTexture t, float width, float height);
	void setTexture(AFTexture t);
	Animation* GetAnimation(const std::string &name);
	void Render(Vector2 p, float r, Vector2 s);
	void Render(b2Vec2 p, float r, Vector2 s);
	std::list<Animation> animations;
	Animation* anim;
	//float fullWidth, fullHeight;

};


#endif