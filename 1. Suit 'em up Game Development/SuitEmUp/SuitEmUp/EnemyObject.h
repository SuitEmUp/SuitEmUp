//EnemyObject.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class EnemyObject : public MovingGameObject{
public:
	EnemyObject(Truck* truck, sf::Sprite* sprite = nullptr);
	~EnemyObject();
	bool Update(float deltatime);
	bool GetType();
	int Damaged(int playerdmg);
	float GetDamage();

protected:
	float m_cooldown;
	float m_hp;
	float m_damage;
};