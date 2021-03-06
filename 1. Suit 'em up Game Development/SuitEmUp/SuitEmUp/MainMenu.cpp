#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "MainMenu.h"
#include "InputManager.h"
#include "SpriteManager.h"

#include "Button.h"
#include "Config.h"

#include "SoundManager.h"

MainMenu::MainMenu(Engine *engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;

	m_canclick = false;
	m_oneclicklock = false;




};

bool MainMenu::Init()
{

	printf("State: MainMenu,  Initialized\n");

	m_xbackground = m_engine->m_spritemanager->Load("../data/Sprites/title.png", "bakgrund", 1.0, 1.0);
	m_fire_sprite = m_engine->m_spritemanager->Load("../data/Sprites/firespreadsheet.png", "fire", 1.3, 1.3);
	m_logo = m_engine->m_spritemanager->Load("../data/misc/logo.png", "Logo", 1.0f, 1.0f);

	m_logo->setOrigin(m_logo->getLocalBounds().width / 2, 0);
	m_logo->setPosition(Config::getInt("window_w", 0) / 2, Config::getInt("logoypos", 0));

	m_glow1 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow1",  1.0f, 1.0f);
	m_glow1->setPosition(Config::getInt("window_w", 0)/2 - 119, Config::getInt("menu_top_padding", 0));

	m_glow2 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow2",  1.0f, 1.0f);
	m_glow2->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)));

	m_glow3 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow3",  1.0f, 1.0f);
	m_glow3->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)*2));

	m_glow4 = m_engine->m_spritemanager->Load("../data/buttons/hover.png","glow4",  1.0f, 1.0f);
	m_glow4->setPosition((Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0)*3));

	m_engine->m_gom->CreateButtons();

	m_Tutorial = m_engine->m_spritemanager->Load("../data/misc/tut.png", "Tutorial", 1.0f, 1.0f);
	m_ShowTutorial = false;

	m_showREALTITLE = false;
	m_reset = false;
	m_codecount = 0;

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
void MainMenu::Exit()
{
	m_engine->m_gom->EraseButtons();
	delete m_fire;
	m_fire = nullptr;
};

bool MainMenu::Update(float deltatime)
{
	m_fire_sprite->setPosition(370.0f, 585.0f);


	if(!m_ShowTutorial)
	{
		m_fire->update(deltatime, 1);
		for(int i = 0; i < m_engine->m_gom->m_vButtons.size(); i++)
		{
			if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked")
			{
				if(m_engine->m_gom->m_vButtons.at(i)->GetType2() == "StartGame")
				{
					m_engine->m_soundmanager->PlaySound("M4A1.wav");

					m_ShowTutorial = true;
				}

				if(m_engine->m_gom->m_vButtons.at(i)->GetType2() == "HighScore")
				{
					printf("Click SUCCESSSSS\n");
					printf("Next State set to Highscore\n");


					m_engine->m_soundmanager->PlaySound("M4A1.wav");

					setNextState("HighScoreState");
					return false;
				}

				if(m_engine->m_gom->m_vButtons.at(i)->GetType2() == "Options")
				{


					printf("Click SUCCESSSSS\n");
					printf("Next State set to Options\n");
					setNextState("Options");
					return false;

					printf("Click SUCCESSSSS\n");
					m_engine->m_soundmanager->PlaySound("M4A1.wav");
					printf("Next State set to Options\n");
					setNextState("Options");
					return false;
				}


				if(m_engine->m_gom->m_vButtons.at(i)->GetType2() == "QuitGame"){

					m_engine->m_running = false;
					printf("Click SUCCESSSSS\n");
					printf("This button doesnt work yet\n");
					//Exit Game

				}
			}
		}
		if(m_input->IsDownOnce(sf::Keyboard::Up) && m_codecount == 0){			m_codecount += 1;}
		//else m_codecount = 0;
		if (m_input->IsDownOnce(sf::Keyboard::Up) && m_codecount == 1){	m_codecount += 1;}
		//else m_codecount = 0;
		if (m_input->IsDownOnce(sf::Keyboard::Down) && m_codecount == 2){		m_codecount += 1;}
		//else m_codecount = 0;
		if (m_input->IsDownOnce(sf::Keyboard::Down) && m_codecount == 3){	m_codecount += 1;}
		//else m_codecount = 0;
		if (m_input->IsDownOnce(sf::Keyboard::Left) && m_codecount == 4){		m_codecount += 1;}
		//else m_codecount = 0;
		if (m_input->IsDownOnce(sf::Keyboard::Right) && m_codecount == 5){		m_codecount += 1;}
		//else m_codecount = 0;
		if (m_input->IsDownOnce(sf::Keyboard::Left) && m_codecount == 6){		m_codecount += 1;}
		//else m_codecount = 0;
		if (m_input->IsDownOnce(sf::Keyboard::Right) && m_codecount == 7){		m_codecount += 1;}
		//else m_codecount = 0;
		if (m_input->IsDownOnce(sf::Keyboard::B) && m_codecount == 8){			m_codecount += 1;}
		if (m_input->IsDownOnce(sf::Keyboard::A) && m_codecount == 9){			m_codecount += 1;}
		if (m_input->IsDownOnce(sf::Keyboard::Return) && m_codecount == 10)
		{
			m_codecount += 1;
			m_logo = m_engine->m_spritemanager->Load("../data/misc/reallogo.png", "Logo", 1.0f, 1.0f);
			m_logo->setOrigin(m_logo->getLocalBounds().width / 2, 0);
			m_logo->setPosition(Config::getInt("window_w", 0) / 2, Config::getInt("logoypos", 0));
		}
	}


	if(m_ShowTutorial)
	{
		Exit();
		if(m_input->IsDown(sf::Keyboard::Space) || m_input->IsDown(sf::Keyboard::Return))
		{

			Config::set("currentsuitcost", "1000");
			Config::set("currentweaponcost", "2000");
			Config::set("currenttruckcost", "1500");
			Config::renew();
			printf("Click SUCCESSSSS\n");
			printf("Next State set to Game\n");
			setNextState("Game");
			m_engine->m_paused = 3; //through mainmenu
			return false;
		}
	}



	return true;
}
void MainMenu::Draw()
{
	m_engine->m_window->draw(*m_xbackground);
	m_engine->m_gom->DrawButtons();
	m_engine->m_window->draw(*m_logo);

	for(int i = 0; i < m_engine->m_gom->m_vButtons.size(); i++)
	{
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Hovering" &&m_engine->m_gom->m_vButtons.at(i)->GetType2() == "StartGame"){
			m_engine->m_window->draw(*m_glow1);
		};
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Hovering" &&m_engine->m_gom->m_vButtons.at(i)->GetType2() == "HighScore"){
			m_engine->m_window->draw(*m_glow2);
		};
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Hovering" &&m_engine->m_gom->m_vButtons.at(i)->GetType2() == "Options"){
			m_engine->m_window->draw(*m_glow3);
		};
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Hovering" &&m_engine->m_gom->m_vButtons.at(i)->GetType2() == "QuitGame"){
			m_engine->m_window->draw(*m_glow4);
		}
	}
	m_engine->m_window->draw(*m_fire_sprite);

	if(m_ShowTutorial)
		m_engine->m_window->draw(*m_Tutorial);
};
std::string MainMenu::Next()
{
	return next_state;
};

void MainMenu::setNextState(std::string state)
{
	next_state = state;
};

bool MainMenu::IsType(const std::string &type)
{
	return type.compare("MainMenu") == 0;
};


