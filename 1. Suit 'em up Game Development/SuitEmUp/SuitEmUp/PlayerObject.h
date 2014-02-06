//PlayerObject.h

#pragma once

#include "MovingGameObject.h"

class Truck;
class InputManager;

class PlayerObject : public MovingGameObject
{
public:
	PlayerObject(Truck* truck, sf::Sprite* sprite = nullptr);
	bool Update(/*deltatime*/InputManager* input);
	bool GetType();
private:
	float m_cooldown;
};