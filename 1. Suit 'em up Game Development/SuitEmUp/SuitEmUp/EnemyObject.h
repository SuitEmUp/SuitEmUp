//EnemyObject.h

#pragma once

#include "MovingGameObject.h"
#include "Animation.h"

class SpriteManager;
class Truck;

class EnemyObject : public MovingGameObject{
public:
	EnemyObject(Truck* truck, SpriteManager* sm);
	~EnemyObject();
	bool Update(float deltatime);
	bool GetType();
	float Damaged(float playerdmg);
	float GetDamage();


	void AddAnimation(sf::Sprite *sprite);

protected:
	
	float m_cooldown;
	float m_hp;
	float m_damage;

	Animation *m_animation;

	sf::Sprite* m_shootingidle;
	sf::Sprite* m_shooting;
};