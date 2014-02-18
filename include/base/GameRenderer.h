/*
 * GameRenderer.h
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#ifndef GAMERENDERER_H_
#define GAMERENDERER_H_

class GameEngine;
class SDL_Renderer;
class SDL_Window;

#include <Box2D/Box2D.h>
#include <vector>

class GameRenderer {

private:
	b2Vec2 worldSize;
	b2Vec2 resolution;
	SDL_Window * sdlWindow;
	SDL_Renderer * sdlRenderer;

public:
	GameRenderer(b2Vec2 worldSize,b2Vec2 resolutionSize);
	SDL_Renderer * getSDLRenderer();
	void render(GameEngine& gameEngine);
	b2Vec2 getResolution();
	b2Vec2 getWorldSize();
};

#endif /* GAMERENDERER_H_ */
