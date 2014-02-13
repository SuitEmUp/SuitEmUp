// EnemyProjectile.h

#pragma once

#include "Projectile.h"

class PlayerObject;
class Truck;
class EnemyObject;

class EnemyProjectile : public Projectile{
public:
	EnemyProjectile(Truck* truck, sf::Vector2f start, sf::Sprite* sprite = nullptr);
	bool Update(Truck* truck, float deltatime);
};