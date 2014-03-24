/*
 * Paddle.cpp
 *
 *  Created on: 16/02/2014
 *      Author: Santi
 */

#include "model/Paddle.h"

Paddle::Paddle() {
	this->imagePath = "C:\\spaceship.bmp";
	this->collisionBody = PADDLE;
}

Paddle::~Paddle() {
	// TODO Auto-generated destructor stub
}


void Paddle::onUserEvent(SDL_Event event){

	switch( event.type )
	{
		case SDL_KEYDOWN:

			 switch( event.key.keysym.sym )
			 {
				case SDLK_LEFT:
					movementState = MV_LEFT;
				break;
				case SDLK_RIGHT:
					movementState = MV_RIGHT;
				break;
			 }


		break;

		case SDL_KEYUP:
			movementState = MV_STOP;
		break;
	}

}

void Paddle::init()
{
	b2PolygonShape boxShape;
	boxShape.SetAsBox(worldSize.x, worldSize.y);

	b2BodyDef bodyDef;
	bodyDef.type = b2_kinematicBody;
	bodyDef.gravityScale = 0;

	bodyDef.position.Set(worldPosition.x, worldPosition.y);
	this->body = world->CreateBody(&bodyDef);
	this->body->CreateFixture(&boxShape, 0.0f);
	this->body->SetUserData(this);
}

void Paddle::move()
{
	b2Vec2 vel = body->GetLinearVelocity();
	float32 desiredVel = 0;

	switch ( movementState )
	{
	  case MV_LEFT:  desiredVel = -5; break;
	  case MV_STOP:  desiredVel =  0; break;
	  case MV_RIGHT: desiredVel =  5; break;
	}

	body->SetLinearVelocity(b2Vec2(desiredVel,0.0f));
}
