//DieState.cpp


#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "DieState.h"
#include "InputManager.h"
#include "SpriteManager.h"
#include <sstream>



DieState::DieState(Engine* engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;
	m_text = new sf::Text;
	m_highscore = nullptr;
	m_highscore = m_engine->m_ehighscore;
	player_score = new S_Highscores;

	if (!m_font.loadFromFile("../assets/fonts/Viking_n.ttf"))
	{ printf("Could not load font\n"); }

	m_text->setFont(m_font);
	m_text->setCharacterSize(25);
	m_text->setColor(sf::Color::Black);
	m_text->move(0.f, 0.f);	
	m_text->setStyle(sf::Text::Bold);
};

bool DieState::Init()
{

	//Resets stuff in the config-file
	Config::set("current_suit", "0");
	Config::set("current_weapon", "0");
	Config::set("current_truck", "0");
	Config::set("weapons_available", "1");
	Config::renew();

	m_xbackground = m_engine->m_spritemanager->Load("../data/sprites/Background.png", "Background", 1, 1);
	m_xbackground->setPosition(0,0);


	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2<float>(150.0f, 150.0f));
	//StartGame

	m_xbuttons.push_back(new Button(m_input, "Retry", "Square", m_engine->m_spritemanager->Load("../data/buttons/Retry.png", "StartGame"),

		(Config::getInt("window_w", 0)/2 - 119), Config::getInt("menu_top_padding", 0)));
	//HighScore
	m_xbuttons.push_back(new Button(m_input, "HighScore", "Square", m_engine->m_spritemanager->Load("../data/buttons/HighScore.png", "HighScore"),

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0))));
	//Mainmenu
	m_xbuttons.push_back(new Button(m_input, "Main", "Square" ,m_engine->m_spritemanager->Load("../data/buttons/Main_Menu.png", "Mainmenu"), 

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*2))));
	//Submit
	m_xbuttons.push_back(new Button(m_input, "Submit", "Square",m_engine->m_spritemanager->Load("../data/buttons/submit_button.png", "Submit"), 

		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*3))));

	m_glow1 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow1",  1.0f, 1.0f);
	m_glow1->setPosition(Config::getInt("window_w", 0)/2 - 119, Config::getInt("menu_top_padding", 0));

	m_glow2 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow2",  1.0f, 1.0f);
	m_glow2->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)));

	m_glow3 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow3",  1.0f, 1.0f);
	m_glow3->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)*2));

	m_glow4 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow4",  1.0f, 1.0f);
	m_glow4->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)*3));

	m_input->Reset_text();

	printf("State: DieState,  Initialized\n");
	return true;
};
void DieState::Exit(){

	for(unsigned int i = 0; i < m_rects.size(); i++)
	{
		delete m_rects[i];
		m_rects[i] = nullptr;
	}
	m_rects.clear();

	for(unsigned int i = 0; i < m_xbuttons.size(); i++)
	{
		delete m_xbuttons[i];
		m_xbuttons[i] = nullptr;
	}
	m_xbuttons.clear();


	if(m_engine->m_paused == 1)
	{
		m_engine->m_gom->ClearGameObjects();
	};
	if(m_xbackground!=nullptr){
		delete m_xbackground;
		m_xbackground=nullptr;
	}
	m_glow1=nullptr;
	m_glow2=nullptr;
	m_glow3=nullptr;
	m_xbackground=nullptr;

};


bool DieState::Update(float deltatime)
{
	m_text = m_input->Get_Text();

	for(int i=0; i<m_xbuttons.size();i++)
	{
		if(m_xbuttons.at(i)->Update()== "Clicked" && m_xbuttons.at(i)->GetType2() == "Retry")
		{
			printf("Next State set to GameState\n");
			setNextState("Game");
			m_engine->m_paused = 1;
			return false;
		}
		if(m_xbuttons.at(i)->Update()== "Clicked" && m_xbuttons.at(i)->GetType2() == "HighScore")
		{
			printf("Next State set to highScoreState\n");
			setNextState("HighScoreState");

			return false;
		}
		if(m_xbuttons.at(i)->Update()== "Clicked" && m_xbuttons.at(i)->GetType2() == "Main")
		{
			printf("Next State set to MainMenu\n");
			setNextState("MainMenu");
			m_engine->m_paused = 1;
			return false;
		}
		if(m_xbuttons.at(i)->Update()== "Clicked" && m_xbuttons.at(i)->GetType2() == "Submit")
		{
			player_score->name = m_text->getString();
			player_score->score = m_engine->m_gom->GetScore(player_score->score);
			player_score->kills = m_engine->m_gom->Kill_count();
			m_highscore->Push_Back(player_score);
		}

	}
	return  true;
}

void DieState::Draw()
{
	//draw Background
	m_engine->m_window->draw(*m_xbackground);

	for(int i=0; i<m_xbuttons.size(); i++){
		if(m_xbuttons.at(i)!=nullptr){
			m_engine->m_window->draw(*m_xbuttons.at(i)->GetSprite()); // draws all buttons
		}
	}

	m_engine->m_gom->Dead();
	m_engine->m_window->draw(*m_text);

	for(int i = 0; i < m_xbuttons.size(); i++)
	{
		if(m_xbuttons.at(i)->Update() == "Hovering" && m_xbuttons.at(i)->GetType2() == "Retry"){
			m_engine->m_window->draw(*m_glow1);
		};
		if(m_xbuttons.at(i)->Update() == "Hovering" && m_xbuttons.at(i)->GetType2() == "HighScore"){
			m_engine->m_window->draw(*m_glow2);
		};
		if(m_xbuttons.at(i)->Update() == "Hovering" && m_xbuttons.at(i)->GetType2() == "Main"){
			m_engine->m_window->draw(*m_glow3);
		};
		if(m_xbuttons.at(i)->Update() == "Hovering" && m_xbuttons.at(i)->GetType2() == "Submit"){
			m_engine->m_window->draw(*m_glow4);
		};
	};

};

std::string DieState::Next()
{
	return next_state;
};

void DieState::setNextState(std::string state)
{
	next_state = state;
};

bool DieState::IsType(const std::string &type)
{
	return type.compare("DieState") == 0;
};