//PlayerProjectile.cpp

#include "PlayerProjectile.h"
#include "PlayerObject.h"
#include "Truck.h"
#include "InputManager.h"

PlayerProjectile::PlayerProjectile(Truck* truck, PlayerObject* player, sf::Sprite* sprite){
	speed = 2000;

	m_position = player->GetPosition();

	m_sprite = sprite;
	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);

	//x difference between player and base
	//y difference between player and base
	
	//distance between player and base

	m_velocity.x-=speed*player->GetDirection().y;	//sets velocity in an outgoing line between player and base
	m_velocity.y-=speed*player->GetDirection().x;   //
	
	const float pi = 3.141592654f;
	m_sprite->setRotation((atan2(player->GetDirection().x, player->GetDirection().y))*(180/pi));
};