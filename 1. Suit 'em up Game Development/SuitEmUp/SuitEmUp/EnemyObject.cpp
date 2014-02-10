//EnemyObject.cpp

#include "EnemyObject.h"
#include "Truck.h"
#include <iostream>

EnemyObject::EnemyObject(Truck* truck, sf::Sprite* sprite){
	m_truck=truck;
	m_sprite = sprite;
	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);
	m_cooldown = 0;
};

bool EnemyObject::Update(/*deltatime*/){
	const float speed = 5;	//Adjust this to make enemy move faster

	/*Calculations for where to move*/
	float delta_x=m_truck->GetPosition().x-m_position.x;
	float delta_y=m_truck->GetPosition().y-m_position.y;
	
	float dist = sqrt(delta_x*delta_x + delta_y*delta_y);
	/*End of them*/

	/*Movement towards base*/
	m_velocity.x = speed*delta_x/dist;
	m_velocity.y = speed*delta_y/dist;
	/*End of movement*/

	m_cooldown-=0.02;	//cooldown goes down
	delta_x=m_truck->GetPosition().x-m_position.x;
	delta_y=m_truck->GetPosition().y-m_position.y;

	dist = sqrt(delta_x*delta_x + delta_y*delta_y);

	if(dist<200)	m_velocity=m_truck->GetVelocity();//if within a certain radius of the truck it sticks to the truck(if the truck's gonna move in the future)
		
	m_position+=m_velocity;//gets new position from velocity
	m_sprite->setPosition(m_position);
	const float pi = 3.141592654f;
	m_sprite->setRotation((atan2(delta_y/dist, delta_x/dist))*(180/pi));

	if(dist<200 && m_cooldown<0){ //within a certain radius of the truck and has no cooldown on firing
		m_cooldown = 1;	//gets cooldown
		return true;	//if this is returned a bullet will spawn
	}
	else return false;//doesn't matter if false is returned.
};

bool EnemyObject::GetType(){
	return true;
};