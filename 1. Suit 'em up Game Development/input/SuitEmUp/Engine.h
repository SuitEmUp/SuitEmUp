#pragma once
#include <vector>
#include "InputManager.h"

class StateManager;
namespace sf{
	class RenderWindow;
}

class Engine
{
public:
	Engine();
	~Engine(){};

	bool Initialize();
	void Run();
	void Cleanup();
	void UpdateDeltatime();

private:
	StateManager* m_statemanager;
	sf::RenderWindow* m_window;
	InputManager m_input;
	sf::Clock* m_xDeltaClock;
	sf::Time* m_xDeltaTime;
	float m_fDeltaTime;
	bool m_running;


};