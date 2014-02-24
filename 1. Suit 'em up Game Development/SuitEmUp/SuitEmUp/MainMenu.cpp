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
};

bool MainMenu::Init()
{
	
	
	//-----------
	//sf::Font font;
	//if (!font.loadFromFile("../assets/fonts/AdobeGothicStd-Bold")) { printf("Could not load font\n"); }
	//sf::Text text;
	//text.setFont(font);
	//text.setString("Is this working?");
	//text.setCharacterSize(24);
	//text.setColor(sf::Color::Red);

	//m_InputManager = nullptr;

	//-----------
	printf("State: MainMenu,  Initialized\n");
	printf("F1 - F4 to Change States\n");


	//m_TestButton = new Button(m_gom->m_spritemanager->Load("../data/buttons/Start_Game.png", "StartGame"), (Config::getInt("window_w", 0)/2 - 119), 150);

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

	if(m_input->IsDown(sf::Keyboard::F3))
	{
		printf("Next State set to Customize\n");
		setNextState("Customize");
		return false;
	};

	return true;
}

void MainMenu::Draw()
{
	//m_gom->m_window->draw(*m_TestButton->GetSprite());
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


