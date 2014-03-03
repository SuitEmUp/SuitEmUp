#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>
#include "InputManager.h"

class Trinket : public GameObject
{
public:
	Trinket(std::string p_TrinketType, std::string p_TrinketMode,  sf::Sprite* p_Sprite, int x_Pos, int y_Pos);

	std::string Update();

	bool GetType(){return true;};

	std::string GetType2();
	int GetMode();
	sf::Vector2f GetPos();

private:
	std::string m_Type;
	int m_Mode;


};