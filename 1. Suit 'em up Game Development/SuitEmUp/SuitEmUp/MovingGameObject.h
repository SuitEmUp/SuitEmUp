//MovingGameObject.h

#pragma once

#include "GameObject.h"

class Truck;

class MovingGameObject : public GameObject
{
public:
	sf::Vector2f GetVelocity();
	void SetVelocity(sf::Vector2f vel);

protected:
	sf::Vector2f m_velocity;
	Truck* m_truck;
};