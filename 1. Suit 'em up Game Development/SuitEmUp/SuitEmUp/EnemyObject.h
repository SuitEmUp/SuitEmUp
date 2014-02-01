//EnemyObject.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class EnemyObject : public MovingGameObject{
public:
	EnemyObject(Truck* truck, sf::Sprite* sprite = nullptr);
	bool Update(/*deltatime*/);

private:
	float m_cooldown;
};