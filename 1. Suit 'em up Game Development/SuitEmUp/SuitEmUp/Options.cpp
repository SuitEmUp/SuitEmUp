#include <iostream>
#include <SFML\Window.hpp>

#include "Options.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "Button.h"
#include "Slider.h"
#include "GameObjectManager.h"


Options::Options(Engine* engine) 
{

	next_state = "";
	m_engine = engine;
	m_input = m_engine->m_input;

};

bool Options::Init()
{
	m_fire_sprite = m_engine->m_spritemanager->Load("../data/Sprites/firespreadsheet.png", "fire", 1.3, 1.3);
	m_background = m_engine->m_spritemanager->Load("../data/Sprites/title.png", "bakgrund", 1.0, 1.0);

	printf("State: Options,   Initialized\n");
	tempName_change = "02";
	m_background = m_engine->m_spritemanager->Load("../data/Sprites/title.png", "bakgrund", 1.0, 1.0);

	m_sliders.push_back(new Slider(m_engine->m_spritemanager, "SoundSlider", sf::Vector2f(1280/2, 100), m_engine->m_soundlevel));
	m_sliders.push_back(new Slider(m_engine->m_spritemanager, "MusicSlider", sf::Vector2f(1280/2, 200), m_engine->m_musiclevel));
	m_sliders.push_back(new Slider(m_engine->m_spritemanager, "MasterVolumeSlider", sf::Vector2f(1280/2, 300), m_engine->m_mastervolumelevel));
	m_sliders.push_back(new Slider(m_engine->m_spritemanager, "VisualSlider", sf::Vector2f(1280/2, 400), m_engine->m_visuallevel));

	m_buttons.push_back(new Button(m_engine->m_soundmanager, m_engine->m_input, "BackButton", "Square", m_engine->m_spritemanager->Load("../data/buttons/back_button.png", "Back"), 70, 650-45));
	m_buttons.push_back(new Button(m_engine->m_soundmanager, m_engine->m_input, "ChangeMovement", "Square", m_engine->m_spritemanager->Load("../data/buttons/Special.png", "SpecialMove"), (1280/2)-(238/2), 500));

	//animation
	m_fire_sprite->setPosition(370.0f, 585.0f);
	m_fire = new Animation(m_fire_sprite, 0.2,false, true);
	m_fire->setSpriteSheet(m_fire_sprite);

	m_fire->addFrame(sf::IntRect (0, 0, 28, 23));
	m_fire->addFrame(sf::IntRect (34, 0, 28, 23));
	m_fire->addFrame(sf::IntRect (68, 0, 28, 23));
	m_fire->addFrame(sf::IntRect (102, 0, 28, 23));
	m_fire->addFrame(sf::IntRect (136, 0, 28, 23));
	
	for(int count=0;count<5;count++)
	{
		m_fire->update(0.1f, 1);
	}
	/*printf("State: Options,   Initialized\n");
	printf("F1 - F4 to Change States\n");
	tempName_change = "02";*/


	return true;
};

void Options::Exit()
{
	for(int i = 0; i< m_buttons.size(); i++){
		delete m_buttons[i];
		m_buttons.erase(m_buttons.begin()+i);
		i--;
	};
	m_buttons.clear();
	for(int i = 0; i< m_sliders.size(); i++){
		delete m_sliders[i];
		m_sliders.erase(m_sliders.begin()+i);
		i--;
	};
	m_sliders.clear();

	m_background = nullptr;
	std::cout<< m_engine->m_controltype << std::endl;
	delete m_fire;
	m_fire = nullptr;
};

bool Options::Update(float deltatime)
{
	m_fire_sprite->setPosition(370.0f, 585.0f);
	m_fire->update(deltatime, 1);

	for(int i=0; i<m_sliders.size(); i++){
		m_sliders.at(i)->Update(m_engine->m_input);
		if(m_sliders.at(i)->GetSliderType() == "SoundSlider"){
			m_engine->m_soundlevel = m_sliders.at(i)->GetLevel();
		}
		if(m_sliders.at(i)->GetSliderType() == "MusicSlider"){
			m_engine->m_musiclevel = m_sliders.at(i)->GetLevel();
		}
		if(m_sliders.at(i)->GetSliderType() == "MasterVolumeSlider"){
			m_engine->m_mastervolumelevel = m_sliders.at(i)->GetLevel();
		}
		if(m_sliders.at(i)->GetSliderType() == "VisualSlider"){
			m_engine->m_visuallevel = m_sliders.at(i)->GetLevel();
		}
	}

	//m_engine->m_gom->m_eyecandy->SetVisualQuality();

	for(int i=0; i<m_buttons.size(); i++){
		if(m_buttons.at(i)->Update() == "Clicked"){
			if(m_buttons.at(i)->GetType2() == "BackButton" && m_buttons.at(i)){
				m_engine->m_soundmanager->PlaySound("M4A1.wav");
				setNextState("MainMenu");
				return false;
			}
			else if(m_buttons.at(i)->GetType2() == "ChangeMovement" && m_buttons.at(i))
			{
				m_engine->m_soundmanager->PlaySound("M4A1.wav");
				if(m_engine->m_controltype == "Special")
				{
				m_engine->m_controltype = "Normal";
				m_buttons.at(i)->GetSprite()->setTexture(*m_engine->m_spritemanager->Load("../data/buttons/Normal.png", "NormalMove")->getTexture());
				std::cout<< "Normal controls!" << std::endl;
				}
				else {m_engine->m_controltype = "Special";	std::cout<< "Special controls!" << std::endl;
				m_buttons.at(i)->GetSprite()->setTexture(*m_engine->m_spritemanager->Load("../data/buttons/Special.png", "SpecialMove")->getTexture());}
			}
		}
	}


	/*if(m_input->IsDown(sf::Keyboard::F1))
	{
	printf("Next State set to MainMenu\n");
	setNextState("MainMenu");
	return false;
	};
<<<<<<< HEAD
	
=======
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

	m_engine->m_window->draw(*m_background);

	for(int i=0; i<m_sliders.size(); i++){
		m_engine->m_window->draw(*m_sliders.at(i)->GetSliderSprite());
	}
	for(int i=0; i<m_sliders.size(); i++){
		m_engine->m_window->draw(*m_sliders.at(i)->GetSprite());
	}
	for(int i=0; i<m_buttons.size(); i++){
		m_engine->m_window->draw(*m_buttons.at(i)->GetSprite());
	}
	m_engine->m_window->draw(*m_fire_sprite);
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
