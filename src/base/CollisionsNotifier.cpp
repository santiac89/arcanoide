/*
 * CollisionsNotifier.cpp
 *
 *  Created on: 18/02/2014
 *      Author: Santi
 */

#include <base/CollisionsNotifier.h>
#include "base/BodyUserData.h"
#include "base/Collisionable.h"

CollisionsNotifier::CollisionsNotifier() {
	// TODO Auto-generated constructor stub

}

CollisionsNotifier::~CollisionsNotifier() {
	// TODO Auto-generated destructor stub
}

void CollisionsNotifier::BeginContact(b2Contact* contact){

	BodyUserData * dataA = (BodyUserData*) contact->GetFixtureA()->GetBody()->GetUserData();
	BodyUserData * dataB = (BodyUserData*) contact->GetFixtureB()->GetBody()->GetUserData();

	if (dataA != NULL)
		dataA->collisionableBody->BeginContact(contact,dataB);

	if (dataB != NULL)
		dataB->collisionableBody->BeginContact(contact,dataA);

}

void CollisionsNotifier::EndContact(b2Contact* contact)
{
	BodyUserData * dataA = (BodyUserData*) contact->GetFixtureA()->GetBody()->GetUserData();

	BodyUserData * dataB = (BodyUserData*) contact->GetFixtureB()->GetBody()->GetUserData();

		if (dataA != NULL)
	dataA->collisionableBody->EndContact(contact,dataB);

		if (dataB != NULL)
		dataB->collisionableBody->EndContact(contact,dataA);
}

void CollisionsNotifier::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{BodyUserData * dataA = (BodyUserData*) contact->GetFixtureA()->GetBody()->GetUserData();
BodyUserData * dataB = (BodyUserData*) contact->GetFixtureB()->GetBody()->GetUserData();

if (dataA != NULL)
	dataA->collisionableBody->PreSolve(contact,oldManifold,dataB);
if (dataB != NULL)
	dataB->collisionableBody->PreSolve(contact,oldManifold,dataA);
}

void CollisionsNotifier::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	BodyUserData * dataA = (BodyUserData*) contact->GetFixtureA()->GetBody()->GetUserData();
		BodyUserData * dataB = (BodyUserData*) contact->GetFixtureB()->GetBody()->GetUserData();

	if (dataA != NULL)
		dataA->collisionableBody->PostSolve(contact,impulse,dataB);
	if (dataB != NULL)
		dataB->collisionableBody->PostSolve(contact,impulse,dataA);
}
