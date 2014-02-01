//InputManager.cpp

#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputKeys.h"
#include "SFML\Window.hpp"


InputManager::InputManager() :
 myMouseX(0),
 myMouseY(0)
{
	for(int i = 0; i < sf::Mouse::ButtonCount; i++) {
		m_currentMouse[i] = false;
		m_previousMouse[i] = false;
	};
}
InputManager::~InputManager()
{

}
bool InputManager::Mouse_isDownOnce(sf::Mouse::Button button) const
{
	return m_currentMouse[sf::Mouse::isButtonPressed(button)] && !m_previousMouse[sf::Mouse::isButtonPressed(button)];
}
int InputManager::GetMouseX() const
{
	return myMouseX;
}
int InputManager::GetMouseY() const
{
	return myMouseY;
}
void InputManager::HandleInput(bool *running, sf::RenderWindow* window, InputManager *m_input, StateManager *m_state_manager)
{
	sf::Event event;
	while(window->isOpen())
	{
		sf::Event event;
		while(window->pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window->close();
			}
			else if(event.type == sf::Event::KeyPressed)
			{
				//InputManager::OnKeyboard(event.key, true);
			}
			else if(event.type == sf::Event::KeyReleased)
			{
				//InputManager::OnKeyboard(event.key, false);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				window->close();
				running = false;
			}
			if (event.type == sf::Event::MouseEntered)
			{
				std::cout << "the mouse cursor has entered the window" << std::endl;
			}
			if (event.type == sf::Event::MouseLeft)
			{
				std::cout << "the mouse cursor has left the window" << std::endl;
			}
			if(event.MouseButtonPressed)
			{
			m_input->myMouseX = event.mouseMove.x;
			m_input->myMouseY = event.mouseMove.y;
			}
			if(event.MouseButtonPressed) {
					m_input->m_currentMouse[0] = true;
				}
			 else if(event.MouseButtonReleased) {
					m_input->m_currentMouse[0] = false;
				}
			
		}
	}
}









