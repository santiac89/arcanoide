/*
 * Body.h
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#ifndef BODY_H_
#define BODY_H_

class GameRenderer;

#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>
#include "base/Renderizable.h"


class Body : public Renderizable {

public:
	b2Body *body;
	b2World* world;
	b2Vec2 worldPosition;
	b2Vec2 worldSize;

	void onRender(GameRenderer& gameRenderer);
	void setPosition(float x, float y);
	void setSize(float w, float h);
	void setWorld(b2World * world);

	virtual ~Body() {};
	virtual void init() {};
	virtual void onUserEvent(SDL_Event event) {};
	virtual void move() {};
};


#endif /* BODY_H_ */
