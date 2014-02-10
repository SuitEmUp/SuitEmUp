//PlayerProjectile.cpp

#include "PlayerProjectile.h"
#include "PlayerObject.h"
#include "Truck.h"

PlayerProjectile::PlayerProjectile(Truck* truck, PlayerObject* player, sf::Sprite* sprite){
	const float speed = 15; //Adjust bullet speed
	
	m_position = player->GetPosition();

	m_sprite = sprite;
	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);

	float delta_x=player->GetPosition().x-truck->GetPosition().x;	//x difference between player and base
	float delta_y=player->GetPosition().y-truck->GetPosition().y;	//y difference between player and base
	
	float dist = sqrt(delta_x*delta_x + delta_y*delta_y); //distance between player and base

	m_velocity.x=(speed*delta_x)/dist;	//sets velocity in an outgoing line between player and base
	m_velocity.y=(speed*delta_y)/dist;   //
	
	const float pi = 3.141592654f;
	m_sprite->setRotation((atan2(delta_y/dist, delta_x/dist))*(180/pi)+180);
};