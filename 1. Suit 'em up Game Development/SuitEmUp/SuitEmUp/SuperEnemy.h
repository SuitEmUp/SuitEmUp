//SuperEnemy.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class SuperEnemy : public MovingGameObject{
public:
	SuperEnemy(Truck* truck, sf::Sprite* sprite = nullptr);
	~SuperEnemy();
	bool Update(float deltatime);
	bool GetType();
	int Damaged(int playerdmg);
	float GetDamage();

protected:
	float m_damage;
	float m_cooldown;
	float m_hp;
};