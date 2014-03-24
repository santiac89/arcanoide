/*
 * Collisioable.h
 *
 *  Created on: 18/02/2014
 *      Author: Santi
 */

#ifndef COLLISIONABLE_H_
#define COLLISIONABLE_H_

class b2Contact;
class b2Manifold;
class b2ContactImpulse;
class BodyUserData;

class Collisionable {

public:

	Collisionable();
	virtual ~Collisionable();
	virtual void BeginContact(b2Contact* contact,BodyUserData * collisionObject);
	virtual	void EndContact(b2Contact* contact,BodyUserData* collisionObject);
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold,BodyUserData* collisionObject);
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse,BodyUserData * collisionObject);

};


#endif /* COLLISIONABLE_H_ */
