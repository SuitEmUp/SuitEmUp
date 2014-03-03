// Projectile.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class Projectile : public MovingGameObject{
public:
	bool Update(Truck* truck, float deltatime);
	bool GetType();
	float GetRotation();
protected:
	float m_rotation;
};