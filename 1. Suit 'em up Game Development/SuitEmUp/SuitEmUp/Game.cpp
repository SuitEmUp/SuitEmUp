#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Game.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "PlayerObject.h"
#include "Config.h"
#include "Score.h"
#include "SoundManager.h"


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
	m_engine->m_crosshair = m_engine->m_spritemanager->Load("../data/sprites/new.png", "crosshair", 1, 1);
	m_engine->m_crosshair->setOrigin(33/2,33/2);

	if(m_engine->m_paused == 1 || m_engine->m_paused == 3)
	{





		m_engine->m_gom->CreateGameObjects(m_engine->m_visuallevel);

	}

	/*popuplock = true;
	onepopuplock = false;*/
	m_engine->m_soundmanager->StopMusic("Campfire.wav");
	printf("State: Game,  Initialized\n");
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

	if(m_input->IsDown(sf::Keyboard::Tab) && Config::getInt("quickcustomize",0) == 1)
	{
		printf("Next State set to Customize\n");
		setNextState("Customize");
		m_engine->m_paused = 2;
		return false;
	};

	if(m_input->IsDown(sf::Keyboard::Escape))
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
