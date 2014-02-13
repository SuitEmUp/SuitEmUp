//PlayerObject.h

#pragma once

#include "MovingGameObject.h"

class Truck;
class InputManager;

class PlayerObject : public MovingGameObject
{
public:
	PlayerObject(Truck* truck, InputManager* input, sf::Sprite* sprite = nullptr);
	bool Update(float deltatime);
	bool GetType();
	int GetDamage();
	sf::Vector2f GetDirection();
private:
	InputManager* m_input;
	int m_damage;
	float m_cooldown;
	sf::Vector2f m_direction;
};