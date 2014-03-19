//InputManager.cpp

#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputKeys.h"
#include "SFML\Window.hpp"
#include "Config.h"

//hej

InputManager::InputManager(sf::RenderWindow* window) :
	myMouseX(0),
	myMouseY(0)
{ 
	m_window = window;
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
	//text
	text = new sf::Text;

	if (!font.loadFromFile("../assets/fonts/Viking_n.ttf"))
	{ printf("Could not load font\n"); }

	text->setFont(font);
	text->setCharacterSize(25);
	text->setColor(sf::Color::Black);
	text->move(0.f, 0.f);	
	text->setStyle(sf::Text::Bold);
	m_globalallow = false;
}

InputManager::~InputManager()
{

}

bool InputManager::Mouse_isDownOnce(sf::Mouse::Button button) const
{
	return m_currentMouse[sf::Mouse::Button::Left] 
	&& !m_previousMouse[sf::Mouse::Button::Left];
}

bool InputManager::Mouse_isDown(sf::Mouse::Button button) const
{
	return m_currentMouse[sf::Mouse::Button::Left];
};

int InputManager::GetMouseX() const
{
	return myMouseX;
}

int InputManager::GetMouseY() const
{
	return myMouseY;
}

void InputManager::HandleInput(bool &running, InputManager *m_input, StateManager *m_state_manager)
{
	m_mousepos = sf::Mouse::getPosition(*m_window);
	sf::Event event;
	while(m_window->pollEvent(event))
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
			}
		}
		else if (event.type == sf::Event::TextEntered)
		{	
			if(m_globalallow == true)
			{
				str += static_cast<char>(event.text.unicode);
				if(m_input->IsDown(sf::Keyboard::BackSpace))
				{
					str = "";
				}
				if(m_input->IsDown(sf::Keyboard::Return))
				{
					str = "";
				}
				if (event.text.unicode < 128)
				{
					text->setString(str);
				}
			}
		}
		else if(event.type == sf::Event::MouseButtonReleased)
		{
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				m_input->m_currentMouse[0] = false;
			}
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

bool InputManager::IsDownOnce(int key) const
{
	return m_current[key] 
	&& !m_previous[key];

};

bool InputManager::IsAnyDown() const
{
	//for (int i = 0; i < )
	return true;
}

sf::Vector2f InputManager::GetMousePos(){
	float x = m_mousepos.x;
	float y = m_mousepos.y;
	return sf::Vector2f(x, y);
}

sf::Text *InputManager::Get_Text()
{
	text->setString(str);
	return text;
}

void InputManager::Reset_text()
{
	str = "";
}
void InputManager::GlobalAllow()
{
	if(m_globalallow == false)
	{
		m_globalallow = true;
	}
	else
	{
		m_globalallow = false;
	}
}