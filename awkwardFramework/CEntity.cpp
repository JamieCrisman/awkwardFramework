#include "CEntity.h"

std::vector<CEntity*> CEntity::EntityList;

EntityTagData::EntityTagData()
{
	save = false;
}

EntityTagData::EntityTagData(const std::string &name, bool save)
	: name(name), save(save)
{
}

EntityTagData::EntityTagData(const EntityTagData &entityTagData)
	: name(entityTagData.name), save(entityTagData.save)
{
}

void CEntity::Add(){
	EntityList.push_back(this);
}

CEntity::CEntity(){
	//X = Y = 0.0f;
	Width = Height = 0;

	Speed = Vector2(0.0, 0.0);
	maxSpeed = Vector2(5.0, 0.0);
	Sprite();
}

CEntity::~CEntity(){
}

bool CEntity::OnLoad(char* File, float Width, float Height, int MaxFrames){
	
	//Anim_Control.MaxFrames = MaxFrames;

	return true;
}

void CEntity::OnLoop(Uint8 *keys){
	
}

void CEntity::SetPos(Vector2 pos){
	position = pos;
}

float CEntity::getX(){
	return position.x;
}
float CEntity::getY(){
	return position.y;
}

void CEntity::OnRender(){
}

void CEntity::OnCleanup(){
}

void CEntity::OnAnimate(){
}

bool CEntity::OnCollision(CEntity* Entity){
	return true;
}

void CEntity::OnMove(float MoveX, float MoveY)
{
}
void CEntity::StopMove(){

}


const std::string& CEntity::GetTag(int index)
{
	return tags[index].name;
}

void CEntity::AddTag(const std::string& tag, bool save)
{
	if (!HasTag(tag))
	{
		tags.push_back(EntityTagData(tag, save));
		//if (scene != NULL)
		//	scene->EntityAddTag(this, tag);
	}
}

void CEntity::RemoveTag(const std::string& tag)
{
	for (EntityTags::iterator i = tags.begin(); i != tags.end(); ++i)
	{
		if ((*i).name.compare(tag) == 0)
		{
			tags.erase(i);
			break;
		}
	}
	//if (scene != NULL)
	//	scene->EntityRemoveTag(this, tag);
}

bool CEntity::HasTag(const std::string& tag)
{
	for (EntityTags::iterator i = tags.begin(); i != tags.end(); ++i)
	{
		if ((*i).name.compare(tag) == 0)
			return true;
	}

	return false;
}

int CEntity::GetNumberOfTags()
{
	return static_cast<int>(tags.size());
}