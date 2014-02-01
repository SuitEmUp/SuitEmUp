#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "TitleScreen.h"
#include "InputManager.h"




TitleScreen::TitleScreen(InputManager* input) 
{
	m_input = input;
	next_state = "";
};

bool TitleScreen::Init()
{
	//-----------
	//sf::Font font;
	//if (!font.loadFromFile("../assets/fonts/AdobeGothicStd-Bold")) { printf("Could not load font\n"); }
	//sf::Text text;
	//text.setFont(font);
	//text.setString("Is this working?");
	//text.setCharacterSize(24);
	//text.setColor(sf::Color::Red);

	//m_InputManager = nullptr;

	//-----------



	printf("State: TitleScreen,  Initialized\n");
	return true;
};
void TitleScreen::Exit(){};



//bool MainMenu::HandleInput()
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
//		
//	}
//	return true;
//};

bool TitleScreen::Update()
{
	if(m_input->IsDown(sf::Keyboard::Space) || m_input->IsDown(sf::Keyboard::Return))
	{
		printf("Next State set to MainMenu\n");
		setNextState("MainMenu");
		return false;
	};
	return true;
}

//draw

std::string TitleScreen::Next()
{
	return next_state;
};

void TitleScreen::setNextState(std::string state)
{
	next_state = state;
};

bool TitleScreen::IsType(const std::string &type)
{
	return type.compare("TitleScreen") == 0;
};


