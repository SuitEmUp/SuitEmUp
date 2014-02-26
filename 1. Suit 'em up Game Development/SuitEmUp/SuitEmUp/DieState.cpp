//DieState.cpp


#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "DieState.h"
#include "InputManager.h"
#include "SpriteManager.h"




DieState::DieState(Engine* engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;
	
};

bool DieState::Init()
{

	m_xbackground = m_engine->m_spritemanager->Load("../data/sprites/Background.png", "Background", 1, 1);
	m_xbackground->setPosition(0,0);

	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2<float>(150.0f, 150.0f));

	m_xbuttons.push_back(new Button(m_input, "Retry", "Square", m_engine->m_spritemanager->Load("../data/buttons/Start_Game.png", "StartGame"),

		(Config::getInt("window_w", 0)/2 - 119), Config::getInt("menu_top_padding", 0)));

	m_xbuttons.push_back(new Button(m_input, "HighScore", "Square", m_engine->m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"),

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0))));

	m_xbuttons.push_back(new Button(m_input, "Main", "Square" ,m_engine->m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"), 

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*2))));

	/*m_xbuttons.push_back(new Button(m_input, "QuitGame", "Square",m_engine->m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"), 

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*3))));*/
		

	printf("State: DieState,  Initialized\n");
	return true;
};
void DieState::Exit(){

	for(unsigned int i = 0; i < m_rects.size(); i++)
	{
		delete m_rects[i];
		m_rects[i] = nullptr;
	}
	m_rects.clear();

	for(unsigned int i = 0; i < m_xbuttons.size(); i++)
	{
		delete m_xbuttons[i];
		m_xbuttons[i] = nullptr;
	}
	m_xbuttons.clear();

};


bool DieState::Update(float deltatime)
{


		for(int i=0; i<m_xbuttons.size();i++)
		{
			if(m_xbuttons.at(i)->Update()== "Clicked" && m_xbuttons.at(i)->GetType2() == "Retry")
			{
				printf("Next State set to GameState\n");
				setNextState("Game");
				m_engine->m_paused = 1;
				return false;
			}
		/*	if(m_xbuttons.at(i)->Update()== "Clicked" && m_xbuttons.at(i)->GetType2() == "Customization")
			{
				printf("Next State set to highScore\n");
				setNextState("HighScore");
				
				return false;
			}*/
			if(m_xbuttons.at(i)->Update()== "Clicked" && m_xbuttons.at(i)->GetType2() == "Main")
			{
				printf("Next State set to MainMenu\n");
				setNextState("MainMenu");
				
				return false;
			}

		}

	return  true;
}

void DieState::Draw()
{
	//draw Background
	m_engine->m_window->draw(*m_xbackground);

	for(int i=0; i<m_xbuttons.size(); i++){
		if(m_xbuttons.at(i)!=nullptr){
			m_engine->m_window->draw(*m_xbuttons.at(i)->GetSprite()); // draws all buttons
		}
	}

	m_engine->m_gom->Dead();

};

std::string DieState::Next()
{
	return next_state;
};

void DieState::setNextState(std::string state)
{
	next_state = state;
};

bool DieState::IsType(const std::string &type)
{
	return type.compare("DieState") == 0;
};