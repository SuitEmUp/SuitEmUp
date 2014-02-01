#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include <iostream>

#include "Customize.h"






Customize::Customize() 
{
	next_state = "";
};

bool Customize::Init()
{
	printf("State: Customize, Initialized\n");
	tempName_change = "02";
	
	//sf::RectangleShape* rectangle = new sf::RectangleShape();

	//sf::Shape * rectangle = new sf::Shape(sf::Shape::Rectangle(0,0,100,100,sf::Color::Red));


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


bool Customize::Update()
{
	//texture.update(260, 107);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		setNextState("");
		return false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		setNextState("MainMenu");
		return false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		setNextState("Options");
		return false;
	}
	//Testing Should not be here



	//Test End


	return true;

	return true;
};

//draw

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


