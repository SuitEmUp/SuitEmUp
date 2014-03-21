#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Game.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "PlayerObject.h"
#include "Config.h"
#include "Score.h"


Game::Game(Engine *engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;
	m_engine->m_paused = 1;
	m_popup = nullptr;
	m_score = 0;
	popuplock = true;
	onepopuplock = false;


};
bool Game::Init()
{

	if(m_engine->m_paused == 1 || m_engine->m_paused == 3)
	{
		printf("\n nu aer vi haer inne \n");
		m_engine->m_gom->CreateGameObjects(m_engine->m_visuallevel);
	}

	/*popuplock = true;
	onepopuplock = false;*/

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
bool Game::Update(float deltatime)
{
	if(popuplock == false)
	{
		m_popup = new Popup(m_input, "Tessst", "TESTINGWOOOO", m_engine->m_gom->m_spritemanager->Load("../data/Sprites/popuptext.png", "popup"), 1280 - 310, 720 - 100);
		popuplock = true;
	}

	m_score = m_engine->m_gom->GetScore(m_score);

	m_engine->m_gom->Update(deltatime);
	if(m_popup != nullptr)
	{
		m_popup->Update();
		if(!m_popup->exists())
		{
			delete m_popup;
			m_popup = nullptr;
			if(m_popup == nullptr)
				printf("Popup deleted woooo\n");
		}
	}


	m_deltatime = deltatime;

	if(m_input->IsDown(sf::Keyboard::F1))
	{
		printf("Next State set to mainMenu\n");
		setNextState("MainMenu");
		return false;
	};
	if(m_input->IsDown(sf::Keyboard::Tab) && Config::getInt("quickcustomize",0) == 1)
	{
		printf("Next State set to Customize\n");
		setNextState("Customize");
		m_engine->m_paused = 2;
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
	if(m_engine->m_gom->m_game_over)
	{
		printf("Next State set to DieState\n");
		setNextState("DieState");
		m_engine->m_paused = 2;

		return false;
	}
	if(m_score >= 1000 && onepopuplock == false)
	{
		popuplock = false;
		onepopuplock = true;
	}


	return true;
}
void Game::Draw(){
	m_engine->m_gom->DrawGameObjects(m_deltatime);

	if(m_popup != nullptr)
		m_engine->m_gom->m_window->draw(*m_popup->GetSprite());
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
