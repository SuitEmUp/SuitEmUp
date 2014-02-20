#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include <iostream>

#include "Customize.h"
#include "InputManager.h"
#include "Config.h"
#include "Button.h"
#include "SpriteManager.h"
#include "GameObjectManager.h"




Customize::Customize(Engine *engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;

	m_currentSuit = Config::getInt("current_suit", 0);
	m_currentWeapon = Config::getInt("current_weapon", 0);
	m_currentTruck = Config::getInt("current_truck", 0);

};

bool Customize::Init()
{
	tempName_change = "02";
	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2<float>(150.0f, 150.0f));
	m_rects.push_back(rectangle);

	printf("State: Customize, Initialized\n");
	printf("F1 - F4 to Change States\n");



	//Background, borders

	m_border = m_engine->m_spritemanager->Load("../data/misc/customization/border.png", "bakgrund", 1.0, 1.0);

	if(m_currentSuit == 0) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_1.png", "suit", 1.0, 1.0);
	else if (m_currentSuit == 1) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_2.png", "suit", 1.0, 1.0);
	else if (m_currentSuit == 2) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_3.png", "suit", 1.0, 1.0);

	m_suit->setPosition(45, 114);

	if(m_currentWeapon == 0)m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "weapon", 1.0, 1.0);
	else if(m_currentWeapon == 1)m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "weapon", 1.0, 1.0);
	else if(m_currentWeapon == 2)m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "weapon", 1.0, 1.0);

	m_weapon->setPosition(354, 114);

	if(m_currentTruck == 0)m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_1.png", "truck", 1.0, 1.0);
	else if(m_currentTruck == 1)m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_2.png", "truck", 1.0, 1.0);
	else if(m_currentTruck == 2)m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_3.png", "truck", 1.0, 1.0);

	m_truck->setPosition(932, 114);

	//Buttons
	m_engine->m_gom->CreateCusomizationButtons();


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


	for(int i = 0; i < m_engine->m_gom->m_vCustomizeButtons.size(); i++)
	{
		//----------------------
		//Suit Stuff
		//----------------------

		//Upgrade Suit
		if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked" 
			&& m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeSuit")
		{
			printf("Click SUCCESSSSS\n");
			printf("Suit Upgraded\n");
		}
		//Next Suit
		if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked" 
			&& m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeSuitRight")
		{
			if(m_currentSuit == 0)
			{
				m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_2.png", "suit", 1.0, 1.0);
				Config::set("current_suit", "1");
				m_currentSuit = Config::getInt("current_suit", 0);
			}
			else if(m_currentSuit == 1)
			{
				m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_3.png", "suit", 1.0, 1.0);
				Config::set("current_suit", "2");
				m_currentSuit = Config::getInt("current_suit", 0);
			}
			else if(m_currentSuit == 2)
			{
				m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_1.png", "suit", 1.0, 1.0);
				Config::set("current_suit", "0");
				m_currentSuit = Config::getInt("current_suit", 0);
			}
			m_suit->setPosition(45, 114);
		}
		//Prev Suit
		if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked" 
			&& m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeSuitLeft")
		{
			if(m_currentSuit == 0)
			{
				m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_3.png", "suit", 1.0, 1.0);
				Config::set("current_suit", "2");
				m_currentSuit = Config::getInt("current_suit", 0);
			}

			else if(m_currentSuit == 1)
			{
				m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_1.png", "suit", 1.0, 1.0);
				Config::set("current_suit", "0");
				m_currentSuit = Config::getInt("current_suit", 0);
			}
			else if(m_currentSuit == 2)
			{
				m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_2.png", "suit", 1.0, 1.0);
				Config::set("current_suit", "1");
				m_currentSuit = Config::getInt("current_suit", 0);
			}
			m_suit->setPosition(45, 114);
		}
		//----------------------
		//Weapon Stuff
		//----------------------

		//Next Weapon
		if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked" 
			&& m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponRight")
		{
			if(m_currentWeapon == 0)
			{
				m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "weapon", 1.0, 1.0);
				Config::set("current_weapon", "1");
				m_currentWeapon = Config::getInt("current_weapon", 0);
			}
			else if(m_currentWeapon == 1)
			{
				m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "weapon", 1.0, 1.0);
				Config::set("current_weapon", "2");
				m_currentWeapon = Config::getInt("current_weapon", 0);
			}
			else if(m_currentWeapon == 2)
			{
				m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "weapon", 1.0, 1.0);
				Config::set("current_weapon", "0");
				m_currentWeapon = Config::getInt("current_weapon", 0);
			}
			m_weapon->setPosition(354, 114);
		}
		//Prev Weapon
		if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked" 
			&& m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponLeft")
		{
			if(m_currentWeapon == 0)
			{
				m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "weapon", 1.0, 1.0);
				Config::set("current_weapon", "2");
				m_currentWeapon = Config::getInt("current_weapon", 0);
			}

			else if(m_currentWeapon == 1)
			{
				m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "weapon", 1.0, 1.0);
				Config::set("current_weapon", "0");
				m_currentWeapon = Config::getInt("current_weapon", 0);
			}
			else if(m_currentWeapon == 2)
			{
				m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "weapon", 1.0, 1.0);
				Config::set("current_weapon", "1");
				m_currentWeapon = Config::getInt("current_weapon", 0);
			}
			m_weapon->setPosition(354, 114);
		}
		//----------------------
		//Truck Stuff
		//----------------------

		//Next Truck
		if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked" 
			&& m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeTruckRight")
		{
			if(m_currentTruck == 0)
			{
				m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_2.png", "truck", 1.0, 1.0);
				Config::set("current_truck", "1");
				m_currentTruck = Config::getInt("current_truck", 0);
			}
			else if(m_currentTruck == 1)
			{
				m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_3.png", "truck", 1.0, 1.0);
				Config::set("current_truck", "2");
				m_currentTruck = Config::getInt("current_truck", 0);
			}
			else if(m_currentTruck == 2)
			{
				m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_1.png", "truck", 1.0, 1.0);
				Config::set("current_truck", "0");
				m_currentTruck = Config::getInt("current_truck", 0);
			}
			m_truck->setPosition(932, 114);
		}
		//Prev Truck
		if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked" 
			&& m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeTruckLeft")
		{
			if(m_currentTruck == 0)
			{
				m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_3.png", "truck", 1.0, 1.0);
				Config::set("current_truck", "2");
				m_currentTruck = Config::getInt("current_truck", 0);
			}

			else if(m_currentTruck == 1)
			{
				m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_1.png", "truck", 1.0, 1.0);
				Config::set("current_truck", "0");
				m_currentTruck = Config::getInt("current_truck", 0);
			}
			else if(m_currentTruck == 2)
			{
				m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_2.png", "truck", 1.0, 1.0);
				Config::set("current_truck", "1");
				m_currentTruck = Config::getInt("current_truck", 0);
			}
			m_truck->setPosition(932, 114);
		}

	}
	return true;
};

void Customize::Draw()
{
	m_engine->m_window->draw(*m_border);
	m_engine->m_window->draw(*m_suit);
	m_engine->m_window->draw(*m_weapon);
	m_engine->m_window->draw(*m_truck);
	//buttons
	m_engine->m_gom->DrawCustomizationButtons();
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


