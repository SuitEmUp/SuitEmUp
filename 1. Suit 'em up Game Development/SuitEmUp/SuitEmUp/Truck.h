// Truck.h

#pragma once;

#include "GameObject.h"

class EnemyProjectile;

class Truck : public GameObject{
public:
	Truck(sf::Sprite* sprite = nullptr);
	bool Update(/*deltatime*/);
	sf::Vector2f GetVelocity();
	void SetVelocity(sf::Vector2f vel);
	bool GetType();
	void Damaged();
	void Healed();

private:
	int m_hp;
	sf::Vector2f m_velocity;
};