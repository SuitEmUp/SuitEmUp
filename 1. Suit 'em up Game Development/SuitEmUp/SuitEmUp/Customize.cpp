//Customize.cpp

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
	m_weapons_available = Config::getInt("weapons_available", 0);
	m_currentSuit = Config::getInt("current_suit", 0);

	m_currentSuit = Config::getInt("current_suit", 0);
	m_currentWeapon = Config::getInt("current_weapon", 0);
	m_currentTruck = Config::getInt("current_truck", 0);
	howmuchitcosts_suit = 1000;
	howmuchitcosts_weapon = 1500;
	howmuchitcosts_truck = 1200;
	howmuchitcosts_trinket = 500;



};

bool Customize::Init()
{
	tempName_change = "02";
	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2<float>(150.0f, 150.0f));
	m_rects.push_back(rectangle);

	//Background, borders

	m_border = m_engine->m_spritemanager->Load("../data/misc/customization/border.png", "Backgrund", 1.0, 1.0);

	if(m_currentSuit == 0) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_1.png", "Suit1", 1.0, 1.0);
	else if (m_currentSuit == 1) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_2.png", "Suit2", 1.0, 1.0);
	else if (m_currentSuit == 2) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_3.png", "Suit3", 1.0, 1.0);
	m_suit->setPosition(45, 114);

	if(m_currentWeapon == 0)m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "Weapon1", 1.0, 1.0);
	else if(m_currentWeapon == 1)m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "Weapon2", 1.0, 1.0);
	else if(m_currentWeapon == 2)m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "Weapon3", 1.0, 1.0);
	m_weapon->setPosition(354, 114);

	if(m_currentTruck == 0)m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_1.png", "Truck1", 1.0, 1.0);
	else if(m_currentTruck == 1)m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_2.png", "Truck2", 1.0, 1.0);
	else if(m_currentTruck == 2)m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_3.png", "Truck3", 1.0, 1.0);
	m_truck->setPosition(932, 114);

	m_statbox = m_engine->m_spritemanager->Load("../data/misc/customization/stats_box.png", "StatBox", 1.0, 1.0);
	m_statbox->setPosition(354, 373);

	m_trinketbox = m_engine->m_spritemanager->Load("../data/misc/customization/trinkets_box.png", "TrinketBox", 1.0, 1.0);
	m_trinketbox->setPosition(932, 373);

	m_trinketboxsprite = m_engine->m_spritemanager->Load("../data/misc/customization/trinket_box_big.png", "BigTrinketBox", 1.0, 1.0);
	m_trinketboxsprite->setPosition(52, 52);
	//Buttons
	m_engine->m_gom->CreateCusomizationButtons();
	m_engine->m_gom->CreateTrinketButtons();

	if(m_input->IsDown(sf::Keyboard::Tab))
	{
		m_pauselock = true;
	}
	else if(m_input->IsUp(sf::Keyboard::Tab))
	{
		m_pauselock = false;
	}

	printf("State: Customize, Initialized\n");
	printf("F1 - F4 to Change States\n");

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

	//update score
	howmuchmoneyihave = m_engine->m_gom->GetScore(howmuchmoneyihave);


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
			if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Clicked")
			{
				//----------------------
				//Suit Stuff
				//----------------------

				//Upgrade Suit
				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeSuit" && howmuchitcosts_suit <= howmuchmoneyihave)
				{
					//score
					m_engine->m_gom->Buy(howmuchitcosts_suit);
					howmuchitcosts_suit + 1500;
					if(m_currentSuit == 0)
					{
						m_engine->m_gom->m_player->SetSuitType("Level2");
						m_currentSuit = 1;
						Config::set("current_suit","1");
						printf("Suit Upgraded\n");
					}
					else if(m_currentSuit == 1)
					{
						m_engine->m_gom->m_player->SetSuitType("Level3");
						m_currentSuit = 2;
						Config::set("current_suit","2");
						printf("Suit Upgraded\n");
					}
				}
				//----------------------
				//Weapon Stuff
				//----------------------

				//Upgrade Weapon
				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeWeapon" && howmuchitcosts_weapon <= howmuchmoneyihave && m_weapons_available != 3)
				{
					std::cout << m_weapons_available << std::endl;
					//score
					m_engine->m_gom->Buy(howmuchitcosts_weapon);
					howmuchitcosts_weapon + 1500;
					if(m_weapons_available == 1)
					{
						m_weapons_available = 2;
						Config::set("weapons_available","2");
						printf("Needlegun is now available!\n");

					}
					else if(m_weapons_available == 2)
					{
						m_weapons_available = 3;
						Config::set("weapons_available","3");
						printf("ArmCannon is now available!\n");
					}
					else if(m_weapons_available == 3){printf("Upgrade already complete\n");}
					else {printf("Upgrade failed");}

					std::cout << m_weapons_available << std::endl;
					Config::renew();
				}


				//Next Weapon
				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponRight")
				{
					if(m_currentWeapon == 0 && (m_weapons_available == 2 || m_weapons_available >= 3))
					{
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "1");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("Needlegun");
					}
					else if(m_currentWeapon == 1 && (m_weapons_available == 3 || m_weapons_available >= 3))
					{
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "2");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("ArmCannon");
					}
					else if(m_currentWeapon == 2 && (m_weapons_available == 1 || m_weapons_available >= 3))
					{
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "0");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("Revolver");
					}
				}

				m_weapon->setPosition(354, 114);
				//Prev Weapon
				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponLeft")
				{
					if(m_currentWeapon == 0 && m_weapons_available == 3)
					{
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "2");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("ArmCannon");
					}

					else if(m_currentWeapon == 1 || (m_currentWeapon == 0 && m_weapons_available == 2))
					{
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "0");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("Revolver");
					}
					else if(m_currentWeapon == 2)
					{
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "1");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("Needlegun");
					}
					m_weapon->setPosition(354, 114);
				}
				//----------------------
				//Truck Stuff
				//----------------------

				//Upgrade Truck
				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeTruck" && howmuchitcosts_weapon <= howmuchmoneyihave)
				{
					//score
					m_engine->m_gom->Buy(howmuchitcosts_truck);
					howmuchitcosts_truck + 1500;
					printf("KOEPT SUIT\n");
					printf("Click SUCCESSSSS\n");
					printf("Suit Upgraded\n");


				}

				//TrinketBox
				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "Slot1")
				{
					m_trinketboxactivator = true;
				}

				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "Back")
				{
					printf("Next State set to Game\n");
					setNextState("Game");
					return false;
				}


			}
		}
		if(m_input->IsUp(sf::Keyboard::Tab) && Config::getInt("quickcustomize",0) == 1 && m_pauselock == true)
		{
			printf("Next State set to Game\n");
			setNextState("Game");
			return false;
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


