//SniperGirl.h

#pragma once

#include "MovingGameObject.h"

class Truck;

class SniperGirl : public MovingGameObject{
public:
	SniperGirl(Truck* truck, sf::Sprite* sprite = nullptr);
	bool Update(float deltatime);
	bool GetType();
	int Damaged(int playerdmg);

protected:
	float m_cooldown;
	float m_hp;
};