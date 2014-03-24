/*
 * GameEngine.cpp
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#include "base/GameEngine.h"
#include "model/Wall.h"
#include "model/Paddle.h"
#include "model/Ball.h"
#include "model/Boundarie.h"
#include <typeinfo>  //for 'typeid'
#include "base/CollisionsNotifier.h"
#include <Box2D/Box2D.h>

GameEngine::GameEngine() {

	this->world = new b2World(b2Vec2(0.0,0.0f));

	//world.SetContactListener(new CollisionsNotifier());

}

GameEngine::GameEngine(b2World *world) {

	this->world = world;
	this->debug = true;
	//world.SetContactListener(new CollisionsNotifier());

}

/**
 * Notifies the bodies in the world that an user event has happened
 */
void GameEngine::manageUserEvent(SDL_Event event)
{
	if (event.type == SDL_QUIT)
	{
		quit = true;
	}

	for (int i = 0;i < bodies.size();i++)
	{
		bodies[i]->onUserEvent(event);
	}
}

/**
 * Main game loop
 */
int GameEngine::loop()
{
	for (int i = 0;i < bodies.size();i++)
	{
			bodies[i]->move();
	}

	if (!debug)
		this->world->Step(1.0f / 60.0f,6,2);
}

/**
 * Initialization
 */
int GameEngine::init()
{
	Paddle *paddle = new Paddle();
	Ball *ball = new Ball();
	Boundarie *topWall = new Boundarie();
	Boundarie *rightWall = new Boundarie();
	Boundarie *bottomWall = new Boundarie();
	Boundarie *leftWall = new Boundarie();

	topWall->setWorld(world);
	topWall->setSize(350.0f,20.0f);
	topWall->setPosition(225.0f,50.0f);
	topWall->init();

	rightWall->setWorld(world);
	rightWall->setSize(20.0f,520.0f);
	rightWall->setPosition(575.0f,50.0f);
	rightWall->init();

	bottomWall->setWorld(world);
	bottomWall->setSize(350.0f,20.0f);
	bottomWall->setPosition(225.0f,550.0f);
	bottomWall->init();

	leftWall->setWorld(world);
	leftWall->setSize(20.0f,520.0f);
	leftWall->setPosition(225.0f,50.0f);
	leftWall->init();
//
//
//	topWall->setWorld(&world);
//	topWall->setSize(300.0f,20.0f);
//	topWall->setPosition(200.0f,20.0f);
//	topWall->init();

	paddle->setWorld(world);
	paddle->setSize(80.0f,10.0f);
	paddle->setPosition(325.0f,500.0f);
	paddle->init();

	ball->setWorld(world);
	ball->setSize(20.0f,20.0f);
	ball->setPosition(325.0f,300.0f);
	ball->init();

	bodies.push_back(paddle);
	bodies.push_back(ball);
	bodies.push_back(topWall);
	bodies.push_back(rightWall);
	bodies.push_back(bottomWall);
	bodies.push_back(leftWall);

	return 0;

}

std::vector<Body*> GameEngine::getBodies()
{
	return bodies;
}
