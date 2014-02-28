#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "MainMenu.h"
#include "InputManager.h"
#include "SpriteManager.h"

#include "Button.h"
#include "Config.h"




MainMenu::MainMenu(Engine *engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;

	int test = Config::getInt("window_w", 0);


};

bool MainMenu::Init()
{

	printf("State: MainMenu,  Initialized\n");
	printf("F1 - F4 to Change States\n");

	m_engine->m_gom->CreateButtons();



	return true;
};
void MainMenu::Exit()
{
	m_engine->m_gom->EraseButtons();
};

bool MainMenu::Update(float deltatime)
{

	for(int i = 0; i < m_engine->m_gom->m_vButtons.size(); i++)
	{
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked" && m_engine->m_gom->m_vButtons.at(i)->GetType2() == "StartGame"){
			printf("Click SUCCESSSSS\n");
			printf("Next State set to Game\n");
			setNextState("Game");
			m_engine->m_paused = 3; //through mainmenu
			return false;
		}

		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked" && m_engine->m_gom->m_vButtons.at(i)->GetType2() == "Options"){
			printf("Click SUCCESSSSS\n");
			printf("HighScore-state does not exist\n");
		}
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked" && m_engine->m_gom->m_vButtons.at(i)->GetType2() == "Options"){

			printf("Click SUCCESSSSS\n");
			printf("Next State set to Options\n");
			setNextState("Options");
			return false;
		}
		if(m_engine->m_gom->m_vButtons.at(i)->Update() == "Clicked" && m_engine->m_gom->m_vButtons.at(i)->GetType2() == "QuitGame"){
			printf("Click SUCCESSSSS\n");
			printf("This button doesnt work yet\n");
			//Exit Game
		}
	}
	return true;
}

void MainMenu::Draw()
{
	m_engine->m_gom->DrawButtons();

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


