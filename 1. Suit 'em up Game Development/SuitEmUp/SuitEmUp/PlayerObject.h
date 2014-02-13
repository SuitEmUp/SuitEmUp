//PlayerObject.h

#pragma once

#include "MovingGameObject.h"

class Truck;
class InputManager;

class PlayerObject : public MovingGameObject
{
public:
	PlayerObject(Truck* truck, InputManager* input, sf::Sprite* sprite = nullptr, sf::Sprite* update = nullptr);
	bool Update(float deltatime);
	bool GetType();
	float GetDamage();
	sf::Vector2f GetDirection();
private:
	InputManager* m_input;
	float m_damage;
	float m_cooldown;
	sf::Vector2f m_direction;
	sf::Sprite* m_update;
	sf::Sprite* m_unupdate;
};