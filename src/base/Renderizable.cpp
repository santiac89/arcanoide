/*
 * Renderizable.cpp
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#include "base/Renderizable.h"
#include "base/ImageManager.h"
#include "base/GameRenderer.h"
#include <SDL2/SDL.h>

void Renderizable::onRender(GameRenderer& gameRenderer)
{
	 if (sdlTexture == NULL) throw "No texture";
	 SDL_Rect dstrect = { position.x,position.y, size.x, size.y };
	 SDL_RenderCopy(gameRenderer.getSDLRenderer(), sdlTexture, NULL, &dstrect);
}

void Renderizable::setImage(SDL_Renderer * sdlRenderer,std::string filePath)
{
	this->imagePath = filePath;
	this->sdlTexture = ImageManager::loadImage(sdlRenderer,filePath);
}

Renderizable::Renderizable() {
	this->sdlTexture = NULL;
}

Renderizable::Renderizable(float x, float y,float w, float h) {
	this->setPosition(x,y);
	this->setSize(w,h);
	this->sdlTexture = NULL;
}

void Renderizable::setPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

void Renderizable::setSize(float w, float h)
{
	this->size.x = w;
	this->size.y = h;
}

void Renderizable::loadImage(SDL_Renderer *sdlRenderer)
{
	this->sdlTexture = ImageManager::loadImage(sdlRenderer,this->imagePath);
}
