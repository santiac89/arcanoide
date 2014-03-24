/*
 * Boundarie.cpp
 *
 *  Created on: 20/02/2014
 *      Author: Santi
 */

#include "model/Boundarie.h"


Boundarie::Boundarie() {
	this->imagePath = "C:\\spaceship.bmp";
	this->collisionBody = WALL;
}

Boundarie::~Boundarie() {
	// TODO Auto-generated destructor stub
}

void Boundarie::init()
{
	b2BodyDef boundarieBodyDef;
	b2Body * boundarieBody;
	b2PolygonShape groundBox;
	b2FixtureDef groundBoxDef;

	boundarieBodyDef.position.Set(worldPosition.x, worldPosition.y);
	boundarieBodyDef.type = b2_staticBody;
	boundarieBody = world->CreateBody(&boundarieBodyDef);

	groundBox.SetAsBox(worldSize.x, worldSize.y);
	groundBoxDef.shape = &groundBox;
	boundarieBody->CreateFixture(&groundBoxDef);

	this->body = boundarieBody;
	boundarieBody->SetUserData(this);

}
