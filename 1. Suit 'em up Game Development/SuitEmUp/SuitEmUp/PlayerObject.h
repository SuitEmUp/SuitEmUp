

#pragma once

#include "MovingGameObject.h"

class PlayerObject : public MovingGameObject
{
public:
	PlayerObject(sf::Vector2u* truck, sf::Sprite* sprite = nullptr);
	bool Update(/*deltatime*/);

private:
	float m_cooldown;
};