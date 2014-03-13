#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "MainMenu.h"
#include "InputManager.h"
#include "SpriteManager.h"

#include "Button.h"
#include "Config.h"




MainMenu::MainMenu(Engine *engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;

	m_buffer = new sf::SoundBuffer();
	m_buffer->loadFromFile("../data/sounds/M4A1.wav");
	m_clicksound = new sf::Sound();
	m_clicksound->setBuffer(*m_buffer);
	m_clicksound->setVolume(200);
	m_clicksound->setPitch(2);

	m_canclick = false;
	m_oneclicklock = false;



};

bool MainMenu::Init()
{

	printf("State: MainMenu,  Initialized\n");
	printf("F1 - F4 to Change States\n");

	m_xbackground = m_engine->m_spritemanager->Load("../data/Sprites/title.png", "bakgrund", 1.0, 1.0);

	m_logo = m_engine->m_spritemanager->Load("../data/misc/PlaceholderLogo.png", "Logo", 1.0f, 1.0f);
	m_logo->setOrigin(m_logo->getLocalBounds().width / 2, 0);
	m_logo->setPosition(Config::getInt("window_w", 0) / 2, Config::getInt("logoypos", 0));

	m_glow1 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow1",  1.0f, 1.0f);
	m_glow1->setPosition(Config::getInt("window_w", 0)/2 - 119, Config::getInt("menu_top_padding", 0));

	m_glow2 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow2",  1.0f, 1.0f);
	m_glow2->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)));

	m_glow3 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow3",  1.0f, 1.0f);
	m_glow3->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)*2));

	m_glow4 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow4",  1.0f, 1.0f);
	m_glow4->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)*3));

	m_engine->m_gom->CreateButtons();



	return true;
};
void MainMenu::Exit()
{
	m_engine->m_gom->EraseButtons();
};

bool MainMenu::Update(float deltatime)
{

	for(int i = 0; i < m_engine->m_gom->m_vButtons.size(); i++)
	{

		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked" && m_engine->m_gom->m_vButtons.at(i)->GetType2() == "StartGame"){
			printf("Click SUCCESSSSS\n");
			printf("Next State set to Game\n");
			setNextState("Game");
			m_engine->m_paused = 3; //through mainmenu
			return false;
		}

		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked" && m_engine->m_gom->m_vButtons.at(i)->GetType2() == "HighScore"){
			printf("Click SUCCESSSSS\n");
			printf("Next State set to Highscore\n");
			setNextState("HighScoreState");
			return false;
		}
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked" && m_engine->m_gom->m_vButtons.at(i)->GetType2() == "Options"){

			printf("Click SUCCESSSSS\n");
			printf("Next State set to Options\n");
			setNextState("Options");
			return false;
		}
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked" && m_engine->m_gom->m_vButtons.at(i)->GetType2() == "QuitGame"){

			m_engine->m_running = false;
			printf("Click SUCCESSSSS\n");
			printf("This button doesnt work yet\n");
			//Exit Game

			if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked"){

				if(m_engine->m_gom->m_vButtons.at(i)->GetType2() == "StartGame"){
					m_clicksound->play();
					printf("Click SUCCESSSSS\n");
					printf("Next State set to Game\n");
					setNextState("Game");
					m_engine->m_paused = 3; //through mainmenu

					return false;
				}

				if(m_engine->m_gom->m_vButtons.at(i)->GetType2() == "HighScore"){
					m_clicksound->play();
					printf("Click SUCCESSSSS\n");
					printf("HighScore-state does not exist\n");
				}
				if( m_engine->m_gom->m_vButtons.at(i)->GetType2() == "Options"){
					m_clicksound->play();

					printf("Click SUCCESSSSS\n");
					printf("Next State set to Options\n");
					setNextState("Options");
					return false;
				}
				if(m_engine->m_gom->m_vButtons.at(i)->GetType2() == "QuitGame"){
					m_clicksound->play();
					printf("Click SUCCESSSSS\n");
					printf("This button doesnt work yet\n");
					//Exit Game
				}

			}
		}
	}
	return true;
}


void MainMenu::Draw()
{
	m_engine->m_window->draw(*m_xbackground);
	m_engine->m_gom->DrawButtons();
	m_engine->m_window->draw(*m_logo);

	for(int i = 0; i < m_engine->m_gom->m_vButtons.size(); i++)
	{
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Hovering" &&m_engine->m_gom->m_vButtons.at(i)->GetType2() == "StartGame"){
			m_engine->m_window->draw(*m_glow1);
		};
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Hovering" &&m_engine->m_gom->m_vButtons.at(i)->GetType2() == "HighScore"){
			m_engine->m_window->draw(*m_glow2);
		};
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Hovering" &&m_engine->m_gom->m_vButtons.at(i)->GetType2() == "Options"){
			m_engine->m_window->draw(*m_glow3);
		};
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Hovering" &&m_engine->m_gom->m_vButtons.at(i)->GetType2() == "QuitGame"){
			m_engine->m_window->draw(*m_glow4);
		}
	}
};
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


