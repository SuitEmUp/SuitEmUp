#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include <iostream>

#include "Customize.h"
#include "InputManager.h"
#include "Config.h"
#include "Button.h"
#include "SpriteManager.h"
#include "GameObjectManager.h"
#include "PlayerObject.h"




Customize::Customize(Engine *engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;
	m_trinketboxactivator = false;
	m_trinketboxlock = false;

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

	m_border = m_engine->m_spritemanager->Load("../data/misc/customization/border.png", "Backgrund", 1.0, 1.0);

	if(m_currentSuit == 0) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_1.png", "SuitL", 1.0, 1.0);
	else if (m_currentSuit == 1) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_2.png", "SuitU", 1.0, 1.0);
	else if (m_currentSuit == 2) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_3.png", "SuitR", 1.0, 1.0);
	m_suit->setPosition(45, 114);

	if(m_currentWeapon == 0)m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "WeaponL", 1.0, 1.0);
	else if(m_currentWeapon == 1)m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "WeaponU", 1.0, 1.0);
	else if(m_currentWeapon == 2)m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "WeaponR", 1.0, 1.0);
	m_weapon->setPosition(354, 114);

	if(m_currentTruck == 0)m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_1.png", "TruckL", 1.0, 1.0);
	else if(m_currentTruck == 1)m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_2.png", "TruckU", 1.0, 1.0);
	else if(m_currentTruck == 2)m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_3.png", "TruckR", 1.0, 1.0);
	m_truck->setPosition(932, 114);

	m_statbox = m_engine->m_spritemanager->Load("../data/misc/customization/stats_box.png", "StatBoc", 1.0, 1.0);
	m_statbox->setPosition(354, 373);

	m_trinketbox = m_engine->m_spritemanager->Load("../data/misc/customization/trinkets_box.png", "TrinketBox", 1.0, 1.0);
	m_trinketbox->setPosition(932, 373);

	m_trinketboxsprite = m_engine->m_spritemanager->Load("../data/misc/customization/trinket_box_big.png", "BigTrinketBox", 1.0, 1.0);
	m_trinketboxsprite->setPosition(52, 52);
	//Buttons
	m_engine->m_gom->CreateCusomizationButtons();
	m_engine->m_gom->CreateTrinketButtons();



	return true;
};
void Customize::Exit(){
	m_engine->m_gom->EraseCustomizationButtons();
	m_engine->m_gom->EraseTrinketButtons();
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

	if(m_trinketboxactivator){
		if(m_input->GetMousePos().x <= m_trinketboxsprite->getPosition().x || m_input->GetMousePos().y <= m_trinketboxsprite->getPosition().y
			|| m_input->GetMousePos().x >= (m_trinketboxsprite->getPosition().x + m_trinketboxsprite->getLocalBounds().width)
			|| m_input->GetMousePos().y >= (m_trinketboxsprite->getPosition().y + m_trinketboxsprite->getLocalBounds().height))
		{
			if(m_input->Mouse_isDownOnce(sf::Mouse::Button::Left))
			{
				m_trinketboxlock = true;
			}
		}
	}


	if(!m_trinketboxactivator)
	{

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
					//m_engine->m_gom->m_player->SetSuitType("Level2");
				}
				else if(m_currentSuit == 1)
				{
					m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_3.png", "suit", 1.0, 1.0);
					Config::set("current_suit", "2");
					m_currentSuit = Config::getInt("current_suit", 0);
					//m_engine->m_gom->m_player->SetSuitType("Level3");
				}
				else if(m_currentSuit == 2)
				{
					m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_1.png", "suit", 1.0, 1.0);
					Config::set("current_suit", "0");
					m_currentSuit = Config::getInt("current_suit", 0);
					//m_engine->m_gom->m_player->SetSuitType("Level1");
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
					//m_engine->m_gom->m_player->SetSuitType("Level3");
				}

				else if(m_currentSuit == 1)
				{
					m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_1.png", "suit", 1.0, 1.0);
					Config::set("current_suit", "0");
					m_currentSuit = Config::getInt("current_suit", 0);
					//m_engine->m_gom->m_player->SetSuitType("Level1");
				}
				else if(m_currentSuit == 2)
				{
					m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_2.png", "suit", 1.0, 1.0);
					Config::set("current_suit", "1");
					m_currentSuit = Config::getInt("current_suit", 0);
					//m_engine->m_gom->m_player->SetSuitType("Level2");
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
					//m_engine->m_gom->m_player->SetWeaponType("Needlegun");
				}
				else if(m_currentWeapon == 1)
				{
					m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "weapon", 1.0, 1.0);
					Config::set("current_weapon", "2");
					m_currentWeapon = Config::getInt("current_weapon", 0);
					//m_engine->m_gom->m_player->SetWeaponType("ArmCannon");
				}
				else if(m_currentWeapon == 2)
				{
					m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "weapon", 1.0, 1.0);
					Config::set("current_weapon", "0");
					m_currentWeapon = Config::getInt("current_weapon", 0);
					//m_engine->m_gom->m_player->SetWeaponType("Revolver");
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
					//m_engine->m_gom->m_player->SetWeaponType("ArmCannon");
				}

				else if(m_currentWeapon == 1)
				{
					m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "weapon", 1.0, 1.0);
					Config::set("current_weapon", "0");
					m_currentWeapon = Config::getInt("current_weapon", 0);
					//m_engine->m_gom->m_player->SetWeaponType("Revolver");
				}
				else if(m_currentWeapon == 2)
				{
					m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "weapon", 1.0, 1.0);
					Config::set("current_weapon", "1");
					m_currentWeapon = Config::getInt("current_weapon", 0);
					//m_engine->m_gom->m_player->SetWeaponType("Needlegun");
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

			//TrinketBox
			if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked" 
				&& m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "Slot1")
			{
				m_trinketboxactivator = true;
			}
		}


	}
	if(m_trinketboxlock)
	{
		m_trinketboxactivator = false;
		m_trinketboxlock = false;
	}

	return true;
};

void Customize::Draw()
{
	m_engine->m_window->draw(*m_border);
	m_engine->m_window->draw(*m_suit);
	m_engine->m_window->draw(*m_weapon);
	m_engine->m_window->draw(*m_truck);
	m_engine->m_window->draw(*m_statbox);
	m_engine->m_window->draw(*m_trinketbox);
	//buttons
	m_engine->m_gom->DrawCustomizationButtons();

	if(m_trinketboxactivator) m_engine->m_window->draw(*m_trinketboxsprite);
	if(m_trinketboxactivator) m_engine->m_gom->DrawTrinketButtons();
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


