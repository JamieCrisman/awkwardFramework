#include "Entity.h"
#include "Collider\Collider.h"
std::vector<Entity*> Entity::EntityList;

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

void Entity::Add(){
	EntityList.push_back(this);
}

Entity* Entity::getThis(){
	return this;
}

Entity::Entity() {
	//X = Y = 0.0f;
	Width = Height = 0;
	//collider.setPosition(this->position);
	Speed = glm::vec2(0.0f, 0.0f);
	maxSpeed = glm::vec2(5.0f, 0.0f);
	collider = NULL;
	offset = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
	graphic = Graphic(this).getThis();
}

Entity::~Entity(){
	delete collider;
}

bool Entity::OnLoad(char* File, float Width, float Height, int MaxFrames){
	
	//Anim_Control.MaxFrames = MaxFrames;

	return true;
}

void Entity::OnLoop(Uint8 *keys){
	
}

void Entity::SetPos(glm::vec2 pos){
	position = pos;
}
/*
float Entity::getX(){
	return position.x;
}
float Entity::getY(){
	return position.y;
}
*/
glm::vec2 Entity::getPosition(){
	return position;
}

int Entity::getWidth(){
	return Width;
}
int Entity::getHeight(){
	return Height;
}

glm::vec4 Entity::getOffset(){
	return offset;
}

void Entity::setOffset(glm::vec4 off){
	offset = off;
}

glm::vec2 Entity::getDimensions(){
	glm::vec2 d = graphic->getFrameDimensions();
	float dimx = (d.x - (offset.x + offset.z)) * this->scale.x;
	float dimy = (d.y - (offset.y + offset.w)) * this->scale.y;
	return glm::vec2(dimx, dimy); //sprite.getDimensions();
}

Collider* Entity::getCollider(){
	return collider;
}

void Entity::setCollider(int type){
	//TODO add in support for other collision types
	if(type == COLLIDER_TYPE_SQUARE){
		collider = new BlockCollider(this);
		//this->collider.setOffset(offset);
		//this->collider.setPosition(position);
	}
}

void Entity::handleCollision(std::vector<glm::vec2> pVec){

}

void Entity::OnRender(){
	graphic->render();
}

void Entity::OnCleanup(){
}

void Entity::OnAnimate(){
}

bool Entity::OnCollision(Entity* Entity){
	return true;
}

void Entity::OnMove(float MoveX, float MoveY)
{
}
void Entity::StopMove(){

}


const std::string& Entity::GetTag(int index)
{
	return tags[index].name;
}

void Entity::AddTag(const std::string& tag, bool save)
{
	if (!HasTag(tag))
	{
		tags.push_back(EntityTagData(tag, save));
		//if (scene != NULL)
		//	scene->EntityAddTag(this, tag);
	}
}

void Entity::RemoveTag(const std::string& tag)
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

bool Entity::HasTag(const std::string& tag)
{
	for (EntityTags::iterator i = tags.begin(); i != tags.end(); ++i)
	{
		if ((*i).name.compare(tag) == 0)
			return true;
	}

	return false;
}

int Entity::GetNumberOfTags()
{
	return static_cast<int>(tags.size());
}