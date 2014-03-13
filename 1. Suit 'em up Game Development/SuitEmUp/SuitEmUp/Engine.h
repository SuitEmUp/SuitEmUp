#pragma once
#include <vector>
#include "InputManager.h"

class SpriteManager;
class StateManager;
class DrawManager;
class GameObjectManager;
class ButtonManager;
<<<<<<< HEAD
class Highscore;
=======
class SoundManager;
>>>>>>> e464993c68810020295f52dc934f30a498fb8a53

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
public:
	StateManager* m_statemanager;
	sf::RenderWindow* m_window;

	SpriteManager* m_spritemanager;
	ButtonManager* m_buttonmanager;

	GameObjectManager* m_gom;
	//ladbon
	InputManager *m_input;
	
	//DrawManager *m_drawmanager;
	SoundManager* m_soundmanager;

	sf::Clock clock;
	sf::Time time;
	float m_fDeltaTime;
	bool m_running;
	int m_paused;

<<<<<<< HEAD
	Highscore *m_ehighscore;
=======
	int m_soundlevel;
	int m_visuallevel;
	int m_musiclevel;
	int m_mastervolumelevel;

>>>>>>> e464993c68810020295f52dc934f30a498fb8a53
	sf::Sprite *m_crosshair;

};