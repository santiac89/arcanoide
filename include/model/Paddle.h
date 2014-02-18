/*
 * Paddle.h
 *
 *  Created on: 16/02/2014
 *      Author: Santi
 */

#ifndef PADDLE_H_
#define PADDLE_H_

#include "base/Body.h"

class Paddle : public Body {
private:
	enum MovementState
	{
		MV_STOP,MV_LEFT,MV_RIGHT,MV_NONE
	};
	MovementState movementState;
public:


	Paddle();
	virtual ~Paddle();

	void init();
	void onUserEvent(SDL_Event event);
	void move();

};

#endif /* PADDLE_H_ */
