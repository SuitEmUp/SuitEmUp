#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include <iostream>

#include "Customize.h"
#include "InputManager.h"
#include "Config.h"
#include "Button.h"
#include "SpriteManager.h"
#include "GameObjectManager.h"


Customize::Customize(InputManager* input, GameObjectManager* gom) 
{
	m_input = input;
	m_gom = gom;
	next_state = "";
};

bool Customize::Init()
{
	tempName_change = "02";

	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2<float>(150.0f, 150.0f));

	m_rects.push_back(rectangle);

	printf("State: Customize, Initialized\n");
	printf("F1 - F4 to Change States\n");

	m_gom->CreateCusomizationButtons();

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

bool Customize::Update(float deltatime)
{
	if(m_input->IsDown(sf::Keyboard::F1))
	{
		printf("Next State set to MainMenu\n");
		setNextState("MainMenu");
		return false;
	};
	if(m_input->IsDown(sf::Keyboard::F2))
	{
		printf("Next State set to Game\n");
		setNextState("Game");
		return false;
	};
	if(m_input->IsDown(sf::Keyboard::F4))
	{
		printf("Next State set to Options\n");
		setNextState("Options");
		return false;
	};


	for(int i = 0; i < m_gom->m_vCustomizeButtons.size(); i++)
	{
		if(m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked" && m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeSuit")
		{
			printf("Click SUCCESSSSS\n");
			printf("Suit Upgraded\n");
		}
	}
	return true;
};

void Customize::Draw()
{
	m_gom->DrawCustomizationButtons();
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


