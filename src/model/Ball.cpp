/*
 * Ball.cpp
 *
 *  Created on: 17/02/2014
 *      Author: Santi
 */

#include "model/Ball.h"
#include "base/BodyUserData.h"
#include "base/CollisionBody.h"

Ball::Ball() {
	this->imagePath = "C:\\spaceship.bmp";
	this->collisionBody = BALL;
}

Ball::~Ball() {
	// TODO Auto-generated destructor stub
}



void Ball::init()
{
	b2CircleShape circleShape;
	circleShape.m_radius = 10.0f/50;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(worldPosition.x, worldPosition.y);
	bodyDef.userData = new BodyUserData(this);

	b2FixtureDef ballFixture;
	ballFixture.shape = &circleShape;
	ballFixture.density = 1.0f;
	ballFixture.friction = 0;
	ballFixture.restitution = 1.0f;

	this->body = world->CreateBody(&bodyDef);
	this->body->CreateFixture(&ballFixture);
	body->ApplyLinearImpulse( b2Vec2(0,0.01),bodyDef.position,true );
}

void Ball::move()
{
//	b2Vec2 vel = body->GetLinearVelocity();
//	float32 desiredVel = 0;
//
//
//	float32 velChange = desiredVel - vel.x;
//	float32 impulse = body->GetMass() * velChange; //disregard time factor
//	if (start == 0)
//	{
//
//		start = 1;
//	}
}

void Ball::BeginContact(b2Contact* contact,BodyUserData * collisionObject)
{
	//body->ApplyLinearImpulse( b2Vec2(-0.02,0),body->GetWorldCenter(),true );

}

