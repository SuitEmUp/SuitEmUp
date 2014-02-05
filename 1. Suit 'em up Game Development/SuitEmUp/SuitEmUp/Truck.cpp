//Truck.cpp

#include "Truck.h"

Truck::Truck(sf::Sprite* sprite){
	m_sprite = sprite;
	m_sprite->setOrigin((m_sprite->getLocalBounds().height)/2, (m_sprite->getLocalBounds().width)/2);
	m_hp = 20;
	m_position=sf::Vector2f(1280/2, 720/2);
};

bool Truck::Update(){
	//if hit by enemybullet m_hp -=1;
	//if hp=0, return true
	m_sprite->setPosition(m_position);
	return false;
};

sf::Vector2f Truck::GetVelocity(){
	return m_velocity;
};

void Truck::SetVelocity(sf::Vector2f vel){
	m_velocity=vel;
};

bool Truck::GetType(){
	return true;
};