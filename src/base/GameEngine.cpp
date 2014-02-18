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
#include "base/CollisionsNotifier.h"
GameEngine::GameEngine() : world(b2Vec2(0.0,0.0f)) {}

void GameEngine::manageUserEvent(SDL_Event event)
{
	for (int i = 0;i < bodies.size();i++)
	{
		bodies[i]->onUserEvent(event);
	}
}

int GameEngine::loop()
{
	for (int i = 0;i < bodies.size();i++)
	{
			bodies[i]->move();
	}

	this->world.Step(1.0f / 60.0f,6,2);
 /*
  * 1.Move objects
  * 2.Check collisions
  */
}

int GameEngine::init()
{
	/**
	 * Walls
	 */

	Wall *bottomWall = new Wall(&world, 225.0f, 550.0f, 350.0f, 10.0f);
	Wall *topWall = new Wall(&world, 225.0f, 50.0f, 350.0f, 10.0f );

	Wall *leftWall = new Wall(&world,225.0f,50.0f,10.0f,500.0f);
	Wall *rightWall = new Wall(&world,565.0f,50.0f,10.0f,500.0f);
	Paddle *paddle = new Paddle();
	Ball *ball = new Ball();

	paddle->setWorld(&world);
	paddle->setSize(80.0f,10.0f);
	paddle->setPosition(325.0f,500.0f);
	paddle->init();


	ball->setWorld(&world);
	ball->setSize(20.0f,20.0f);
	ball->setPosition(325.0f,300.0f);
	ball->init();
//
//	bodies.push_back(bottomWall);
//	bodies.push_back(topWall);
//	bodies.push_back(leftWall);
//	bodies.push_back(rightWall);

	bodies.push_back(paddle);
	bodies.push_back(ball);

	world.SetContactListener(new CollisionsNotifier());

	return 0;

}

std::vector<Body*> GameEngine::getBodies()
{
	return bodies;
}
