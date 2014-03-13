#include <iostream>
#include <SFML\Window.hpp>

#include "Options.h"
#include "InputManager.h"


Options::Options(Engine* engine) 
{

	next_state = "";
	m_engine = engine;
	m_input = m_engine->m_input;

};

bool Options::Init()
{

	printf("State: Options,   Initialized\n");
	printf("F1 - F4 to Change States\n");
	tempName_change = "02";
	m_background = m_engine->m_spritemanager->Load("../data/Sprites/title.png", "bakgrund", 1.0, 1.0);


	return true;
};

void Options::Exit(){};

bool Options::Update(float deltatime)
{
	if(m_input->IsDown(sf::Keyboard::F1))
	{
		printf("Next State set to MainMenu\n");
		setNextState("MainMenu");
		return false;
	};
	
	return true;
};

void Options::Draw()
{
	m_engine->m_window->draw(*m_background);
};
std::string Options::Next()
{
	return next_state;
};

void Options::setNextState(std::string state)
{
	next_state = state;
};

bool Options::IsType(const std::string &type)
{
	return type.compare("Options") == 0;
};


