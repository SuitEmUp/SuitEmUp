// Truck.h

#pragma once;

#include "GameObject.h"

class Truck : public GameObject{
public:
	Truck(sf::Sprite* sprite = nullptr);
	bool Update(/*deltatime*/);
	sf::Vector2u GetVelocity();
	void SetVelocity(sf::Vector2u vel);

private:
	int m_hp;
	sf::Vector2u m_velocity;
};