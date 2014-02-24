#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Game.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "PlayerObject.h"


Game::Game(Engine *engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;
	m_engine->m_paused = 1;


};
bool Game::Init()
{

	if(m_engine->m_paused == 1 || m_engine->m_paused == 3)
	{
		printf("nu aer vi haer inne\n");
		m_engine->m_gom->CreateGameObjects();
	}
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
	return true;
};

void Game::Exit(){


	if(m_engine->m_paused == 1)
	{
		m_engine->m_gom->ClearGameObjects();
	};


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

bool Game::Update(float deltatime)
{
	m_engine->m_gom->Update(deltatime);
	if(m_input->IsDown(sf::Keyboard::F1)||m_engine->m_gom->m_game_over)
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

	if(m_input->IsDown(sf::Keyboard::P))
	{
		printf("Next State set to PausState\n");
		setNextState("PausState");
		m_engine->m_paused = 2;
		return false;
	};

	return true;
}

//draw
void Game::Draw(/*sf::RenderWindow *p_window*/){
	m_engine->m_gom->DrawGameObjects();
};

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
