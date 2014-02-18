/*
 * Wall.h
 *
 *  Created on: 14/02/2014
 *      Author: Santi
 */

#ifndef WALL_H_
#define WALL_H_

class b2World;

#include "base/Body.h"
#include <string>

class Wall : public Body {

public:
	Wall();
	Wall(b2World * world,float x, float y , float w, float h);
	virtual ~Wall();
	virtual void init();

};

#endif /* WALL_H_ */
