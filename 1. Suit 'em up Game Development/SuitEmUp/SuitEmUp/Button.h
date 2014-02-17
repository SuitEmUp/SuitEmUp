#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>
#include "InputManager.h"

class Button : public GameObject
{
public:
	Button(InputManager* p_input, std::string p_ButtonName, sf::Sprite* p_Sprite, int x_Pos, int y_Pos);

	std::string Update();

	bool GetType(){return true;};

	std::string GetType2();

private:
	std::string m_Type;
	InputManager* m_input;

};