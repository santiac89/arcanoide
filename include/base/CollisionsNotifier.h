/*
 * CollisionsNotifier.h
 *
 *  Created on: 18/02/2014
 *      Author: Santi
 */

#ifndef COLLISIONSNOTIFIER_H_
#define COLLISIONSNOTIFIER_H_

#include "Box2D/Box2D.h"

class CollisionsNotifier : public b2ContactListener {
public:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
	CollisionsNotifier();
	virtual ~CollisionsNotifier();

};


#endif /* COLLISIONSNOTIFIER_H_ */
