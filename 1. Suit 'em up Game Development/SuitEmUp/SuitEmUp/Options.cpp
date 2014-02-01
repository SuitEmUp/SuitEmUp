#include <iostream>
#include <SFML\Window.hpp>

#include "Options.h"
Options::Options()
{

}



Options::Options(InputManager* input) 
{
	m_input = input;
	next_state = "";
};

bool Options::Init()
{
	printf("State: Options,   Initialized\n");
	tempName_change = "02";

	return true;
};

void Options::Exit(){};

//bool Options::HandleInput()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//	{
//		setNextState("");
//		return false;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
//	{
//		setNextState("Options");
//		return false;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
//	{
//		setNextState("Customize");
//		return false;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
//	{
//		setNextState("Game");
//		return false;
//	}
//	return true;
//};

bool Options::Update()
{

	return true;
};

//draw

std::string Options::Next()
{
	return next_state;
};

void Options::setNextState(std::string state)
{
	next_state = state;
};

bool Options::IsType(const std::string &type)
{
	return type.compare("Options") == 0;
};


