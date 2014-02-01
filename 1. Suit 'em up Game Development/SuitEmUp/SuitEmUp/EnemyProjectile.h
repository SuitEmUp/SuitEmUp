// EnemyProjectile.h

#pragma once

#include "Projectile.h"

class PlayerObject;
class Truck;

class EnemyProjectile : public Projectile{
public:
	EnemyProjectile(Truck* truck, sf::Sprite* sprite = nullptr);

};