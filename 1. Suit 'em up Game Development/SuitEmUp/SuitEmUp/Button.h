#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>

class Button : public GameObject
{
public:
	Button(std::string p_Output, sf::Sprite* p_Sprite);

	bool Update(/*deltatime*/);
	std::string GetOutput();

	bool GetType(){ return true;};

private:
	//sf::Vector2f m_extention;
	std::string m_output;


};