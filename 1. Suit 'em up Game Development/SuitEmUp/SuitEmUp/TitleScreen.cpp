#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "TitleScreen.h"
#include "InputManager.h"
#include "SpriteManager.h"
#include "SoundManager.h"



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
	start_game.setColor(sf::Color(156, 35, 23, 255));
	start_game.move(325.f, 650.f);	
	start_game.setStyle(sf::Text::Bold);


	m_blTimer = 10;
	m_tiTimer = 100;
	m_blackfade = 255.0f;
	m_titlefade = 255.0f;
	m_CanGoToMain = false;
	m_playsound = true;

};

bool TitleScreen::Init()
{
	m_xbackground = m_engine->m_spritemanager->Load("../data/Sprites/title.png", "bakgrund", 1.0, 1.0);
	m_TitleLogo = m_engine->m_spritemanager->Load("../data/misc/titlelogob.png", "title", 1.0, 1.0);
	m_fire_sprite = m_engine->m_spritemanager->Load("../data/Sprites/firespreadsheet.png", "fire", 1.3, 1.3);

	Black = new sf::RectangleShape;							Black->setSize(sf::Vector2f(1280, 720));
	Black->setFillColor(sf::Color(0,0,0,m_blackfade));		Black->setPosition(sf::Vector2f(0, 0 ));

	//animation
	m_fire_sprite->setPosition(370.0f, 585.0f);
	m_fire = new Animation(m_fire_sprite, 0.2,false, true);
	m_fire->setSpriteSheet(m_fire_sprite);

	m_fire->addFrame(sf::IntRect (0, 0, 28, 23));
	m_fire->addFrame(sf::IntRect (34, 0, 28, 23));
	m_fire->addFrame(sf::IntRect (68, 0, 28, 23));
	m_fire->addFrame(sf::IntRect (102, 0, 28, 23));
	m_fire->addFrame(sf::IntRect (136, 0, 28, 23));
	
	for(int count=0;count<5;count++)
	{
		m_fire->update(0.1f, 1);
	}
	
	printf("State: TitleScreen,  Initialized\n");
	printf("Press SPACE or RETURN to enter MainMenu\n");
	return true;
};
void TitleScreen::Exit()
{
	delete m_fire;
	m_fire = nullptr;
};


bool TitleScreen::Update(float deltatime)
{
	m_fire_sprite->setPosition(370.0f, 585.0f);
	int fadespeed = 4;

	if(m_CanGoToMain == true)
	{
		if(m_playsound){
		m_engine->m_soundmanager->PlayMusic("Campfire.wav");
		m_playsound = false;
		}
		m_fire->update(deltatime, 1);
		if(m_input->IsDown(sf::Keyboard::Space) || m_input->IsDown(sf::Keyboard::Return))
		{
			printf("Next State set to MainMenu\n");
			setNextState("MainMenu");
			return false;
		};
	}

	else if(m_CanGoToMain == false)
	{
		if(m_tiTimer > 0)
		{
			m_tiTimer -= 1;
			/*if(m_tiTimer < 0)
			m_tiTimer = 0*/;
		}


		if(m_tiTimer <= 0)
		{
			m_titlefade -= fadespeed;
			if(m_titlefade <= 0)
			{
				m_blTimer -= 1;
				//delete m_TitleLogo;
				m_TitleLogo = nullptr;
				if(m_blTimer <= 0)
				{
					m_blackfade -= fadespeed;
					if(m_blackfade <= 0)
					{
						//	delete Black;
						Black = nullptr;
					}
				}
			}
		}
		if(Black != nullptr)
			Black->setFillColor(sf::Color(0,0,0, m_blackfade));
		if(m_TitleLogo != nullptr)
			m_TitleLogo->setColor(sf::Color(255, 255, 255, m_titlefade));


		if(m_blackfade <= 0)
			m_CanGoToMain = true;


	}

	return true;
}

void TitleScreen::Draw()
{
	m_engine->m_window->draw(*m_xbackground);
	m_engine->m_window->draw(start_game);

	if(Black != nullptr)
		m_engine->m_window->draw(*Black);
	if(m_TitleLogo != nullptr)
		m_engine->m_window->draw(*m_TitleLogo);

	if(m_CanGoToMain)
	{
		m_engine->m_window->draw(*m_fire_sprite);
	}


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


