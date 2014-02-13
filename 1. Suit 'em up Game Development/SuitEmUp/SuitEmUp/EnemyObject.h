//EnemyObject.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class EnemyObject : public MovingGameObject{
public:
	EnemyObject(Truck* truck, sf::Sprite* sprite = nullptr);
	bool Update(float deltatime);
	bool GetType();
	int Damaged(int playerdmg);

private:
	float m_cooldown;
	float m_hp;
};