/*
 * Entity.h
 *
 *  Created on: 17/03/2014
 *      Author: Santi
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "base/Body.h"

enum EntityType
{
	BALL,
	WALL,
	PADDLE,
	BRICK
};

class Entity : public Renderizable
{
	private:
		Body body;
	public:
		Body getBody();
		void setEntityType(EntityType entityType);
		EntityType getEntityType();
		virtual void onUserEvent(SDL_Event event);
		virtual void onMove();
		virtual void onEndContact(b2Contact* contact,Entity* collisionObject);
		virtual void onPreSolveContact(b2Contact* contact, const b2Manifold* oldManifold,Entity* collisionObject);
		virtual void onPostSolveContact(b2Contact* contact, const b2ContactImpulse* impulse,Entity * collisionObject);
		virtual void onBeginContact(b2Contact* contact,Entity * collisionObject);

};


#endif /* ENTITY_H_ */
