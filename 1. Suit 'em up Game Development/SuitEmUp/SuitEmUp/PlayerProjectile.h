// PlayerProjectile.h

#pragma once

#include "Projectile.h"

class Truck;
class PlayerObject;
class InputManager;

class PlayerProjectile : public Projectile{
public:
	PlayerProjectile(Truck* truck, PlayerObject* player, sf::Sprite* sprite = nullptr);
};