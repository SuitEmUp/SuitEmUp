
#pragma once

#include "GameObject.h"

class MovingGameObject : public GameObject
{
protected:
	sf::Vector2u m_velocity;
	sf::Vector2u m_middle;
};