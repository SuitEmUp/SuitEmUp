#include <iostream>
#include <SFML\Window.hpp>

#include "Options.h"
#include "InputManager.h"
#include "Button.h"
#include "Slider.h"


Options::Options(Engine* engine) 
{

	next_state = "";
	m_engine = engine;
	m_input = m_engine->m_input;

};

bool Options::Init()
{
	m_sliders.push_back(new Slider(m_engine->m_spritemanager, "SoundSlider", sf::Vector2f(1080/2, 100)));
	m_sliders.push_back(new Slider(m_engine->m_spritemanager, "MusicSlider", sf::Vector2f(1080/2, 200)));
	m_sliders.push_back(new Slider(m_engine->m_spritemanager, "VisualSlider", sf::Vector2f(1080/2, 300)));

	m_buttons.push_back(new Button(m_engine->m_input, "BackButton", "Square", m_engine->m_spritemanager->Load("../data/buttons/back_button.png", "Back"), 100, 100));


	/*printf("State: Options,   Initialized\n");
	printf("F1 - F4 to Change States\n");
	tempName_change = "02";*/

	return true;
};

void Options::Exit(){};

bool Options::Update(float deltatime)
{
	for(int i=0; i<m_sliders.size(); i++){
		m_sliders.at(i)->Update(m_engine->m_input);
		if(m_sliders.at(i)->GetSliderType() == "SoundSlider"){
			m_engine->m_soundlevel = m_sliders.at(i)->GetLevel();
		}
		if(m_sliders.at(i)->GetSliderType() == "MusicSlider"){
			m_engine->m_musiclevel = m_sliders.at(i)->GetLevel();
		}
		if(m_sliders.at(i)->GetSliderType() == "VisualSlider"){
			m_engine->m_visuallevel = m_sliders.at(i)->GetLevel();
		}
	}

	for(int i=0; i<m_buttons.size(); i++){
		m_buttons.at(i)->Update();
		if(m_buttons.at(i)->GetType2() == "BackButton"){
			setNextState("MainMenu");
			return false;
		}
	}


	/*if(m_input->IsDown(sf::Keyboard::F1))
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
	};*/
	return true;
};

void Options::Draw()
{

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


