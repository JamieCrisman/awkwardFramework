#include "WorldEntity.h"

//std::vector<CEntity*> CEntity::EntityList;


WorldEntity::WorldEntity(){
	//X = Y = 0.0f;
	Width = Height = 0;

	//Type= come up with types?;


	Sprite();
}

WorldEntity::WorldEntity(char* File, float width, float height, Vector2 pos){
	Sprite();
	worldTexture.Load(File, width, height);
	if(worldTexture.GL_texture != NULL){
		sprite.setTexture(worldTexture);
		position = pos;
	}

}


WorldEntity::~WorldEntity(){
}

bool WorldEntity::Load(char* File, float width, float height, Vector2 pos){
	worldTexture.Load(File, width, height);
	if(worldTexture.GL_texture != NULL){
		sprite.setTexture(worldTexture);
		position = pos;
		return true;
	}else{
		return false;
	}
}

void WorldEntity::OnLoop(Uint8 *keys){
	
}

void WorldEntity::SetPos(Vector2 pos){
	position = pos;
}

float WorldEntity::getX(){
	return position.x;
}
float WorldEntity::getY(){
	return position.y;
}

void WorldEntity::OnRender(){
	sprite.Render(this->position, this->rotation, this->scale);
}

void WorldEntity::OnCleanup(){
}

void WorldEntity::OnAnimate(){
}
/*
bool WorldEntity::OnCollision(CEntity* Entity){
	return true;
}*/

/*
bool WorldEntity::Collides(int oX, int oY, int oW, int oH){
	int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
 
    int tX = (int)X + Col_X;
    int tY = (int)Y + Col_Y;
 
    left1 = tX;
    left2 = oX;
 
    right1 = left1 + Width - 1 - Col_Width;
    right2 = oX + oW - 1;
 
    top1 = tY;
    top2 = oY;
 
    bottom1 = top1 + Height - 1 - Col_Height;
    bottom2 = oY + oH - 1;
 
 
    if (bottom1 < top2) return false;
    if (top1 > bottom2) return false;
 
    if (right1 < left2) return false;
    if (left1 > right2) return false;
 
    return true;

}
*/