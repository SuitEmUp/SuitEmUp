#pragma once
#include <vector>
#include "InputManager.h"

class SpriteManager;
class StateManager;
class DrawManager;
class GameObjectManager;
class ButtonManager;

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
	void UpdateDeltatime(); //ladbon
private:
	StateManager* m_statemanager;
	sf::RenderWindow* m_window;

	SpriteManager* m_spritemanager;
	ButtonManager* m_buttonmanager;

	GameObjectManager* m_gom;
	//ladbon
	InputManager m_input;
	
	//DrawManager *m_drawmanager;

	sf::Clock* m_xDeltaClock;
	sf::Time* m_xDeltaTime;
	float m_fDeltaTime;
	bool m_running;



};