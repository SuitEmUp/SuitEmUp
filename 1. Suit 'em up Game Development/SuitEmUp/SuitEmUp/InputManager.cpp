//InputManager.cpp

#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputKeys.h"
#include "SFML\Window.hpp"

//hej

InputManager::InputManager() :
	myMouseX(0),
	myMouseY(0)
{
	m_window = nullptr;
	//Keyboard

	for(int i = 0; i < sf::Keyboard::KeyCount; i++) {
		m_current[i] = false;
		m_previous[i] = false;
	};

	//Mouse

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
	return m_currentMouse[sf::Mouse::Button::Left] 
	&& !m_previousMouse[sf::Mouse::Button::Left];
}
int InputManager::GetMouseX() const
{
	return myMouseX;
}
int InputManager::GetMouseY() const
{
	return myMouseY;
}
void InputManager::HandleInput(bool &running, sf::RenderWindow* window, InputManager *m_input, StateManager *m_state_manager)
{
	m_mousepos = sf::Mouse::getPosition(*window);
	sf::Event event;
	while(window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			running = false;
		}
		else if(event.type == sf::Event::KeyPressed) 
		{
			int index = event.key.code;
			m_input->m_current[index] = true;
		}
		else if(event.type == sf::Event::KeyReleased) 
		{
			int index = event.key.code;
			m_input->m_current[index] = false;
		}
		else if(event.type == sf::Event::MouseButtonPressed)
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				m_input->myMouseX = event.mouseButton.x;
				m_input->myMouseY = event.mouseButton.y;
				m_input->m_currentMouse[0] = true;
				std::cout << myMouseX << " : " << myMouseY << "\n";
			}
		}
		else if(event.type == sf::Event::MouseButtonReleased)
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				m_input->m_currentMouse[0] = false;
			}
		}
		if(m_input->IsDown(sf::Keyboard::Escape))
		{
			std::cout << "nu kom jag in haer";
			running = false;

		}
	}
}
void InputManager::PostMouseUpdate()
{
	for(int i = 0; i < sf::Mouse::ButtonCount; i++) 
	{
		m_previousMouse[i] = m_currentMouse[i];
	};
}

void InputManager::PostKeyboardUpdate()
{

	for(int i = 0; i < sf::Keyboard::KeyCount; i++) {
		m_previous[i] = m_current[i];
	};

};

bool InputManager::IsDown(int key) const
{
	return m_current[key];
}
bool InputManager::IsUp(int key)
{
	return !m_current[key];
}

sf::Vector2i InputManager::GetMousePos(){
	return m_mousepos;
}
