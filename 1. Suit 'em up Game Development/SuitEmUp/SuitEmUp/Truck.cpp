//Truck.cpp

#include "Truck.h"

Truck::Truck(sf::Sprite* sprite){
	m_sprite = sprite;
	m_hp = 20;
	m_position=sf::Vector2f(1280/2, 720/2);
};

bool Truck::Update(){
	//if hit by enemybullet m_hp -=1;
	//if hp=0, return true
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