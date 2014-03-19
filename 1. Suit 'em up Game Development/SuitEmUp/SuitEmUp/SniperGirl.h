//SniperGirl.h

#pragma once

#include "MovingGameObject.h"

class Truck;
class SpriteManager;

class SniperGirl : public MovingGameObject{
public:
	SniperGirl(Truck* truck, SpriteManager* sm);
	~SniperGirl();
	bool Update(float deltatime);
	bool GetType();
	float Damaged(float playerdmg);
	float GetDamage();

	void AddAnimation(sf::Sprite *sprite);

protected:
	float m_cooldown;
	float m_hp;
	float m_damage;
	//sf::SoundBuffer *m_buffer;
	//sf::Sound *m_sound;
	Animation *m_animation;

	sf::Sprite* m_shooting;
};