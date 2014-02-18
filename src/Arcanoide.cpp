#include <stdio.h>
#include <SDL2/SDL.h>
#include "base/GameEngine.h"
#include "base/GameRenderer.h"

// This is a simple example of building and running a simulation
// using Box2D. Here we create a large ground box and a small dynamic
// box.
// There are no graphics for this example. Box2D is meant to be used
// with your rendering engine in your game engine.
int main(int argc, char** argv)
{

	/*
	* Initialization
	*/

	GameEngine gameEngine;
	GameRenderer gameRenderer(b2Vec2(10.0f,30.0f),b2Vec2(800.0f,600.0f));
	bool quitGame = false;
	SDL_Event sdlEvent;

	gameEngine.init();

	while (!quitGame)
	{

		while (SDL_PollEvent(&sdlEvent))
		{
			gameEngine.manageUserEvent(sdlEvent);
		}

		gameEngine.loop();
		gameRenderer.render(gameEngine);
		/*
		 * 1. UserEvents
		 * 2. WorldStep
		 * 3. WorldEvents
		 * 4. Render
		 */
	}


    SDL_Quit();
	return 0;
}
