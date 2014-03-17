#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "TitleScreen.h"
#include "InputManager.h"
#include "SpriteManager.h"




TitleScreen::TitleScreen(Engine* engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;

	start_game.setString("Press Enter/Space to continue");

	if (!font.loadFromFile("../assets/fonts/Viking_n.ttf"))
	{ printf("Could not load font\n"); }

	start_game.setFont(font);
	start_game.setCharacterSize(25);
	start_game.setColor(sf::Color::Green);
	start_game.move(325.f, 650.f);	
	start_game.setStyle(sf::Text::Bold);

};

bool TitleScreen::Init()
{
	m_xbackground = m_engine->m_spritemanager->Load("../data/Sprites/title.png", "bakgrund", 1.0, 1.0);

	printf("State: TitleScreen,  Initialized\n");
	printf("Press SPACE or RETURN to enter MainMenu\n");
	return true;
};
void TitleScreen::Exit()
{
};


bool TitleScreen::Update(float deltatime)
{
	if(m_input->IsDown(sf::Keyboard::Space) || m_input->IsDown(sf::Keyboard::Return))
	{
		printf("Next State set to MainMenu\n");
		setNextState("MainMenu");
		return false;
	};
	return true;
}

void TitleScreen::Draw()
{
	m_engine->m_window->draw(*m_xbackground);
	m_engine->m_window->draw(start_game);
};

std::string TitleScreen::Next()
{
	return next_state;
};

void TitleScreen::setNextState(std::string state)
{
	next_state = state;
};

bool TitleScreen::IsType(const std::string &type)
{
	return type.compare("TitleScreen") == 0;
};


