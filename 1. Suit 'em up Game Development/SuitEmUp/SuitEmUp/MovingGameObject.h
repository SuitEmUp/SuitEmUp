//MovingGameObject.h

#pragma once

#include "GameObject.h"

class Truck;

class MovingGameObject : public GameObject
{
public:
	sf::Vector2u GetVelocity();
	void SetVelocity(sf::Vector2u vel);

protected:
	sf::Vector2u m_velocity;
	Truck* m_truck;
};