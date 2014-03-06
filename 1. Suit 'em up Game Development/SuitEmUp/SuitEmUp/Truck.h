// Truck.h

#pragma once;


#include "GameObject.h"
#include "Animation.h"

class EnemyProjectile;

class Truck : public GameObject
{
	friend class Animation;
public:

	Truck(sf::Sprite* sprite = nullptr, sf::Sprite* sprite2 = nullptr,sf::Sprite* sprite3 = nullptr,sf::Sprite* sprite4= nullptr);
	bool Update(float deltatime);
	sf::Vector2f GetVelocity();
	void SetVelocity(sf::Vector2f vel);
	bool GetType();
	void Damaged(float damage);
	void Healed();
	float UpdateHP();

	void Set_Animation(sf::Sprite *m_xsprite,int sprite_number);

protected:

	float m_hp;
	float m_maxhp;

	std::vector<sf::Sprite*>sprite_truck;


	sf::Vector2f m_velocity;

	Animation *m_truck_hp;
	Animation *m_truck_lowhp;
};