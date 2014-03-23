//MovingGameObject.cpp

#include "MovingGameObject.h"

sf::Vector2f MovingGameObject::GetVelocity(){
	return m_velocity;
};

void MovingGameObject::SetVelocity(sf::Vector2f vel){
	m_velocity=vel;
};
void MovingGameObject::SetSpeed(float s)
{
	 speed  = s;
}
