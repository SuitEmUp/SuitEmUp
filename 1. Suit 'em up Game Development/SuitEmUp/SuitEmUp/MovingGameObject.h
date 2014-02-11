//MovingGameObject.h

#pragma once

#include "GameObject.h"

class Truck;

class MovingGameObject : public GameObject
{
public:
	sf::Vector2f GetVelocity();
	void SetVelocity(sf::Vector2f vel);
	int GetSpeed();
	int SetSpeed(int s);


protected:
	int speed;
	sf::Vector2f m_velocity;
	Truck* m_truck;
};