/*
 * Ball.h
 *
 *  Created on: 17/02/2014
 *      Author: Santi
 */

#ifndef BALL_H_
#define BALL_H_

#include <base/Body.h>
#include "base/Collisionable.h"

class Ball: public Body,public Collisionable {
public:
	int start = 0;
	Ball();
	virtual ~Ball();

	void init();
	void move();
	void BeginContact(b2Contact* contact,BodyUserData * collisionObject);

};



#endif /* BALL_H_ */
