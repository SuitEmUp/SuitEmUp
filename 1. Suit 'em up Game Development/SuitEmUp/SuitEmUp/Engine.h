#pragma once
#include <vector>
#include "InputManager.h"

class SpriteManager;
class StateManager;
class DrawManager;
class GameObjectManager;

namespace sf{
	class RenderWindow;
}

class Engine //brum brum
{
public:
	Engine();
	~Engine(){};

	bool Initialize();
	void Run();
	void Cleanup();
	void UpdateDeltatime(); //ladbon
private:
	StateManager* m_statemanager;
	sf::RenderWindow* m_window;

	SpriteManager* m_spritemanager;

	GameObjectManager* m_gom;
	//ladbon
	InputManager m_input;
	//DrawManager *m_drawmanager;


	sf::Clock clock;
	sf::Time time;
	float m_fDeltaTime;
	bool m_running;



};