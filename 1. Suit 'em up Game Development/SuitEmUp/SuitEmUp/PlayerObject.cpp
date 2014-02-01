//PlayerObject.cpp

#include "PlayerObject.h"
#include "Truck.h"

PlayerObject::PlayerObject(Truck* truck, sf::Sprite* sprite)
{
	m_truck = truck;
	m_sprite = sprite;
	m_cooldown = 0;
};

bool PlayerObject::Update(/*deltatime*/){
	const float speed=500.0f;	//Change this to adjust player speed

	m_position += m_truck->GetVelocity();	//Lets the player smoothly stick to the truck if we're going to implement truck movement

	float delta_x = m_truck->GetPosition().x - m_position.x;		//x-difference between truck and player
	float delta_y = m_truck->GetPosition().y - m_position.y;		//y-difference between truck and player

	float dist1 = sqrt((delta_x * delta_x) + (delta_y * delta_y));	//the actual distance between truck and player
	float dist2=dist1;	//The distance from the truck we want to have
						//This is soon used to maintain a certain distance from the truck when rotating around it, we don't want any centripetal effects.

	/*MOVEMENT INPUTS
	if(LOL){
		m_velocity.m_x=-speed*deltatime*((delta_y)/dist1);	
		m_velocity.m_y=speed*deltatime*((delta_x)/dist1);
		//nothing happens with dist2, but dist1 gets hit by centripetal effects
	}
	if(keyispressed d){
		m_velocity.m_x=speed*deltatime*((delta_y)/dist1);
		m_velocity.m_y=-speed*deltatime*((delta_x)/dist1);
		//same as previous
	}
	if(keyispressed w){
		m_velocity.m_x-=speed*deltatime*((delta_x)/dist1);
		m_velocity.m_y-=speed*deltatime*((delta_y)/dist1);
		distance2+=speed*deltatime;	//Here dist2 is increased, since we go further from the truck (dist1 is increased too)
	}
	if(keyispressed s){
		m_velocity.m_x+=speed*deltatime*((delta_x)/dist1);
		m_velocity.m_y+=speed*deltatime*((delta_y)/dist1);
		distance2-=speed*deltatime;	//Same as previous
	}
	/*END OF MOVEMENT INPUTS*/

	//We don't want the player to go inside a certain radius of the truck, therefore we limit its distance from it
	if(dist2<100){
		dist2=100;
	}

	
	m_position+=m_velocity;	//Here the player gets its new position, but it might not be the right one if any centripetal effects has occurred or the player has gone too close to our base.

	dist1 = sqrt((delta_x * delta_x) + (delta_y * delta_y));	//current distance from middle
	float offset = dist2-dist1;	//how much off it is from the distance from the middle that we want

	m_position.x+=(offset*delta_x)/dist1;	//adjusting x to be what we want
	m_position.y+=(offset*delta_y)/dist1;	//adjusting y to be what we want

	//m_cooldown-=deltatime;		//reduces cooldown until you can fire again
	if(m_cooldown<0) m_cooldown=0;	//cooldown can't be less than 0
	//if(keyispressed space && m_cooldown==0){
	//	m_cooldown=1;	//How long the cooldown is
	//	return true;	//if this is returned a bullet will be spawned
	//}
	return false; //if this is returned nothing will happen
};