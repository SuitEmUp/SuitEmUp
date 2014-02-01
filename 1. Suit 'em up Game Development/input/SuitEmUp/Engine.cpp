#include "Engine.h"

#include "StateManager.h"

#include "MainMenu.h"
#include "Options.h"
#include "Customize.h"
#include "InputManager.h"

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"


Engine::Engine()
{
	m_running = false;
	m_statemanager = nullptr;
	m_window = nullptr;
};
bool Engine::Initialize()
{
	m_statemanager = new StateManager;
	m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
	m_statemanager->SetInput(&m_input);


	m_statemanager->Attach(new MainMenu(&m_input));
	m_statemanager->Attach(new Options);
	m_statemanager->Attach(new Customize);
	m_statemanager->SetState("MainMenu");

	m_running = true;
	return true;
};

void Engine::Run()
{
	while(m_running)
	{
			m_statemanager->Update();
			m_statemanager->UpdateTime(m_fDeltaTime);
			m_window->clear();
			m_statemanager->Draw();
			m_window->display();

			m_input.HandleInput(&m_running, m_window, &m_input, m_statemanager);
	}
}
void Engine::Cleanup()
{
	m_statemanager->Cleanup();
	delete m_statemanager;
	m_statemanager = nullptr;
};
void Engine::UpdateDeltatime()
{
	*m_xDeltaTime = m_xDeltaClock->getElapsedTime();
	m_fDeltaTime = m_xDeltaTime->asSeconds();
	m_xDeltaClock->restart();
}


