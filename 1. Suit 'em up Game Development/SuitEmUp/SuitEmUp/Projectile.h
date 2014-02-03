// Projectile.h

#pragma once

#include "MovingGameObject.h"

class Projectile : public MovingGameObject{
public:
	bool Update(/*deltatime*/);
	bool GetType();
};