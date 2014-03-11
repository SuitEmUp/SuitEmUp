//PlayerProjectile.cpp

#include "PlayerProjectile.h"
#include "PlayerObject.h"
#include "Truck.h"
#include "InputManager.h"

PlayerProjectile::PlayerProjectile(Truck* truck, PlayerObject* player, sf::Sprite* sprite, sf::Sprite* update, sf::Sprite* updatedupdate){
	
	if(player->GetWeaponType() == "ArmCannon"){
	speed = 20;
	}

	else{speed = 2000;}

	m_position = player->GetPosition();

	m_updatedupdate = updatedupdate;
	m_unupdate = sprite;
	m_update = update;
	if(player->GetWeaponType() == "ArmCannon"){
		m_sprite = m_updatedupdate;
		m_sprite->setOrigin(64/2, 64/2);
		m_sprite->setColor(sf::Color(0, 0, 0, 0xff));
		
	}

	else if(player->GetWeaponType() == "Needlegun"){
		m_sprite = m_update;
		type = "Needle";
		//m_sprite->setScale((player->GetDamage()-80)/20, (player->GetDamage()-80)/100);
	}
	else{
		m_sprite = m_unupdate;
		//	m_sprite->setScale(player->GetDamage()/20, player->GetDamage()/20);
		//	m_sprite->setScale((player->GetDamage()-80)/20, (player->GetDamage()-80)/100);
	}


	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);

	//x difference between player and base
	//y difference between player and base

	//distance between player and base

	m_velocity.x-=speed*player->GetDirection().y;	//sets velocity in an outgoing line between player and base
	m_velocity.y-=speed*player->GetDirection().x;   //

	const float pi = 3.141592654f;
	m_rotation = (atan2(player->GetDirection().x, player->GetDirection().y))*(180/pi);
	m_sprite->setRotation(m_rotation);
};