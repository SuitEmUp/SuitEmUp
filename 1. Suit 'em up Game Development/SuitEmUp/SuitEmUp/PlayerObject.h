//PlayerObject.h

#pragma once

#include "MovingGameObject.h"
#include <SFML/Audio.hpp>
#include "SpriteManager.h"

class Truck;
class InputManager;

class PlayerObject : public MovingGameObject
{
public:
	//PlayerObject(Truck* truck, InputManager* input, sf::Sprite* sprite = nullptr, sf::Sprite* update = nullptr);
	PlayerObject(Truck* truck, InputManager* input, sf::Sprite* sprite, SpriteManager* p_spritemanager);
	~PlayerObject();
	bool Update(float deltatime);
	bool GetType();
	float GetDamage();
	sf::Vector2f GetDirection();

	void SetSuitType(std::string p_suittype);
	void SetWeaponType(std::string p_weapontype);
	void SetTruckType(std::string p_trucktype);

	std::string GetWeaponType();
	std::string GetSuitType();
	std::string GetTruckType();

private:
	
	SpriteManager* m_spritemanager;
	InputManager* m_input;
	float m_damage;
	float m_cooldown;
	float m_attackspeed;
	sf::Vector2f m_direction;

	sf::Sprite* m_Level1Weapon1;
	sf::Sprite* m_Level1Weapon2;
	sf::Sprite* m_Level1Weapon3;

	sf::Sprite* m_Level2Weapon1;
	sf::Sprite* m_Level2Weapon2;
	sf::Sprite* m_Level2Weapon3;

	sf::Sprite* m_Level3Weapon1;
	sf::Sprite* m_Level3Weapon2;
	sf::Sprite* m_Level3Weapon3;

	

	std::string m_firetype;
	std::string m_controltype;

	std::string m_suittype;
	std::string m_weapontype;
	std::string m_trucktype;

};