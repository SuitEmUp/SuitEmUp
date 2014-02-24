//MovingGameObject.h

#pragma once

#include "GameObject.h"
#include <SFML/Audio.hpp>


class Truck;

class MovingGameObject : public GameObject
{
public:
	sf::Vector2f GetVelocity();
	void SetVelocity(sf::Vector2f vel);
	int GetSpeed();
	int SetSpeed(int s);
	sf::SoundBuffer* GetBuffer();
	void SetBuffer(sf::SoundBuffer* buffer);
	sf::Sound* GetSound();
	void SetSound(sf::Sound* sound);

protected:
	float speed;
	sf::Vector2f m_velocity;
	Truck* m_truck;
	sf::SoundBuffer* m_buffer;
	sf::Sound* m_sound;
};