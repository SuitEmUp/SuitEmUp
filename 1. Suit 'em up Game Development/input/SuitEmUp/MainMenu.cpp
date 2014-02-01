#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include "InputManager.h"
#include "MainMenu.h"




MainMenu::MainMenu(InputManager *input) 
{
	m_input = input;
	next_state = "";
};

bool MainMenu::Init()
{
	//-----------
	//sf::Font font;
	//if (!font.loadFromFile("../assets/fonts/AdobeGothicStd-Bold")) { printf("Could not load font\n"); }
	//sf::Text text;
	//text.setFont(font);
	//text.setString("Is this working?");
	//text.setCharacterSize(24);
	//text.setColor(sf::Color::Red);

	
	
	//-----------
	printf("State: MainMenu,  Initialized\n");
	return true;
};
void MainMenu::Exit(){};


//Update should be bool
bool MainMenu::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		setNextState("");
		return false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		setNextState("Options");
		return false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		setNextState("Customize");
		return false;
	}

	return true;
};

//draw

std::string MainMenu::Next()
{
	return next_state;
};

void MainMenu::setNextState(std::string state)
{
	next_state = state;
};

bool MainMenu::IsType(const std::string &type)
{
	return type.compare("MainMenu") == 0;
};


