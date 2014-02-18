/*
 * BodyUserData.h
 *
 *  Created on: 18/02/2014
 *      Author: Santi
 */

#ifndef BODYUSERDATA_H_
#define BODYUSERDATA_H_

#include "base/Collisionable.h"


class BodyUserData {

	public:
		Collisionable * collisionableBody;
	BodyUserData(Collisionable * collisionableBody);
	virtual ~BodyUserData();
};


#endif /* BODYUSERDATA_H_ */
