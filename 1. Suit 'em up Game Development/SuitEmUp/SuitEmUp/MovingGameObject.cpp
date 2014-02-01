//MovingGameObject.cpp

#include "MovingGameObject.h"

sf::Vector2u MovingGameObject::GetVelocity(){
	return m_velocity;
};

void MovingGameObject::SetVelocity(sf::Vector2u vel){
	m_velocity=vel;
};