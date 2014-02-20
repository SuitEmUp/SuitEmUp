// EnemyProjectile.h

#pragma once

#include "Projectile.h"

class PlayerObject;
class Truck;
class EnemyObject;

class EnemyProjectile : public Projectile{
	float m_damage;
public:
	EnemyProjectile(float damage, Truck* truck, sf::Vector2f start, sf::Sprite* sprite = nullptr);
	bool Update(Truck* truck, float deltatime);
	float GetDamage();
};