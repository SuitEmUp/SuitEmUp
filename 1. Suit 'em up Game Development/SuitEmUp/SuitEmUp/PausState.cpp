//PausState.cpp

#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "PausState.h"
#include "InputManager.h"
#include "SpriteManager.h"




PausState::PausState(Engine* engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;
	//paused = true;
};

bool PausState::Init()
{

	m_vbackground = m_engine->m_spritemanager->Load("../data/sprites/Background.png", "Background", 1, 1);
	m_vbackground->setPosition(0,0);

	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2<float>(150.0f, 150.0f));

	m_buttons.push_back(new Button(m_input, "Resume", "Square", m_engine->m_spritemanager->Load("../data/buttons/Start_Game.png", "StartGame"),

		(Config::getInt("window_w", 0)/2 - 119), Config::getInt("menu_top_padding", 0)));

	m_buttons.push_back(new Button(m_input, "Customization", "Square", m_engine->m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"),

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0))));

	m_buttons.push_back(new Button(m_input, "MainMenu", "Square" ,m_engine->m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"), 

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*2))));

	/*m_buttons.push_back(new Button(m_input, "QuitGame", "Square",m_engine->m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"), 

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*3))));*/
		

	printf("State: PausState,  Initialized\n");
	return true;
};
void PausState::Exit(){

	for(unsigned int i = 0; i < m_rects.size(); i++)
	{
		delete m_rects[i];
		m_rects[i] = nullptr;
	}
	m_rects.clear();

	for(unsigned int i = 0; i < m_buttons.size(); i++)
	{
		delete m_buttons[i];
		m_buttons[i] = nullptr;
	}
	m_buttons.clear();

};


bool PausState::Update(float deltatime)
{


		//m_engine->m_gom->DrawGameObjects();

		for(int i=0; i<m_buttons.size();i++)
		{
			if(m_buttons.at(i)->Update()== "Clicked" && m_buttons.at(i)->GetType2() == "Resume")
			{
				printf("Next State set to GameState\n");
				setNextState("Game");
				//paused = false;
				return false;
			}
			if(m_buttons.at(i)->Update()== "Clicked" && m_buttons.at(i)->GetType2() == "Customization")
			{
				printf("Next State set to Customize\n");
				setNextState("Customize");
				//paused = false;
				return false;
			}
			if(m_buttons.at(i)->Update()== "Clicked" && m_buttons.at(i)->GetType2() == "MainMenu")
			{
				printf("Next State set to MainMenu\n");
				setNextState("MainMenu");
				//paused = false;
				return false;
			}

		}

	return  true;
}

void PausState::Draw()
{
	//draw Background
	m_engine->m_window->draw(*m_vbackground);

	for(int i=0; i<m_buttons.size(); i++){
		if(m_buttons.at(i)!=nullptr){
			m_engine->m_window->draw(*m_buttons.at(i)->GetSprite()); // draws all buttons
		}
	}

};

std::string PausState::Next()
{
	return next_state;
};

void PausState::setNextState(std::string state)
{
	next_state = state;
};

bool PausState::IsType(const std::string &type)
{
	return type.compare("PausState") == 0;
};