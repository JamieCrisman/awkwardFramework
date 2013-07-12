#ifndef _CPLAYER_H_
	#define _CPLAYER_H_

#include "Entity.h"

class CPlayer : public Entity {
private:
	float aY, aX;
	float sY, sX;
public:
	CPlayer();
	CPlayer(Shashin* t, float width, float height );
	bool OnLoad(char* File, float width, float height);
	void OnLoop(Uint8 *keys);
	void setDimensions(glm::vec2 dim);
	void handleCollision(std::vector<glm::vec2> pVecs);
	void OnCleanup();
	void OnAnimate();
	bool OnCollision(Entity* Entity);
	Shashin texture;
	//AnimControl Animation;
	//Sprite sprite;

};












#endif