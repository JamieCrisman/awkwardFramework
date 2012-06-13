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

void WorldEntity::OnRender(){
	sprite.Render(this->position, this->rotation, this->scale);
}
