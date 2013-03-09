#ifndef _CPLAYER_H_
	#define _CPLAYER_H_

#include "Entity.h"

class CPlayer : public Entity {
public:
	CPlayer();
	CPlayer(Shashin t, float width, float height );
	bool OnLoad(char* File, float width, float height);
	void OnLoop(Uint8 *keys);

	void OnRender();
	void handleCollision(glm::vec2 pVec);
	void OnCleanup();
	void OnAnimate();
	bool OnCollision(Entity* Entity);
	virtual glm::vec2 getDimensions();
	Shashin texture;
	AnimControl Animation;
	//Sprite sprite;

	void setTexture(Shashin t);

};












#endif