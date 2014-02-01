#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "StateManager.h"

class SFML_WINDOW_API Mouse;

class InputManager {
	friend class Engine;
public:

	InputManager();
	~InputManager();
	bool Mouse_isDownOnce(sf::Mouse::Button button) const;
	int GetMouseY() const;
	int GetMouseX() const;
	void HandleInput(bool &running, sf::RenderWindow* window, InputManager *m_input, StateManager *m_state_manager);
	void PostMouseUpdate();
	void PostKeyboardUpdate();
	bool IsDown(int key) const;
	bool IsUp(int key);

private:

	bool m_currentMouse[sf::Mouse::ButtonCount];
	bool m_previousMouse[sf::Mouse::ButtonCount];
	bool m_current[256];
	bool m_previous[256];

	int myMouseX;                                        
	int myMouseY;    
};