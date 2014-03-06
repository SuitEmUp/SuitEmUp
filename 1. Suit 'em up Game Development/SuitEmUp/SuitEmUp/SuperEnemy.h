//SuperEnemy.h

#pragma once

#include "MovingGameObject.h"
#include "Animation.h"

class Truck;

class SuperEnemy : public MovingGameObject{
public:
	SuperEnemy(Truck* truck, sf::Sprite* sprite = nullptr);
	~SuperEnemy();
	bool Update(float deltatime);
	bool GetType();
	float Damaged(float playerdmg);
	float GetDamage();
	float GetRotation();

	void AddAnimation(sf::Sprite *sprite);

protected:
	float rotation;
	float m_damage;
	float m_cooldown;
	float m_hp;

	Animation *m_animation;
};