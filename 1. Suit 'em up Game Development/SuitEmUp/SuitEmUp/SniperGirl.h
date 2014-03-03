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
	float Damaged(float playerdmg);
	float GetDamage();

protected:
	float m_cooldown;
	float m_hp;
	float m_damage;
};