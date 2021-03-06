//MovingGameObject.h

#pragma once

#include "GameObject.h"
#include <SFML/Audio.hpp>


class Truck;

class MovingGameObject : public GameObject
{
public:
	sf::Vector2f GetVelocity();
	void SetVelocity(sf::Vector2f vel);
	int GetSpeed();
	void SetSpeed(float s);
	float getspeed();
protected:
	float speed;
	sf::Vector2f m_velocity;
	Truck* m_truck;
};