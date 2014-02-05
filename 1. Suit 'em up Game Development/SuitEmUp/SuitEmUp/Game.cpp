#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Game.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "PlayerObject.h"


Game::Game(InputManager* input) 
{
	m_input = input;
	next_state = "";
};

bool Game::Init()
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
	printf("State: Game,  Initialized\n");
	printf("F1 - F4 to Change States\n");
	m_gom=new GameObjectManager();
	return true;
};

void Game::Exit(){
	if(m_gom!=nullptr){
		delete m_gom;
		m_gom = nullptr;
	}

};



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

bool Game::Update()
{

	m_gom->Update();

	if(m_input->IsDown(sf::Keyboard::F1))
	{
		printf("Next State set to mainMenu\n");
		setNextState("MainMenu");
		return false;
	};
	if(m_input->IsDown(sf::Keyboard::F3))
	{
		printf("Next State set to Customize\n");
		setNextState("Customize");
		return false;
	};
	if(m_input->IsDown(sf::Keyboard::F4))
	{
		printf("Next State set to Options\n");
		setNextState("Options");
		return false;
	};
	return true;
}

//draw

std::string Game::Next()
{
	return next_state;
};

void Game::setNextState(std::string state)
{
	next_state = state;
};

bool Game::IsType(const std::string &type)
{
	return type.compare("Game") == 0;
};
