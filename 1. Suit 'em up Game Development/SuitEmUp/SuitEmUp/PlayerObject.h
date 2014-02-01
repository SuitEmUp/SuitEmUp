//PlayerObject.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class PlayerObject : public MovingGameObject
{
public:
	PlayerObject(Truck* truck, sf::Sprite* sprite = nullptr);
	bool Update(/*deltatime*/);

private:
	float m_cooldown;
};