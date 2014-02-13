#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>

class Button : public GameObject
{
public:
	Button(std::string p_ButtonName, sf::Sprite* p_Sprite, int x_Pos, int y_Pos);

	bool Update(/*deltatime*/);

	bool GetType(){return true;};

	std::string GetType2();

private:
	std::string m_Type;

};