//HighScoreState.cpp

#include <iostream>
#include <SFML\Window.hpp>

#include "HighScoreState.h"
#include "InputManager.h"


HighScore::HighScore(Engine* engine) 
{
	
	next_state = "";
	m_engine = engine;
	m_input = m_engine->m_input;

};

bool HighScore::Init()
{
	
	printf("State: Options,   Initialized\n");
	printf("F1 - F4 to Change States\n");
	tempName_change = "02";

	return true;
};

void HighScore::Exit(){};

bool HighScore::Update(float deltatime)
{
	if(m_input->IsDown(sf::Keyboard::F1))
	{
		printf("Next State set to MainMenu\n");
		setNextState("MainMenu");
		return false;
	};
	if(m_input->IsDown(sf::Keyboard::F2))
	{
		printf("Next State set to Game\n");
		setNextState("Game");
		return false;
	};
	if(m_input->IsDown(sf::Keyboard::F3))
	{
		printf("Next State set to Customize\n");
		setNextState("Customize");
		return false;
	};
	return true;
};

void HighScore::Draw()
{

};
std::string HighScore::Next()
{
	return next_state;
};

void HighScore::setNextState(std::string state)
{
	next_state = state;
};

bool HighScore::IsType(const std::string &type)
{
	return type.compare("HighScore") == 0;
};

