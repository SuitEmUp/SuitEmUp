#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "StateManager.h"

class SFML_WINDOW_API Mouse;

class InputManager {
	friend class Engine;
public:

	InputManager(sf::RenderWindow* window);
	~InputManager();
	bool Mouse_isDownOnce(sf::Mouse::Button button) const;
	bool Mouse_isDown(sf::Mouse::Button button) const;
	int GetMouseY() const;
	int GetMouseX() const;
	sf::Vector2f GetMousePos();
	void HandleInput(bool &running,InputManager *m_input, StateManager *m_state_manager);
	void PostMouseUpdate();
	void PostKeyboardUpdate();
	bool IsDown(int key) const;
	bool IsDownOnce(int key) const;
	bool IsUp(int key);
	sf::Text *Get_Text();
	void Reset_text();
	bool IsAnyDown() const;

	//Fix
	void GlobalAllow();

private:

	sf::RenderWindow* m_window;
	bool m_currentMouse[sf::Mouse::ButtonCount];
	bool m_previousMouse[sf::Mouse::ButtonCount];
	bool m_current[sf::Keyboard::KeyCount];
	bool m_previous[sf::Keyboard::KeyCount];
	
	bool m_globalallow;
	int myMouseX;                                        
	int myMouseY;    
	sf::Vector2i m_mousepos;
	std::string str;
	sf::Text *text;
	sf::Font font;
	std::string *check;
};