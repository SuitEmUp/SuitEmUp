//PlayerObject.cpp

#include "PlayerObject.h"
#include "Truck.h"
#include "InputManager.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "Config.h"
//PlayerObject::PlayerObject(Truck* truck, InputManager* input, sf::Sprite* sprite, sf::Sprite* update)
PlayerObject::PlayerObject(Truck* truck, InputManager* input, sf::Sprite* sprite, SpriteManager* p_spritemanager)
{
	m_spritemanager = p_spritemanager;
	m_position = sf::Vector2f(600, 400);
	//m_update = update;
	m_input = input;
	m_truck = truck;
	//m_unupdate = sprite;
	m_cooldown = 0;
	speed = 400;
	m_damage = 1;
	m_controltype = "Special";
	m_firetype = "Mouse";
	m_suittype = "Level1";
	m_weapontype = "Revolver";

	//update arian sprite 10ggr

	//vapen 1


	m_Level1Weapon1 = m_spritemanager->Load("../data/sprites/ariana/11.png", "11");
	m_Level1Weapon2 = m_spritemanager->Load("../data/sprites/ariana/12.png", "12");;
	m_Level1Weapon3 = m_spritemanager->Load("../data/sprites/ariana/13.png", "13");;

	m_Level2Weapon1 = m_spritemanager->Load("../data/sprites/ariana/21.png", "21");;
	m_Level2Weapon2 = m_spritemanager->Load("../data/sprites/ariana/22.png", "22");;
	m_Level2Weapon3 = m_spritemanager->Load("../data/sprites/ariana/23.png", "23");;

	m_Level3Weapon1 = m_spritemanager->Load("../data/sprites/ariana/31.png", "31");;
	m_Level3Weapon2 = m_spritemanager->Load("../data/sprites/ariana/32.png", "32");;
	m_Level3Weapon3 = m_spritemanager->Load("../data/sprites/ariana/33.png", "33");;


	m_sprite = m_Level1Weapon1;

	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);

	
};

bool PlayerObject::Update(float deltatime)
{
	if(m_input->IsDown(sf::Keyboard::O))
	{
		m_weapontype = "BoomWosh";
	}
	//sets suit stats
	if(m_suittype == "Level1")
	{
		speed = 350;
	}
	if(m_suittype == "Level2")
	{
		speed = 500;

	}
	if(m_suittype == "Level3")
	{
		speed = 600;

	}
	//sets weapon stats
	if(m_weapontype == "Revolver")
	{
		m_damage = 1;
		m_attackspeed = 0.3f;
	}
	if(m_weapontype == "Needlegun")
	{
		m_damage = 4;
		m_attackspeed = 0.85f;
	}
	if(m_weapontype == "ArmCannon")
	{
		m_damage = 1;
		m_attackspeed = 0.000002f;
	}
	if(m_weapontype == "BoomWosh")
	{
		m_damage = 50.0f;
		m_attackspeed = 1.5f;
	}
	//Set Sprites

	if(m_suittype == "Level1" && m_weapontype == "Revolver")
		m_sprite = m_Level1Weapon1;

	if(m_suittype == "Level1" && m_weapontype == "Needlegun")
		m_sprite = m_Level1Weapon2;

	if(m_suittype == "Level1" && m_weapontype == "ArmCannon")
		m_sprite = m_Level1Weapon3;

	if(m_suittype == "Level2" && m_weapontype == "Revolver")
		m_sprite = m_Level2Weapon1;

	if(m_suittype == "Level2" && m_weapontype == "Needlegun")
		m_sprite = m_Level2Weapon2;

	if(m_suittype == "Level2" && m_weapontype == "ArmCannon")
		m_sprite = m_Level2Weapon3;

	if(m_suittype == "Level3" && m_weapontype == "Revolver")
		m_sprite = m_Level3Weapon1;

	if(m_suittype == "Level3" && m_weapontype == "Needlegun")
		m_sprite = m_Level3Weapon2;

	if(m_suittype == "Level3" && m_weapontype == "ArmCannon")
		m_sprite = m_Level3Weapon3;


	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);
	//Correct Origin
	//if(m_weapontype == "Needlegun")







	m_velocity = sf::Vector2f(0, 0);

	if(m_input->IsDown(sf::Keyboard::B)){
		m_controltype = "Special";
	}
	if(m_input->IsDown(sf::Keyboard::N)){
		m_controltype = "Normal";
	}
	if(m_input->IsDown(sf::Keyboard::M)){
		m_controltype = "Viktor";
	}

	if(m_input->IsDown(sf::Keyboard::C)){
		m_firetype = "Mouse";
	}
	if(m_input->IsDown(sf::Keyboard::V)){
		m_firetype = "Viktor";
	}

	//UP/DOWN-GRADES
	if(m_input->IsDown(sf::Keyboard::U)){
		m_damage+=5;
	}
	if(m_input->IsDown(sf::Keyboard::I)){
		speed+=5;
	}
	if(m_input->IsDown(sf::Keyboard::J)){
		m_damage-=5;
	}
	if(m_input->IsDown(sf::Keyboard::K)){
		speed-=5;
	}
	if(m_input->IsDown(sf::Keyboard::O)){
		m_truck->Healed();
	}

	//m_position += m_truck->GetVelocity();	//Lets the player smoothly stick to the truck if we're going to implement truck movement

	float delta_x = m_truck->GetPosition().x - m_position.x;		//x-difference between truck and player
	float delta_y = m_truck->GetPosition().y - m_position.y;		//y-difference between truck and player

	float dist1 = sqrt((delta_x * delta_x) + (delta_y * delta_y));	//the actual distance between truck and player
	float dist2=dist1;	//The distance from the truck we want to have
	//This is soon used to maintain a certain distance from the truck when rotating around it, we don't want any centripetal effects.

	m_velocity = sf::Vector2f(0, 0);

	//MOVEMENT INPUTS
	if(m_controltype == "Normal"){
		// NORMAL MOVEMENT
		if(m_input->IsDown(sf::Keyboard::A)){
			m_velocity.x=-speed;
		}
		if(m_input->IsDown(sf::Keyboard::D)){
			m_velocity.x=speed;
		}
		if(m_input->IsDown(sf::Keyboard::W)){
			m_velocity.y=-speed;
		}
		if(m_input->IsDown(sf::Keyboard::S)){
			m_velocity.y=speed;
		}

		m_position += m_velocity*deltatime;
	}

	if(m_controltype == "Special"){
		/*Special Movement*/
		if(m_input->IsDown(sf::Keyboard::A)){
			m_velocity.x=-speed*((delta_y)/dist1);
			m_velocity.y=speed*((delta_x)/dist1);
			/*nothing happens with dist2, but dist1 gets affected by centripetal effects*/
		}
		if(m_input->IsDown(sf::Keyboard::D)){
			m_velocity.x=speed*((delta_y)/dist1);
			m_velocity.y=-speed*((delta_x)/dist1);
			/*same as previous*/
		}
		if(m_input->IsDown(sf::Keyboard::W)){
			m_velocity.x-=speed*((delta_x)/dist1);
			m_velocity.y-=speed*((delta_y)/dist1);
			dist2+=speed*deltatime;	//Here dist2 is increased, since we go further from the truck (dist1 is increased too)
		}
		if(m_input->IsDown(sf::Keyboard::S)){
			m_velocity.x+=speed*((delta_x)/dist1);
			m_velocity.y+=speed*((delta_y)/dist1);
			dist2-=speed*deltatime;	//Same as previous
		}
		/*END OF MOVEMENT INPUTS*/

		//We don't want the player to go inside a certain radius of the truck, therefore we limit its distance from it
		if(dist2<100){
			dist2=100;
		}


		m_position+=m_velocity*deltatime;	//Here the player gets its new position, but it might not be the right one if any centripetal effects has occurred or the player has gone too close to our base.

		delta_x = m_truck->GetPosition().x - m_position.x;	//x-difference between truck and player
		delta_y = m_truck->GetPosition().y - m_position.y;

		dist1 = sqrt((delta_x * delta_x) + (delta_y * delta_y));	//current distance from middle
		float offset = dist1-dist2;	//how much off it is from the distance from the middle that we want


		m_position.x+=(offset*delta_x)/dist1;	//adjusting x to be what we want
		m_position.y+=(offset*delta_y)/dist1;	//adjusting y to be what we want
	}

	if(m_controltype == "Viktor"){
		//VIKTOR STYLE
		if(m_input->IsDown(sf::Keyboard::A)){
			m_velocity.x=-speed*((delta_y)/dist1);
			m_velocity.y=speed*((delta_x)/dist1);
			//	nothing happens with dist2, but dist1 gets affected by centripetal effects
		}
		if(m_input->IsDown(sf::Keyboard::D)){
			m_velocity.x=speed*((delta_y)/dist1);
			m_velocity.y=-speed*((delta_x)/dist1);
			//	same as previous
		}

		//END OF MOVEMENT INPUTS

		//We don't want the player to go inside a certain radius of the truck, therefore we limit its distance from it
		if(dist2<100){
			dist2=100;
		}


		m_position+=m_velocity*deltatime;	//Here the player gets its new position, but it might not be the right one if any centripetal effects has occurred or the player has gone too close to our base.

		delta_x = m_truck->GetPosition().x - m_position.x;	//x-difference between truck and player
		delta_y = m_truck->GetPosition().y - m_position.y;  //y-difference between truck and player

		dist1 = sqrt((delta_x * delta_x) + (delta_y * delta_y));	//current distance from middle
		float offset = dist1-dist2;	//how much off it is from the distance from the middle that we want


		m_position.x+=(offset*delta_x)/dist1;	//adjusting x to be what we want
		m_position.y+=(offset*delta_y)/dist1;	//adjusting y to be what we want
	}

	//LIMITS
	if(m_position.x<0){
		m_position.x=0;
	}
	if(m_position.x>1280){
		m_position.x=1280;
	}
	if(m_position.y<0){
		m_position.y=0;
	}
	if(m_position.y>720){
		m_position.y=720;
	}

	m_sprite->setPosition(m_position);

	if(m_firetype == "Viktor"){
		//Viktor FireStyle
		float delta_X = m_truck->GetPosition().x-m_position.x;
		float delta_Y = m_truck->GetPosition().y-m_position.y;
		float dist3 = sqrt(delta_X*delta_X+delta_Y*delta_Y);

		const float pi = 3.141592654f;
		m_direction = sf::Vector2f(delta_Y/dist3, delta_X/dist3);
		m_sprite->setRotation((atan2(delta_Y/dist3, delta_X/dist3))*(180/pi));

		m_cooldown-=deltatime;
		if(!m_input->IsDown(sf::Keyboard::Space)) m_cooldown = 0;
		if(m_cooldown<0) m_cooldown=0;	//cooldown can't be less than 0
		if(m_input->IsDown(sf::Keyboard::Space) && m_cooldown==0){
			m_cooldown=m_attackspeed;
			//How long the cooldown is
			return true;	//if this is returned a bullet will be spawned
		}
	}
	if(m_firetype == "Mouse"){
		// MOUSE FIRE
		float delta_X = m_position.x-m_input->GetMousePos().x;
		float delta_Y = m_position.y-m_input->GetMousePos().y;
		float dist3 = sqrt(delta_X*delta_X+delta_Y*delta_Y);

		const float pi = 3.141592654f;
		m_direction = sf::Vector2f(delta_Y/dist3, delta_X/dist3);
		m_sprite->setRotation((atan2(delta_Y/dist3, delta_X/dist3))*(180/pi));

		//m_cooldown-=deltatime;		//reduces cooldown until you can fire again
		m_cooldown-=1;
		if(m_cooldown<0) m_cooldown=0;	//cooldown can't be less than 0

		if(m_weapontype != "ArmCannon"){
			if(m_input->Mouse_isDownOnce(sf::Mouse::Button::Left)/* && m_cooldown==0*/)
			{
				m_cooldown=1;	//How long the cooldown is
				return true;	//if this is returned a bullet will be spawned
			}
		}
		if(m_weapontype == "ArmCannon"){
			if(m_input->Mouse_isDown(sf::Mouse::Button::Left)/* && m_cooldown==0*/){
				m_cooldown=1;	//How long the cooldown is
				return true;	//if this is returned a bullet will be spawned
			}
		}
	}

	return false; //if this is returned nothing will happen
};

PlayerObject::~PlayerObject(){
	m_truck = nullptr;
	m_input = nullptr;
	m_sprite = nullptr;


};

bool PlayerObject::GetType()
{
	return true;
};


float PlayerObject::GetDamage()
{
	return m_damage;
};

sf::Vector2f PlayerObject::GetDirection()
{
	return m_direction;
}

void PlayerObject::SetSuitType(std::string p_suittype)
{
	m_suittype = p_suittype;
};

void PlayerObject::SetWeaponType(std::string p_weapontype)
{
	m_weapontype = p_weapontype;
};

void PlayerObject::SetTruckType(std::string p_trucktype)
{
	m_trucktype = p_trucktype;
};

std::string PlayerObject::GetWeaponType()
{
	return m_weapontype;
};

std::string PlayerObject::GetSuitType()
{
	return m_suittype;
};

std::string PlayerObject::GetTruckType()
{
	return m_trucktype;
};