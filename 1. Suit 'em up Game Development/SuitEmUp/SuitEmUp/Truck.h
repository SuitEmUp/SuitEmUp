// Truck.h

#pragma once;

#include "GameObject.h"

class EnemyProjectile;

class Truck : public GameObject{
public:
	Truck(sf::Sprite* sprite = nullptr, sf::Sprite* sprite2 = nullptr);
	bool Update(float deltatime);
	sf::Vector2f GetVelocity();
	void SetVelocity(sf::Vector2f vel);
	bool GetType();
	void Damaged(float damage);
	void Healed();
	float UpdateHP();

protected:
	sf::Sprite* m_update;
	sf::Sprite* m_unupdate;
	float m_hp;
	sf::Vector2f m_velocity;
};