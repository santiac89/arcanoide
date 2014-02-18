/*
 * GameRenderer.cpp
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#include "base/GameRenderer.h"
#include "base/GameEngine.h"
#include <SDL2/SDL.h>

GameRenderer::GameRenderer(b2Vec2 worldSize,b2Vec2 resolutionSize) {

	SDL_Init(SDL_INIT_VIDEO);
	sdlWindow = SDL_CreateWindow("Arcanoide", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, resolutionSize.x, resolutionSize.y, SDL_WINDOW_SHOWN);
	sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);
	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 0);
	this->resolution = resolutionSize;
	this->worldSize = worldSize;

}

void GameRenderer::render(GameEngine& gameEngine)
{
	std::vector<Body*> bodiesToRender = gameEngine.getBodies();

	SDL_RenderClear(sdlRenderer);

	for (int i = 0;i < bodiesToRender.size();i++)
	{
		if (bodiesToRender[i]->sdlTexture == NULL) bodiesToRender[i]->loadImage(sdlRenderer);
		bodiesToRender[i]->onRender(*this);
	}

	SDL_RenderPresent(sdlRenderer);

}


SDL_Renderer * GameRenderer::getSDLRenderer()
{
	return sdlRenderer;
}

b2Vec2 GameRenderer::getResolution()
{
	return resolution;
}

b2Vec2 GameRenderer::getWorldSize()
{
	return worldSize;
}
