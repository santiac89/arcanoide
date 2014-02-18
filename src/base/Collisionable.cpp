/*
 * Collisionable.cpp
 *
 *  Created on: 18/02/2014
 *      Author: Santi
 */

#include <base/Collisionable.h>


Collisionable::Collisionable() {
	// TODO Auto-generated constructor stub

}

Collisionable::~Collisionable() {
	// TODO Auto-generated destructor stub
}

void Collisionable::EndContact(b2Contact* contact,BodyUserData* collisionObject) {}
 void Collisionable::PreSolve(b2Contact* contact, const b2Manifold* oldManifold,BodyUserData* collisionObject) {}
void Collisionable::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse,BodyUserData * collisionObject) {}
void Collisionable::BeginContact(b2Contact* contact,BodyUserData * collisionObject) {}

