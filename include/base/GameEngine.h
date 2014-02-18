/*
 * GameEngine.h
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

class Body;
union SDL_Event;

#include <vector>
#include <Box2D/Box2D.h>
#include "base/Body.h"

class GameEngine {

private:
	std::vector<Body*> bodies;
	b2World world;

public:
	GameEngine();
	int loop();
	int init();
	std::vector<Body*> getBodies();
	void manageUserEvent(SDL_Event event);
};

#endif /* GAMEENGINE_H_ */
