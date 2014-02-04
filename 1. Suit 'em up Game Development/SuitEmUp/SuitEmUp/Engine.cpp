
#include "Engine.h"

#include "StateManager.h"
#include "SpriteManager.h"

#include "MainMenu.h"
#include "Options.h"
#include "Customize.h"
#include "Game.h"
#include "TitleScreen.h"

#include "InputManager.h"//Ladbon
#include "DrawManager.h"

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

#include "Config.h"
#include <iostream>


Engine::Engine()
{


	m_running = false;//Ladbon
	m_window = nullptr;
	
	m_drawmanager = nullptr;
	m_statemanager = nullptr;
	m_spritemanager = nullptr;

	m_fDeltaTime = 0.01f;
};

bool Engine::Initialize()
{
	m_statemanager = new StateManager;
	m_window = new sf::RenderWindow(sf::VideoMode(Config::getInt("window_w", 0), Config::getInt("window_h", 0)), "SFML window");
	m_spritemanager = new SpriteManager;

	/*m_drawmanager = new DrawManager();
	if (!m_drawmanager->initialize(*m_window))
	{
		return false;
	}*/


	if(m_statemanager->current == nullptr)
	{
		m_statemanager->Attach(new TitleScreen(&m_input));
		m_statemanager->Attach(new MainMenu(&m_input));
		m_statemanager->Attach(new Options(&m_input));
		m_statemanager->Attach(new Customize(&m_input));
		m_statemanager->Attach(new Game(&m_input));
		m_statemanager->SetState("TitleScreen");
	}
	m_running = true;

	m_window->setFramerateLimit(60);
	return true;
};
void Engine::Run()
{
	sf::Sprite* xSprite = m_spritemanager->Load("../assets/gfx/b.png", "testbutton");


	while(m_running)
	{
		//deltatime()
	//	UpdateDeltatime();
		m_statemanager->HandleEvents();
		//m_statemanager->UpdateTime(m_fDeltaTime);
		m_statemanager->Update();
		m_window->clear();
		m_statemanager->Draw(m_window);
		m_window->draw(*xSprite);
		m_window->display();
		//sf::sleep(sf::milliseconds(10));
		m_input.PostMouseUpdate();
		m_input.PostKeyboardUpdate();
		m_input.HandleInput(m_running, m_window, &m_input, m_statemanager);
		//std::cout << m_running << std::endl;

		//sf::sleep(sf::seconds(1));
	}
	m_window->close();
};
void Engine::Cleanup()
{
	m_statemanager->Cleanup();
	delete m_statemanager;
	m_statemanager = nullptr;
};
void Engine::UpdateDeltatime()
{
	*m_xDeltaTime = m_xDeltaClock->getElapsedTime();
	m_fDeltaTime = m_xDeltaTime->asMilliseconds();
	m_xDeltaClock->restart();
}




