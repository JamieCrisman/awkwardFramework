#include "WorldEntity.h"

//std::vector<CEntity*> CEntity::EntityList;


WorldEntity::WorldEntity(){
	//X = Y = 0.0f;
	Width = Height = 0;

	//Type= come up with types?;


	//Sprite();
}

WorldEntity::WorldEntity(char* File, float width, float height, glm::vec2 pos){
	//Sprite();
	worldTexture.Load(File);
	if(worldTexture.GL_texture != NULL){
		graphic->setTexture(worldTexture.getThis());
		position = pos;
	}
}


WorldEntity::~WorldEntity(){
}


bool WorldEntity::Load(char* File, float width, float height, glm::vec2 pos){
	if(worldTexture.Load(File)){
		graphic->setTexture(worldTexture.getThis());
		//position = pos;
		return true;
	}else{
		return false;
	}
}

void WorldEntity::OnRender(){
	Entity::OnRender();
}
