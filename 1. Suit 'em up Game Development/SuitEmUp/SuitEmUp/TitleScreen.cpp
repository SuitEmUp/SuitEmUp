#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "TitleScreen.h"
#include "InputManager.h"
#include "SpriteManager.h"




TitleScreen::TitleScreen(InputManager *input, GameObjectManager* gom) 
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
	printf("Press SPACE or RETURN to enter MainMenu\n");
	return true;
};
void TitleScreen::Exit(){};


bool TitleScreen::Update(float deltatime)
{
	if(m_input->IsDown(sf::Keyboard::Space) || m_input->IsDown(sf::Keyboard::Return))
	{
		printf("Next State set to MainMenu\n");
		setNextState("MainMenu");
		return false;
	};
	return true;
}

void TitleScreen::Draw()
{

};

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


