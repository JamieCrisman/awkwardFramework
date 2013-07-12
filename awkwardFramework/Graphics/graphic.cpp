#pragma once

#include "graphic.h"

Graphic::Graphic(){
	int RGB[3] = {255};
	frameOffset = glm::vec2(0,0);
	frameScale = glm::vec2(1.0, 1.0); //use whole frame
	frameWidth = 0;
	frameHeight = 0;
}
Graphic::Graphic(Entity *e){
	entity = e->getThis();
	Graphic();
}
Graphic::~Graphic(){
	//delete texture; //texture is a pointer... figure out how to delete it
}

void Graphic::setTexture(Shashin *txtr){
	texture = txtr;
	//defaulting to whole texture
	//frame h/w is what we look at when it comes to rendering
	frameWidth = texture->textureWidth;
	frameHeight = texture->textureHeight;
	//animation frames have to be defined after the texture is set
}

//for showing a graphic without a texture
void Graphic::setFrame(float fWidth, float fHeight){
	frameWidth = fWidth;
	frameHeight = fHeight;
}

Shashin *Graphic::getTexture(){
	return texture;
}

int *Graphic::getColor(){
	return RGB;
}

glm::vec2 Graphic::getFrameDimensions(){
	return glm::vec2(frameWidth, frameHeight);
}

void Graphic::render(){
	bool hasTexture = false; //(texture->GL_texture != NULL);
	
	glLoadIdentity();
	if(hasTexture){
		glBindTexture( GL_TEXTURE_2D, texture->GL_texture);
	}
	float w = frameWidth * entity->scale.x; 
	float h = frameHeight* entity->scale.y;
	//if we have a negative scale. add an offset of the width
	if(entity->scale.x < 0){
		entity->position.x += frameWidth * glm::abs(entity->scale.x);
	}

	if(entity->rotation != 0.0){ //no idea how much this will actually trim off but lettuce try it.
		//position the rotation around the center of the graphic
		glTranslatef((entity->position.x + (frameWidth/2)), (entity->position.y + (frameHeight/2)), entity->depth);
		glRotatef(entity->rotation, 0,0, 1.0);
		//move back to top left
		glTranslatef(-(entity->position.x + (frameWidth/2)), -(entity->position.y + (frameHeight/2)), entity->depth);
	}
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	GLenum renderType = GL_QUADS;
		if(!hasTexture){ //|| debugmode == true; maybe do another render for debug mode
			renderType = GL_LINE_LOOP;
		}
		glBegin(renderType);
			glColor3ui(RGB[0], RGB[1], RGB[2]);
			// bottom left
			if(hasTexture)
				glTexCoord2f(frameOffset.x, frameOffset.y + frameScale.y);
			glVertex3f(entity->position.x, h + entity->position.y, entity->depth);
			

			// top left
			if(hasTexture)
				glTexCoord2f(frameOffset.x, frameOffset.y);
			glVertex3f(entity->position.x, entity->position.y, entity->depth);

			// top right
			if(hasTexture)
				glTexCoord2f(frameOffset.x + frameScale.x, frameOffset.y);
			glVertex3f(w + entity->position.x, entity->position.y, entity->depth);

			// bottom right
			if(hasTexture)
				glTexCoord2f(frameOffset.x + frameScale.x, frameOffset.y + frameScale.y);
			glVertex3f(w + entity->position.x, h + entity->position.y, entity->depth);
			
		glEnd();
	glPopMatrix();
	

}

Graphic *Graphic::getThis(){
	return this;
}