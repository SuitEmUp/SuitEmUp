//MovingGameObject.cpp

#include "MovingGameObject.h"

sf::Vector2f MovingGameObject::GetVelocity(){
	return m_velocity;
};

void MovingGameObject::SetVelocity(sf::Vector2f vel){
	m_velocity=vel;
};

sf::SoundBuffer* MovingGameObject::GetBuffer(){
	return m_buffer;
}

void MovingGameObject::SetBuffer(sf::SoundBuffer* buffer){
	m_buffer = buffer;
}

sf::Sound* MovingGameObject::GetSound(){
	return m_sound;
}

void MovingGameObject::SetSound(sf::Sound* sound){
	m_sound = sound;
}