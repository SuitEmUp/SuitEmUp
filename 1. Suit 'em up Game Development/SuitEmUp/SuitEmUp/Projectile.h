// Projectile.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class Projectile : public MovingGameObject{
public:
	bool Update(/*deltatime*/Truck* truck);
	bool GetType();
};