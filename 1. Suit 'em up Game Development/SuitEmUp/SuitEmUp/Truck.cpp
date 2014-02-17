//Truck.cpp

#include "Truck.h"
#include "EnemyProjectile.h"

Truck::Truck(sf::Sprite* sprite){
	m_sprite = sprite;
	m_sprite->setOrigin((m_sprite->getLocalBounds().width)/2, (m_sprite->getLocalBounds().height)/2);
	m_hp = 100;
	m_position=sf::Vector2f(1280/2, 720/2);
};

bool Truck::Update(float deltatime){
	m_sprite->setPosition(m_position);
	if(m_hp>100){m_hp=100;}
	if(m_hp<1) return true;
	return false;
};
float Truck::UpdateHP()
{
	return m_hp;
}

sf::Vector2f Truck::GetVelocity(){
	return m_velocity;
};

void Truck::SetVelocity(sf::Vector2f vel){
	m_velocity=vel;
};

bool Truck::GetType(){
	return true;
};

void Truck::Damaged(){
	m_hp--;
}

void Truck::Healed(){
	m_hp+=100;
}