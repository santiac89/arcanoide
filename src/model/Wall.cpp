/*
 * Wall.cpp
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#include "model/Wall.h"

Wall::Wall(b2World * world,float x, float y , float w, float h) {

	this->world = world;
	this->setSize(w,h);
	this->setPosition(x,y);
	this->imagePath = "C:\\spaceship.bmp";
	this->init();

}

Wall::~Wall() {
	// TODO Auto-generated destructor stub
}

void Wall::init()
{
//	b2BodyDef groundBodyDef;
//	groundBodyDef.position.Set(0,0);
//	b2Body groundBody;// = world->CreateBody(&groundBodyDef);
//
//	b2EdgeShape groundBox;
//	b2FixtureDef groundBoxDef;
//	groundBoxDef.shape = &groundBox;
//
//	groundBox.Set(b2Vec2(worldPosition.x, worldPosition.y), b2Vec2(worldSize.x, 0));
//	groundBody.CreateFixture(&groundBoxDef);
//
//	groundBox.Set(b2Vec2(worldPosition.x, worldPosition.y), b2Vec2(0, worldSize.y));
//	groundBody.CreateFixture(&groundBoxDef);
//
//	groundBox.Set(b2Vec2(worldPosition.x, worldPosition.y), b2Vec2(worldPosition.x, 0));
//	groundBody.CreateFixture(&groundBoxDef);
//
//	groundBox.Set(b2Vec2(worldPosition.x, worldPosition.y), b2Vec2(worldPosition.x, 0));
//	groundBody.CreateFixture(&groundBoxDef);

//	groundBox.Set(b2Vec2(0,0), b2Vec2(0, winSize.height/PTM_RATIO));
//	groundBody->CreateFixture(&groundBoxDef);
//
//	groundBox.Set(b2Vec2(0, winSize.height/PTM_RATIO), b2Vec2(winSize.width/PTM_RATIO,
//	    winSize.height/PTM_RATIO));
//	_groundBody->CreateFixture(&groundBoxDef);
//
//	groundBox.Set(b2Vec2(winSize.width/PTM_RATIO, winSize.height/PTM_RATIO),
//	    b2Vec2(winSize.width/PTM_RATIO, 0));
//	_groundBody->CreateFixture(&groundBoxDef);

//	b2PolygonShape wallBox;
//	wallBox.SetAsBox(worldSize.x, worldSize.y);
//
//	b2BodyDef wallBodyDef;
//	wallBodyDef.position.Set(worldPosition.x, worldPosition.y);
//	this->body = world->CreateBody(&wallBodyDef);
//	this->body->CreateFixture(&wallBox, 0.0f);
}

