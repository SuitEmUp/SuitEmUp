#include <iostream>
#include "SFML\Window.hpp"

#include "Options.h"




Options::Options() 
{
	next_state = "";
};

bool Options::Init()
{
	printf("State: Options,   Initialized\n");
	tempName_change = "02";

	return true;
};
void Options::Exit(){};


bool Options::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		setNextState("");
		return false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		setNextState("Customize");
		return false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		setNextState("MainMenu");
		return false;
	}

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


