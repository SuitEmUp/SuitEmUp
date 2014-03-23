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
#include <sstream>




Customize::Customize(Engine *engine) 
{
	m_engine = engine;
	next_state = "";
	m_input = m_engine->m_input;

	m_weapons_available = Config::getInt("weapons_available", 0);
	m_currentSuit = Config::getInt("current_suit", 0);
	m_currentTruck = Config::getInt("current_truck", 0);

	m_trinketboxactivator = false;
	m_trinketboxlock = false;

	howmuchitcosts_suit = 1000;
	howmuchitcosts_weapon = 2000;
	howmuchitcosts_truck = 1500;
	//howmuchitcosts_trinket = 500;

	//stats text
	m_stats = nullptr;
	m_font = nullptr;
	m_stats = new sf::Text;
	m_font = new sf::Font;

	if (!m_font->loadFromFile("../assets/fonts/Viking_n.ttf"))
	{ printf("Could not load font\n"); }

	m_stats->setFont(*m_font);
	m_stats->setCharacterSize(20);
	m_stats->setColor(sf::Color::Black);
	m_stats->setPosition(430.f, 400.f);	
	m_stats->setStyle(sf::Text::Bold);

	items[0] = "\nLenkár: Normal MoveSpeed\n";
	items[1] = "\nSuravíra: Fast MoveSpeed\n";
	items[2] = "\nChaya: Faster MoveSpeed\n";
	items[3] = "\nThe Negotiator: 1 dmg\n";
	items[4] = "\nThumper: 3 dmg piercing\n";
	items[5] = "\nDiplomacy: 1 dmg Burst\n";
	items[6] = "\nMukai: 100 hp\n";
	items[7] = "\nMukai: 200 hp\n";
	items[8] = "\nMukai: 300hp\n";

	m_currentweapon = items[3];
	m_currentsuit = items[0];
	m_currenttruck = items[6];

	once = 0;
};

bool Customize::Init()
{
	m_engine->m_window->clear(sf::Color(165, 35, 23, 255));

	counts = 0;

	m_weapons_available = Config::getInt("weapons_available", 0);
	m_currentSuit = Config::getInt("current_suit", 0);
	m_currentWeapon = Config::getInt("current_weapon", 0);
	m_currentTruck = Config::getInt("current_truck", 0);



	tempName_change = "02";
	//sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2<float>(150.0f, 150.0f));
	//m_rects.push_back(rectangle);

	//Background, borders

	m_border = m_engine->m_spritemanager->Load("../data/misc/customization/border.png", "Backgrund", 1.0, 1.0);
	m_statbox = m_engine->m_spritemanager->Load("../data/misc/customization/stats_box.png", "StatBox", 1.0, 1.0);
	m_statbox->setPosition(354,373);
	m_decal = m_engine->m_spritemanager->Load("../data/misc/customization/decal.png", "Decal", 1.0, 1.0);
	m_decal->setPosition(932, 373);																																									

	if(m_currentSuit == 0)
	{
		m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_1.png", "Suit1", 1.0, 1.0);
		m_suit->setPosition(45, 114);
		m_currentsuit = items[0];
		howmuchitcosts_suit = 1000;
	}
	else if (m_currentSuit == 1) 
	{
		m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_2.png", "Suit2", 1.0, 1.0);
		m_suit->setPosition(45, 114);
		m_currentsuit = items[1];
	}
	else if (m_currentSuit == 2) 
	{
		m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_3.png", "Suit3", 1.0, 1.0);
		m_suit->setPosition(45, 114);
		m_currentsuit = items[2];
	}
	if(m_currentWeapon == 0)
	{
		m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "Weapon1", 1.0, 1.0);
		m_currentweapon = items[3];
		m_weapon->setPosition(354, 114);
		howmuchitcosts_weapon = 2000;
	}
	else if(m_currentWeapon == 1)
	{
		m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "Weapon2", 1.0, 1.0);
		m_currentweapon = items[4];
		m_weapon->setPosition(354, 114);
	}
	else if(m_currentWeapon == 2)
	{
		m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "Weapon3", 1.0, 1.0);
		m_weapon->setPosition(354, 114);
		m_currentweapon = items[5];
	}

	if(m_currentTruck == 0)
	{
		howmuchitcosts_truck = 1500;
		m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_1.png", "Truck1", 1.0, 1.0);
		m_currenttruck = items[6];
		m_truck->setPosition(932, 114);
	}
	else if(m_currentTruck == 1)
	{
		m_currenttruck = items[7];
		m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_2.png", "Truck2", 1.0, 1.0);
		m_truck->setPosition(932, 114);
	}
	else if(m_currentTruck == 2)
	{
		m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_3.png", "Truck3", 1.0, 1.0);
		m_truck->setPosition(932, 114);
		m_currenttruck = items[8];
	}

	//Buttons
	m_engine->m_gom->CreateCusomizationButtons();

	if(m_input->IsDown(sf::Keyboard::Tab))
	{
		m_pauselock = true;
	}
	else if(m_input->IsUp(sf::Keyboard::Tab))
	{
		m_pauselock = false;
	}

	//glow feedback

	m_smallupgrade1 = m_engine->m_spritemanager->Load("../data/buttons/back_button_glow.png", "SmallGlow1", 1.0, 1.0);
	m_smallupgrade1->setPosition(Config::getInt("customize_padding_big", 0), Config::getInt("customize_padding_big", 0));
	m_smallupgrade2 = m_engine->m_spritemanager->Load("../data/buttons/back_button_glow.png", "SmallGlow2", 1.0, 1.0);
	m_smallupgrade2->setPosition(932, Config::getInt("customize_padding_big", 0));
	m_bigupgrade = m_engine->m_spritemanager->Load("../data/buttons/upgrade_weapon_glow.png", "BigGlow", 1.0, 1.0);
	m_bigupgrade->setPosition(413, Config::getInt("customize_padding_big", 0));
	m_leftbutton = m_engine->m_spritemanager->Load("../data/buttons/change_left_button_glow.png", "LeftGlow", 1.0, 1.0);
	m_leftbutton->setPosition(354, Config::getInt("customize_padding_big", 0));
	m_rightbutton = m_engine->m_spritemanager->Load("../data/buttons/change_left_button_glow.png", "RightGlow", 1.0, 1.0);
	m_rightbutton->setPosition(873, Config::getInt("customize_padding_big", 0));
	m_back = m_engine->m_spritemanager->Load("../data/buttons/back_button_glow.png", "Back", 1.0, 1.0);
	m_back->setPosition(Config::getInt("customize_padding_big", 0), ((Config::getInt("window_h", 0) - Config::getInt("customize_padding_big",0) - 64)));


	//m_suitrect = new sf::RectangleShape;					m_suitrect->setSize(sf::Vector2f(299, 50));
	//m_suitrect->setFillColor(sf::Color(255,255,255,100));		m_suitrect->setOutlineColor(sf::Color::Black);
	//m_suitrect->setOutlineThickness(2);						m_suitrect->setPosition(sf::Vector2f(47, 556));

	//m_weaponrect = new sf::RectangleShape;					m_weaponrect->setSize(sf::Vector2f(568, 50));
	//m_weaponrect->setFillColor(sf::Color(255,255,255,100));	m_weaponrect->setOutlineColor(sf::Color::Black);
	//m_weaponrect->setOutlineThickness(2);					m_weaponrect->setPosition(sf::Vector2f(356, 315));

	//m_truckrect = new sf::RectangleShape;					m_truckrect->setSize(sf::Vector2f(299, 50));
	//m_truckrect->setFillColor(sf::Color(255,255,255,100));		m_truckrect->setOutlineColor(sf::Color::Black);
	//m_truckrect->setOutlineThickness(2);					m_truckrect->setPosition(sf::Vector2f(934, 315 ));

	sf::RectangleShape* t_suitrect = new sf::RectangleShape;					t_suitrect->setSize(sf::Vector2f(287, 50));
	t_suitrect->setFillColor(sf::Color(255,255,255,50));		t_suitrect->setOutlineColor(sf::Color::Black);
	t_suitrect->setOutlineThickness(2);						t_suitrect->setPosition(sf::Vector2f(53, 547));

	m_rects.push_back(t_suitrect);

	sf::RectangleShape* t_weaponrect = new sf::RectangleShape;					t_weaponrect->setSize(sf::Vector2f(568, 50));
	t_weaponrect->setFillColor(sf::Color(255,255,255,50));	t_weaponrect->setOutlineColor(sf::Color::Black);
	t_weaponrect->setOutlineThickness(2);					t_weaponrect->setPosition(sf::Vector2f(356, 315));

	m_rects.push_back(t_weaponrect);

	sf::RectangleShape* t_truckrect = new sf::RectangleShape;					t_truckrect->setSize(sf::Vector2f(299, 50));
	t_truckrect->setFillColor(sf::Color(255,255,255,50));	t_truckrect->setOutlineColor(sf::Color::Black);
	t_truckrect->setOutlineThickness(2);						t_truckrect->setPosition(sf::Vector2f(934, 315 ));

	m_rects.push_back(t_truckrect);


	//getcosts
	m_currentsuitcost = Config::get("currentsuitcost");
	m_currentweaponcost = Config::get("currentweaponcost");
	m_currenttruckcost = Config::get("currenttruckcost");

	//text
	m_foont = new sf::Font;
	m_foont->loadFromFile("../assets/fonts/AdobeFangsongStd-Regular.otf");

	m_suitcostText = new sf::Text;							
	m_suitcostText->setOrigin(m_suitcostText->getLocalBounds().height/2,0);		m_suitcostText->setFont(*m_foont);
	m_suitcostText->setString(Config::get("currentsuitcost"));					m_suitcostText->setPosition(sf::Vector2f(150,555));		
	m_suitcostText->setColor(sf::Color::Black);						m_suitcostText->setCharacterSize(40);

	m_weaponcostText = new sf::Text;
	m_weaponcostText->setOrigin(m_weaponcostText->getLocalBounds().height/2,0);	m_weaponcostText->setFont(*m_foont);
	m_weaponcostText->setString(Config::get("currentweaponcost"));				m_weaponcostText->setPosition(sf::Vector2f(600,313));		
	m_weaponcostText->setColor(sf::Color::Black);						m_weaponcostText->setCharacterSize(40);

	m_truckcostText = new sf::Text;
	m_truckcostText->setOrigin(m_truckcostText->getLocalBounds().height/2,0);	m_truckcostText->setFont(*m_foont);
	m_truckcostText->setString(Config::get("currenttruckcost"));				m_truckcostText->setPosition(sf::Vector2f(1037,313));		
	m_truckcostText->setColor(sf::Color::Black);						m_truckcostText->setCharacterSize(40);


	// fullösning
	if(Config::getInt("current_suit", 0) == 2)
	{
		m_suitcostText->setPosition(sf::Vector2f(77,555));
		m_suitcostText->setCharacterSize(30);
	}
	if(Config::getInt("weapons_available", 0) == 3)
	{
		m_weaponcostText->setPosition(sf::Vector2f(530,319));
		m_weaponcostText->setCharacterSize(30);
	}
	if(Config::getInt("current_truck", 0) == 2)
	{
		m_truckcostText->setPosition(sf::Vector2f(960,319));
		m_truckcostText->setCharacterSize(30);
	}


	printf("State: Customize, Initialized\n");

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
	//update score
	howmuchmoneyihave = m_engine->m_gom->GetScore(howmuchmoneyihave);

	if(Config::getInt("current_suit", 0) != 2)
	{
		m_suitcostText->setPosition(sf::Vector2f(150,555));	
		m_suitcostText->setCharacterSize(30);
	}
	if(Config::getInt("weapons_available", 0) != 3)
	{
		m_weaponcostText->setPosition(sf::Vector2f(600,313));
		m_weaponcostText->setCharacterSize(30);
	}
	if(Config::getInt("current_truck", 0) != 2)
	{
		m_truckcostText->setPosition(sf::Vector2f(1037,313));
		m_truckcostText->setCharacterSize(30);
	}

	std::ostringstream ss;

	ss << "\t\tAriana's Stats\n" <<
		"\n\t\tScore: " << m_engine->m_gom->GetScore(once) << "\n" <<
		m_currentsuit << m_currentweapon << m_currenttruck;

	m_stats->setString(ss.str());


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
					if(m_currentSuit != 2)
					{
						//score
						m_engine->m_gom->Buy(howmuchitcosts_suit);
						howmuchitcosts_suit = 2000;

						if(m_currentSuit == 0)
						{
							m_engine->m_gom->m_player->SetSuitType("Level2");
							m_currentSuit = 1;
							if (m_currentSuit == 1) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_2.png", "Suit2", 1.0, 1.0);
							Config::set("current_suit","1");

							Config::set("currentsuitcost", "2000");
							m_currentsuit = items[1];
						}
						else if(m_currentSuit == 1)
						{
							m_engine->m_gom->m_player->SetSuitType("Level3");
							m_currentSuit = 2;
							if (m_currentSuit == 2) m_suit = m_engine->m_spritemanager->Load("../data/misc/customization/suit_3.png", "Suit3", 1.0, 1.0);
							Config::set("current_suit","2");

							Config::set("currentsuitcost", "Upgrade Complete");
							m_suitcostText->setPosition(sf::Vector2f(77,555));
							m_suitcostText->setCharacterSize(30);
							m_currentsuit = items[2];
						}
						m_suit->setPosition(45, 114);
					}
					Config::renew();
				}

				//----------------------
				//Weapon Stuff
				//----------------------

				//Upgrade Weapon
				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeWeapon" && howmuchitcosts_weapon <= howmuchmoneyihave && m_weapons_available != 3)
				{

					//score
					m_engine->m_gom->Buy(howmuchitcosts_weapon);
					howmuchitcosts_weapon = 3000;
					if(m_weapons_available == 1)
					{
						m_weapons_available = 2;
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "1");
						Config::set("weapons_available","2");
						printf("Needlegun is now available!\n");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("Needlegun");
						Config::set("currentweaponcost", "3000");
						m_currentweapon = items[4];
					}
					else if(m_weapons_available == 2)
					{
						m_weapons_available = 3;
						Config::set("weapons_available","3");
						printf("ArmCannon is now available!\n");
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "2");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("ArmCannon");
						Config::set("currentweaponcost", "Upgrade Complete");
						m_weaponcostText->setPosition(sf::Vector2f(530,319));
						m_weaponcostText->setCharacterSize(30);
						m_currentweapon = items[5];
					}
					else if(m_weapons_available == 3){printf("Upgrade already complete\n");}
					else {printf("Upgrade failed");}

					std::cout << m_weapons_available << std::endl;
					Config::renew();
					m_weapon->setPosition(354, 114);
				}

				//NextWeapon
				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponRight" || m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponLeft")
				{
					if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponRight")
					{
						if(m_currentWeapon == 0 && m_weapons_available > 1)
						{
							m_currentWeapon = 1;
							m_currentweapon = items[4];
						}
						else if(m_currentWeapon == 1 && m_weapons_available > 2)
						{
							m_currentWeapon = 2;
							m_currentweapon = items[5];
						}
						else if(m_currentWeapon == 2 && m_weapons_available == 3)
						{
							m_currentWeapon = 0;
							m_currentweapon = items[3];
						}
						else if(m_currentWeapon == 1 && m_weapons_available == 2)
						{
							m_currentWeapon = 0;
							m_currentweapon = items[3];
						}

					}
					//PrevWeapon
					if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponLeft")
					{
						m_currentWeapon -= 1;

						if(m_currentWeapon == 0 && m_weapons_available == 3)
						{
							m_currentWeapon = 3;
							m_currentweapon = items[5];
						}
						else if(m_currentWeapon == 0 && m_weapons_available == 2)
						{
							m_currentWeapon = 1;
							m_currentweapon = items[4];
						}
						else if(m_currentWeapon == 1 && m_weapons_available > 1)
						{	m_currentWeapon = 0;
						m_currentweapon = items[3];
						}
						else if(m_currentWeapon == 2 && m_weapons_available > 2)
						{
							m_currentWeapon = 1;
							m_currentweapon = items[4];
						}
						else if(m_currentWeapon = 0)
							printf("You need to upgrade before you can change weapon\n");
					}
					//if(m_currentWeapon == 0 && m_weapons_available == 3)

					if(m_currentWeapon == 0)
					{		
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_1.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "0");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("Revolver");
					}
					if(m_currentWeapon == 1)
					{
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_2.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "1");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("Needlegun");
					}
					if(m_currentWeapon == 2)
					{
						m_weapon = m_engine->m_spritemanager->Load("../data/misc/customization/weapon_3.png", "weapon", 1.0, 1.0);
						Config::set("current_weapon", "2");
						m_currentWeapon = Config::getInt("current_weapon", 0);
						m_engine->m_gom->m_player->SetWeaponType("ArmCannon");
					}
					m_weapon->setPosition(354, 114);
				}

				//----------------------
				//Truck Stuff
				//----------------------

				std::string count[3] = {"0", "1", "2" };

				//Upgrade Truck
				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeTruck" && howmuchitcosts_truck <= howmuchmoneyihave)
				{

					if(Config::getInt("current_truck", 0) == 1)
					{

						m_currenttruck = items[8];
						Config::set("currenttruckcost", "Upgrade Complete");
						Config::set("current_truck", "2");
						m_engine->m_gom->UpgradeMaxHpAndSprites();
						m_truckcostText->setPosition(sf::Vector2f(960,319));
						m_truckcostText->setCharacterSize(30);
						m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_3.png", "Truck3", 1.0, 1.0);
						m_truck->setPosition(932, 114);
						m_currentTruck++;
						//score
						m_engine->m_gom->Buy(howmuchitcosts_truck);
						howmuchitcosts_truck = 0;
					}
					if(Config::getInt("current_truck", 0) == 0)
					{


						m_currenttruck = items[7];
						Config::set("currenttruckcost", "2500");
						Config::set("current_truck", "1");
						m_engine->m_gom->UpgradeMaxHpAndSprites();
						m_truckcostText->setPosition(sf::Vector2f(960,319));
						m_truckcostText->setCharacterSize(30);
						m_truck = m_engine->m_spritemanager->Load("../data/misc/customization/truck_2.png", "Truck2", 1.0, 1.0);
						m_truck->setPosition(932, 114);
						//score
						m_engine->m_gom->Buy(howmuchitcosts_truck);
						howmuchitcosts_truck = 2500;
						m_currentTruck++;

					}			
				}

				if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "Back")
				{
					printf("Next State set to Game\n");
					setNextState("Game");
					return false;
				}
			}
			if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "QuitGame")
			{
				printf("Next State set to Game\n");
				setNextState("Game");
				return false;
			}
		}


		if(m_input->IsUp(sf::Keyboard::Tab) && Config::getInt("quickcustomize",0) == 1 && m_pauselock == true)
		{
			printf("Next State set to Game\n");
			setNextState("Game");
			return false;
		}

		m_suitcostText->setString(Config::get("currentsuitcost"));
		m_weaponcostText->setString(Config::get("currentweaponcost"));
		m_truckcostText->setString(Config::get("currenttruckcost"));

		ss.str("");

		return true;
};


void Customize::Draw()
{
	m_engine->m_window->clear(sf::Color(34, 4, 1, 255));


	m_engine->m_window->draw(*m_border);
	m_engine->m_window->draw(*m_suit);
	m_engine->m_window->draw(*m_weapon);
	m_engine->m_window->draw(*m_truck);
	m_engine->m_window->draw(*m_statbox);
	m_engine->m_window->draw(*m_decal);
	m_engine->m_window->draw(*m_stats);


	//buttons
	m_engine->m_gom->DrawCustomizationButtons();
	for(int i = 0; i < m_engine->m_gom->m_vCustomizeButtons.size(); i++)
	{
		if(m_engine->m_gom->m_vCustomizeButtons.at(i)->Update() == "Hovering")
		{
			if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeSuit"){
				m_engine->m_window->draw(*m_smallupgrade1);		
			}
			if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponLeft"){
				m_engine->m_window->draw(*m_leftbutton);		
			}
			if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeWeapon"){
				m_engine->m_window->draw(*m_bigupgrade);		
			}
			if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "ChangeWeaponRight"){
				m_engine->m_window->draw(*m_rightbutton);	
			}
			if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "UpgradeTruck"){
				m_engine->m_window->draw(*m_smallupgrade2);
			}
			if(m_engine->m_gom->m_vCustomizeButtons.at(i)->GetType2() == "Back"){
				m_engine->m_window->draw(*m_back);
			}
		}
	}

	for(int i = 0; i<m_rects.size(); i++){
		m_engine->m_window->draw(*m_rects.at(i));
	}

	/*m_engine->m_window->draw(*m_suitrect);
	m_engine->m_window->draw(*m_weaponrect);
	m_engine->m_window->draw(*m_truckrect);*/
	m_engine->m_window->draw(*m_suitcostText);
	m_engine->m_window->draw(*m_weaponcostText);
	m_engine->m_window->draw(*m_truckcostText);
};


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


