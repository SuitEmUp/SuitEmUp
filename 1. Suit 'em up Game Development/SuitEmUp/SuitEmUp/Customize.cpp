#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include <iostream>

#include "Customize.h"



Customize::Customize(InputManager* input) 
{
	m_input = input;
	next_state = "";
};

bool Customize::Init()
{
	printf("State: Customize, Initialized\n");
	tempName_change = "02";

	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2<float>(150.0f, 150.0f));

	m_rects.push_back(rectangle);




	return true;
};
void Customize::Exit(){
	for(unsigned int i = 0; i < m_rects.size(); i++)
	{
		delete m_rects[i];
		m_rects[i] = nullptr;
	}
	m_rects.clear();
};

//bool Customize::HandleInput()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//	{
//		setNextState("");
//		return false;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
//	{
//		setNextState("Options");
//		return false;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
//	{
//		setNextState("Customize");
//		return false;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
//	{
//		setNextState("Game");
//		return false;
//	}
//	return true;
//};


bool Customize::Update()
{
	return true;
};

void Customize::Draw(sf::RenderWindow *p_window)
{
	for(unsigned int i = 0; i<m_rects.size(); i++)
	{
		p_window->draw(*m_rects[i]);
	}
}

std::string Customize::Next()
{
	return next_state;
};

void Customize::setNextState(std::string state)
{
	next_state = state;
};

bool Customize::IsType(const std::string &type)
{
	return type.compare("Customize") == 0;
};


