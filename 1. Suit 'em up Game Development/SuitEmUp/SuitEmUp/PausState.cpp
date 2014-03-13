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

};

bool PausState::Init()
{

	m_vbackground = m_engine->m_spritemanager->Load("../data/sprites/Background.png", "Background", 1, 1);
	m_vbackground->setPosition(0,0);

	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2<float>(150.0f, 150.0f));

	m_buttons.push_back(new Button(m_input, "Resume", "Square", m_engine->m_spritemanager->Load("../data/buttons/Resume.png", "StartGame"),

		(Config::getInt("window_w", 0)/2 - 119), Config::getInt("menu_top_padding", 0)));

	m_buttons.push_back(new Button(m_input, "Customization", "Square", m_engine->m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"),

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0))));

	m_buttons.push_back(new Button(m_input, "MainMenu", "Square" ,m_engine->m_spritemanager->Load("../data/buttons/Main_Menu.png", "QuitGame"), 

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*2))));

	m_glow1 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow1",  1.0f, 1.0f);
	m_glow1->setPosition(Config::getInt("window_w", 0)/2 - 119, Config::getInt("menu_top_padding", 0));

	m_glow2 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow2",  1.0f, 1.0f);
	m_glow2->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)));

	m_glow3 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow3",  1.0f, 1.0f);
	m_glow3->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)*2));



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

	if(m_engine->m_paused == 1)
	{
		Config::set("current_suit", "0");
		Config::set("current_weapon", "0");
		Config::set("current_truck", "0");
		Config::set("weapons_available", "1");
		Config::renew();
		m_engine->m_paused = 0;
	}

};


bool PausState::Update(float deltatime)
{


	for(int i=0; i<m_buttons.size();i++)
	{
		if(m_buttons.at(i)->Update()== "Clicked" && m_buttons.at(i)->GetType2() == "Resume")
		{
			printf("Next State set to GameState\n");
			setNextState("Game");
			return false;
		}
		if(m_buttons.at(i)->Update()== "Clicked" && m_buttons.at(i)->GetType2() == "Customization")
		{
			printf("Next State set to Customize\n");
			setNextState("Customize");
			return false;
		}
		if(m_buttons.at(i)->Update()== "Clicked" && m_buttons.at(i)->GetType2() == "MainMenu")
		{
			printf("Next State set to MainMenu\n");
			m_engine->m_gom->ClearGameObjects();
			setNextState("MainMenu");
			m_engine->m_paused = 1;
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

	for(int i = 0; i < m_buttons.size(); i++)
	{
		if(m_buttons.at(i)->Update() == "Hovering" && m_buttons.at(i)->GetType2() == "Resume"){
			m_engine->m_window->draw(*m_glow1);
		};
		if(m_buttons.at(i)->Update() == "Hovering" && m_buttons.at(i)->GetType2() == "Customization"){
			m_engine->m_window->draw(*m_glow2);
		};
		if(m_buttons.at(i)->Update() == "Hovering" && m_buttons.at(i)->GetType2() == "MainMenu"){
			m_engine->m_window->draw(*m_glow3);
		};
	};

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