
#include "Engine.h"

#include "StateManager.h"
#include "SpriteManager.h"

#include "MainMenu.h"
#include "Options.h"
#include "Customize.h"
#include "Game.h"
#include "TitleScreen.h"
#include "PausState.h"
#include "DieState.h"
#include "HighScoreState.h"
#include "Highscore.h"

#include "InputManager.h"//Ladbon
#include "DrawManager.h"
#include "GameObjectManager.h"
#include "ButtonManager.h"

#include "SoundManager.h"

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

#include "Config.h"
#include <iostream>


Engine::Engine()
{

	m_ehighscore = nullptr;
	m_running = false;//Ladbon
	m_window = nullptr;
	m_input = nullptr;
	m_statemanager = nullptr;
	m_spritemanager = nullptr;
	m_crosshair = nullptr;
	m_soundmanager = nullptr;

	m_fDeltaTime = 0.01f;

	m_soundlevel = 50;
	m_visuallevel = 50;
	m_musiclevel = 50;
	m_mastervolumelevel = 50;

	m_paused = 1; // false 

	m_controltype = "Special";
};

bool Engine::Initialize()
{
	m_soundmanager = new SoundManager();
	m_soundmanager->Initialize("../data/sounds/");
	m_statemanager = new StateManager();

	if(Config::getBool("fullscreen", false) == true)
		m_window = new sf::RenderWindow(sf::VideoMode(Config::getInt("window_w", 0), Config::getInt("window_h", 0)), "SFML window", sf::Style::Fullscreen);
	if(Config::getBool("fullscreen", false) == false)
		m_window = new sf::RenderWindow(sf::VideoMode(Config::getInt("window_w", 0), Config::getInt("window_h", 0)), "SFML window", sf::Style::Default);

	m_input = new InputManager(m_window);
	m_spritemanager = new SpriteManager();
	m_gom = new GameObjectManager(m_spritemanager, m_window, m_input, m_soundmanager, &m_controltype);
	m_buttonmanager = new ButtonManager(m_spritemanager, m_input);
	m_ehighscore = new Highscore();

	m_ehighscore->Load();

	if(m_window == nullptr)
	{
		return false;
	}

	//crosshair
	m_window->setMouseCursorVisible(false);
	m_crosshair = m_spritemanager->Load("../data/sprites/crosshair.png", "crosshair", 1, 1);
	m_crosshair->setOrigin(32/2,32/2);
	//m_statemanager->SetInput(m_input);

	if(m_statemanager != nullptr)
	{

		m_statemanager->Attach(new TitleScreen(this));
		m_statemanager->Attach(new MainMenu(this));
		m_statemanager->Attach(new Options(this));
		m_statemanager->Attach(new Customize(this));
		m_statemanager->Attach(new Game(	this));
		m_statemanager->Attach(new PausState(this));
		m_statemanager->Attach(new DieState(this));
		m_statemanager->Attach(new HighScoreState(this));
		m_statemanager->SetState("TitleScreen");
	}
	m_running = true;

	m_window->setFramerateLimit(60);
	return true;
};
void Engine::Run()
{
	while(m_running)
	{
		m_crosshair->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*m_window)));

		UpdateDeltatime();
		//	m_statemanager->HandleEvents();
		m_statemanager->Update(m_fDeltaTime);
		m_window->clear();
		m_statemanager->Draw(/*m_window*/);
		m_window->draw(*m_crosshair);
		m_window->display();
		m_input->PostMouseUpdate();
		m_input->PostKeyboardUpdate();
		m_input->HandleInput(m_running, m_input, m_statemanager);

		m_soundmanager->SetSoundVolume(m_soundlevel);
		m_soundmanager->SetMusicVolume(m_musiclevel);
		m_soundmanager->SetMasterVolume(m_mastervolumelevel);

		//std::cout << m_running << std::endl;
	}
	m_window->close();
};
void Engine::Cleanup()
{
	//Resets stuff in the config-file
	Config::set("current_suit", "0");
	Config::set("current_weapon", "0");
	Config::set("current_truck", "0");
	Config::set("weapons_available", "1");
	Config::renew();

	if(m_spritemanager != nullptr){
		delete m_spritemanager;
		m_spritemanager=nullptr;
	}

	if(m_window != nullptr){
		delete m_window;
		m_window=nullptr;
	}

	m_statemanager->Cleanup();
	delete m_statemanager;
	m_statemanager = nullptr;

	if(m_gom != nullptr){
		delete m_gom;
		m_gom=nullptr;
	}

	if(m_buttonmanager !=nullptr)
	{
		delete m_buttonmanager;
		m_buttonmanager = nullptr;
	}
	if(m_ehighscore != nullptr)
	{
		delete m_ehighscore;
		m_ehighscore = nullptr;
	}
};
void Engine::UpdateDeltatime()
{
	time = clock.restart();
	m_fDeltaTime = time.asSeconds();
}

void Engine::SetVisuals(float degree)
{
	m_visuallevel = degree;
}
