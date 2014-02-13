//PlayerProjectile.cpp

#include "PlayerProjectile.h"
#include "PlayerObject.h"
#include "Truck.h"
#include "InputManager.h"

PlayerProjectile::PlayerProjectile(Truck* truck, PlayerObject* player, sf::Sprite* sprite, sf::Sprite* update){
	speed = 2000;

	m_position = player->GetPosition();

	m_unupdate = sprite;
	m_update = update;
	
	if(player->GetDamage()>=100){
		m_sprite = m_update;
		m_sprite->setScale((player->GetDamage()-80)/20, (player->GetDamage()-80)/100);
	}
	else{
		m_sprite = m_unupdate;
		m_sprite->setScale(player->GetDamage()/20, player->GetDamage()/20);
	}


	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);

	//x difference between player and base
	//y difference between player and base
	
	//distance between player and base

	m_velocity.x-=speed*player->GetDirection().y;	//sets velocity in an outgoing line between player and base
	m_velocity.y-=speed*player->GetDirection().x;   //
	
	const float pi = 3.141592654f;
	m_sprite->setRotation((atan2(player->GetDirection().x, player->GetDirection().y))*(180/pi));
};