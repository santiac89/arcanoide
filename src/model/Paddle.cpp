/*
 * Paddle.cpp
 *
 *  Created on: 16/02/2014
 *      Author: Santi
 */

#include "model/Paddle.h"

Paddle::Paddle() {
	this->imagePath = "C:\\spaceship.bmp";

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
	bodyDef.type = b2_dynamicBody;
	bodyDef.gravityScale = 0;

	bodyDef.position.Set(worldPosition.x, worldPosition.y);
	this->body = world->CreateBody(&bodyDef);
	this->body->CreateFixture(&boxShape, 0.0f);
}

void Paddle::move()
{
	b2Vec2 vel = body->GetLinearVelocity();
	float32 desiredVel = 0;

	switch ( movementState )
	{
	  case MV_LEFT:  desiredVel = -0.05; break;
	  case MV_STOP:  desiredVel =  0; break;
	  case MV_RIGHT: desiredVel =  0.05; break;
	}

	float32 velChange = desiredVel - vel.x;
	float32 impulse = body->GetMass() * velChange; //disregard time factor
	body->ApplyLinearImpulse( b2Vec2(impulse,0), body->GetWorldCenter(),true );
}
