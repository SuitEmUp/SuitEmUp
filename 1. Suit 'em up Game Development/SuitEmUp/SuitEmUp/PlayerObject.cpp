//PlayerObject.cpp

#include "PlayerObject.h"
#include "Truck.h"
#include "InputManager.h"
#include <iostream>

PlayerObject::PlayerObject(Truck* truck, InputManager* input, sf::Sprite* sprite)
{
	m_input = input;
	m_truck = truck;
	m_sprite = sprite;
	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);
	m_cooldown = 0;
	speed = 5;
	m_damage = 1;
};

bool PlayerObject::Update(/*deltatime*/){

	m_velocity = sf::Vector2f(0, 0);

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

	double delta_x = m_truck->GetPosition().x - m_position.x;		//x-difference between truck and player
	double delta_y = m_truck->GetPosition().y - m_position.y;		//y-difference between truck and player

	double dist1 = sqrt((delta_x * delta_x) + (delta_y * delta_y));	//the actual distance between truck and player
	double dist2=dist1;	//The distance from the truck we want to have
						//This is soon used to maintain a certain distance from the truck when rotating around it, we don't want any centripetal effects.
	
	/*MOVEMENT INPUTS*/

	if(m_input->IsDown(sf::Keyboard::A)){
		m_velocity.x=-speed*((delta_y)/dist1);
		m_velocity.y=speed*((delta_x)/dist1);
		//nothing happens with dist2, but dist1 gets affected by centripetal effects
	}
	if(m_input->IsDown(sf::Keyboard::D)){
		m_velocity.x=speed*((delta_y)/dist1);
		m_velocity.y=-speed*((delta_x)/dist1);
		//same as previous
	}
	if(m_input->IsDown(sf::Keyboard::W)){
		m_velocity.x-=speed*((delta_x)/dist1);
		m_velocity.y-=speed*((delta_y)/dist1);
		dist2+=speed;	//Here dist2 is increased, since we go further from the truck (dist1 is increased too)
	}
	if(m_input->IsDown(sf::Keyboard::S)){
		m_velocity.x+=speed*((delta_x)/dist1);
		m_velocity.y+=speed*((delta_y)/dist1);
		dist2-=speed;	//Same as previous
	}
	/*END OF MOVEMENT INPUTS*/

	//We don't want the player to go inside a certain radius of the truck, therefore we limit its distance from it
	if(dist2<100){
		dist2=100;
	}

	
	m_position+=m_velocity;	//Here the player gets its new position, but it might not be the right one if any centripetal effects has occurred or the player has gone too close to our base.

	delta_x = m_truck->GetPosition().x - m_position.x;	//x-difference between truck and player
	delta_y = m_truck->GetPosition().y - m_position.y;

	dist1 = sqrt((delta_x * delta_x) + (delta_y * delta_y));	//current distance from middle
	double offset = dist1-dist2;	//how much off it is from the distance from the middle that we want


	m_position.x+=(offset*delta_x)/dist1;	//adjusting x to be what we want
	m_position.y+=(offset*delta_y)/dist1;	//adjusting y to be what we want


	//std::cout << "offset:" << offset << "  dist1:" << dist1 << "  dist2:" << dist2 << std::endl;
	

	m_sprite->setPosition(m_position);

	float delta_X = m_position.x-m_input->GetMousePos().x;
	float delta_Y = m_position.y-m_input->GetMousePos().y;
	float dist3 = sqrt(delta_X*delta_X+delta_Y*delta_Y);
	
	const float pi = 3.141592654f;
	m_direction = sf::Vector2f(delta_Y/dist3, delta_X/dist3);
	m_sprite->setRotation((atan2(delta_Y/dist3, delta_X/dist3))*(180/pi));

	//m_cooldown-=deltatime;		//reduces cooldown until you can fire again
	m_cooldown-=1;
	if(m_cooldown<0) m_cooldown=0;	//cooldown can't be less than 0
	if(m_input->Mouse_isDownOnce(sf::Mouse::Button::Left) && m_cooldown==0){
		m_cooldown=1;	//How long the cooldown is
		return true;	//if this is returned a bullet will be spawned
	}
	return false; //if this is returned nothing will happen
};


bool PlayerObject::GetType(){
	return true;
};

int PlayerObject::GetDamage(){
	return m_damage;
};

sf::Vector2f PlayerObject::GetDirection(){
	return m_direction;
}