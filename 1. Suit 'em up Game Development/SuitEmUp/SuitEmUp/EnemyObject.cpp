//EnemyObject.cpp

#include "EnemyObject.h"
#include "Truck.h"

EnemyObject::EnemyObject(Truck* truck, sf::Sprite* sprite){
	m_truck=truck;
	m_sprite = sprite;
	m_cooldown = 0;
};

bool EnemyObject::Update(/*deltatime*/){
	const float speed = 300;	//Adjust this to make enemy move faster

	/*Calculations for where to move*/
	float delta_x=m_truck->GetPosition().x-m_position.x;
	float delta_y=m_truck->GetPosition().y-m_position.y;
	
	float dist = sqrt(delta_x*delta_x + delta_y*delta_y);
	/*End of them*/

	/*Movement towards base*/
	//m_velocity.x = speed*deltatime*delta_x/dist;
	//m_velocity.y = speed*deltatime*delta_y/dist;
	/*End of movement*/

	//m_cooldown-=deltatime;	//cooldown goes down
	//if(cooldown<0) cooldown=0;//cooldown can't go below 0

	dist = sqrt(delta_x*delta_x + delta_y*delta_y);

	if(dist<m_truck->GetRadius())	m_velocity=m_truck->GetVelocity();//if within a certain radius of the truck it sticks to the truck(if the truck's gonna move in the future)
		
	m_position+=m_velocity;//gets new position from velocity

	if(dist<m_truck->GetRadius() && m_cooldown==0){ //within a certain radius of the truck and has no cooldown on firing
		m_cooldown = 1;	//gets cooldown
		return true;	//if this is returned a bullet will spawn
	}
	else return false;//doesn't matter if false is returned.
};