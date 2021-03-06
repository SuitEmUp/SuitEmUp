//HighScoreState.cpp

#include <iostream>
#include "HighScoreState.h"
#include "InputManager.h"
#include <fstream>
#include <iostream>
#include "GameObjectManager.h"
#include "SpriteManager.h"
#include "SoundManager.h"

HighScoreState::HighScoreState(Engine* engine) 
{
	m_highscore = nullptr;
	text = nullptr;
	font = nullptr;
	m_background = nullptr;

	m_engine = engine;
	m_input = engine->m_input;
	m_highscore = m_engine->m_ehighscore;


	text = new sf::Text;
	font = new sf::Font;
	m_background = new sf::Sprite;

	index = 0.0f;
	next_state = "";
};

bool HighScoreState::Init()
{
	m_fire_sprite = m_engine->m_spritemanager->Load("../data/Sprites/firespreadsheet.png", "fire", 1.3, 1.3);
	m_background = m_engine->m_spritemanager->Load("../data/sprites/title.png", "title.png", 1, 1);
	m_background->setPosition(0,0);

	Config::set("current_suit", "0");
	Config::set("current_weapon", "0");
	Config::set("current_truck", "0");
	Config::set("weapons_available", "1");
	Config::renew();

	if (!font->loadFromFile("../assets/fonts/Viking_n.ttf"))
	{ printf("Could not load font\n"); }

	if(m_highscore->Size() <= 10)
	{
		for(int i=0;i<m_highscore->Size();i++)
		{
			text->setFont(*font);
			text->setCharacterSize(20);
			text->setColor(sf::Color(156, 35, 23, 255));	
			text->setStyle(sf::Text::Bold);

			std::ostringstream ss;
			ss << i+1 << ". " << m_highscore->Getdata(i)->name << "  " << m_highscore->Getdata(i)->score << "  | Kills | -> " << m_highscore->Getdata(i)->kills << "\n";	
			text->setString( ss.str());
			text->setPosition(400, 100+(text->getCharacterSize()+10)*i);
			Texts.push_back(text);
			text = new sf::Text;
		}
	}
	else
	{
		for(int y=0;y<13;y++)
		{
			if(y == m_highscore->Size())
			{
				break;
			}
			text->setFont(*font);
			text->setCharacterSize(20);
			text->setColor(sf::Color(156, 35, 23, 255));		
			text->setStyle(sf::Text::Bold);

			std::ostringstream ss;
			ss << y+1 << ". " << m_highscore->Getdata(y)->name << "  " << m_highscore->Getdata(y)->score << "  | Kills | -> " << m_highscore->Getdata(y)->kills << "\n";	
			text->setString( ss.str());
			text->setPosition(400, 100+(text->getCharacterSize()+10)*y);
			Texts.push_back(text);
			text = new sf::Text;
		}
	}

	//Mainmenu
	m_xbuttons.push_back(new Button(m_engine->m_soundmanager,m_input, "Main", "Square" ,m_engine->m_spritemanager->Load("../data/buttons/Main_Menu.png", "Mainmenu"), 
		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*3))));

	m_glow1 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow1",  1.0f, 1.0f);
	m_glow1->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)*3));

	std::cout << "Initiated HighscoreState\n";

	tempName_change = "02";

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

	return true;
};

void HighScoreState::Exit()
{
	m_highscore->Save();

	for(unsigned int i = 0; i < m_rects.size(); i++)
	{
		delete m_rects[i];
		m_rects[i] = nullptr;
	}
	m_rects.clear();

	for(unsigned int i = 0; i < 1; i++)
	{
		delete m_xbuttons.at(i);
		m_xbuttons.at(i) = nullptr;
	}
	m_xbuttons.clear();

	if(m_glow1 != nullptr)
	{
		delete m_glow1;
		m_glow1 = nullptr;
	}
	delete m_fire;
	m_fire = nullptr;

	for(unsigned int i = 0; i < Texts.size(); i++)
	{
		delete Texts[i];
		Texts[i] = nullptr;
	}
	Texts.clear();
};

bool HighScoreState::Update(float deltatime)
{
	m_fire_sprite->setPosition(370.0f, 585.0f);
	m_fire->update(deltatime, 1);

	for(int i=0; i<m_xbuttons.size();i++)
	{
		if(m_xbuttons.at(i)->Update()== "Clicked")
		{
			if(m_xbuttons.at(i)->GetType2() == "Main")
			{
				printf("Next State set to MainMenu\n");
				setNextState("MainMenu");
				m_engine->m_paused = 1;
				m_engine->m_soundmanager->PlaySound("M4A1.wav");
				return false;
			}
		}
	}
	return  true;

};

void HighScoreState::Draw()
{
	m_engine->m_window->draw(*m_background);

	for(int i=0;i<Texts.size();i++)
	{

		m_engine->m_window->draw(*Texts.at(i));
	}

	for(int i=0; i<m_xbuttons.size(); i++){

		if(m_xbuttons.at(i)!=nullptr){
			m_engine->m_window->draw(*m_xbuttons.at(i)->GetSprite()); // draws all buttons
		}
	}

	for(int i = 0; i < m_xbuttons.size(); i++)
	{
		if(m_xbuttons.at(i)->Update() == "Hovering" && m_xbuttons.at(i)->GetType2() == "Main"){
			m_engine->m_window->draw(*m_glow1);
		}
	}
	m_engine->m_window->draw(*m_fire_sprite);

};
std::string HighScoreState::Next()
{
	return next_state;
};

void HighScoreState::setNextState(std::string state)
{
	next_state = state;
};

bool HighScoreState::IsType(const std::string &type)
{
	return type.compare("HighScoreState") == 0;
};

