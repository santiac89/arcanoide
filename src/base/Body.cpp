/* Body.cpp
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#include "base/Body.h"
#include "base/GameRenderer.h"
#include <stdio.h>

void Body::setWorld(b2World * world)
{
	this->world = world;
}

void Body::setPosition(float x, float y)
{
	if (worldSize.x + worldSize.y == 0) printf("Calculation error: No size for the object");
	this->worldPosition.x = x/50 + worldSize.x;
	this->worldPosition.y = -y/50 - worldSize.y;
}

/*
 * Set the size of a body un pixels
 */
void Body::setSize(float w, float h)
{
	this->worldSize.x = w/50/2;
	this->worldSize.y = h/50/2;
	Renderizable::setSize(w,h);
}

void Body::onRender(GameRenderer& gameRenderer)
{
	worldPosition = this->body->GetPosition();
	b2Vec2 renderPosition((worldPosition.x*50)-(size.x/2),-((worldPosition.y*50)+(size.y/2)));
	Renderizable::setPosition(renderPosition.x,renderPosition.y);
	Renderizable::onRender(gameRenderer);

}


