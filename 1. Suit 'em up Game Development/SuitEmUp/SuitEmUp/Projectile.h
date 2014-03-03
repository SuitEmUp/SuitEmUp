// Projectile.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class Projectile : public MovingGameObject{
public:
	bool Update(Truck* truck, float deltatime);
	bool GetType();
	std::string GetType2();
	float GetRotation();
protected:
	std::string type;
	float m_rotation;
};