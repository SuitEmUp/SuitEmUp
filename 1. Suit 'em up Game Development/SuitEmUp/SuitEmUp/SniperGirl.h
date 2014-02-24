//SniperGirl.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class SniperGirl : public MovingGameObject{
public:
	SniperGirl(Truck* truck, sf::Sprite* sprite = nullptr);
	~SniperGirl();
	bool Update(float deltatime);
	bool GetType();
	int Damaged(int playerdmg);
	float GetDamage();

protected:
	float m_cooldown;
	int m_hp;
	float m_damage;
};