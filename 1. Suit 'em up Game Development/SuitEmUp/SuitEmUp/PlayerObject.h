//PlayerObject.h

#pragma once

#include "MovingGameObject.h"
#include <SFML/Audio.hpp>

class Truck;
class InputManager;

class PlayerObject : public MovingGameObject
{
public:
	PlayerObject(Truck* truck, InputManager* input, sf::Sprite* sprite = nullptr, sf::Sprite* update = nullptr);
	~PlayerObject();
	bool Update(float deltatime);
	bool GetType();
	float GetDamage();
	sf::Vector2f GetDirection();

	void SetSuitType(std::string p_suittype);
	void SetWeaponType(std::string p_weapontype);
	void SetTruckType(std::string p_trucktype);

private:
	InputManager* m_input;
	float m_damage;
	float m_cooldown;
	float m_attackspeed;
	sf::Vector2f m_direction;
	sf::Sprite* m_update;
	sf::Sprite* m_unupdate;
	sf::SoundBuffer* m_buffer2;
	sf::Sound* m_sound2;


	std::string m_suittype;
	std::string m_weapontype;
	std::string m_trucktype;

};