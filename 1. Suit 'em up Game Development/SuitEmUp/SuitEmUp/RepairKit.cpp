//RepairKit.cpp

#include "RepairKit.h"
#include "Truck.h"
#include "PlayerObject.h"

RepairKit::RepairKit(sf::Vector2f p_position, sf::Vector2f p_velocity, sf::Sprite* p_sprite){
	m_position = p_position;
	m_sprite = p_sprite;
	m_radius = 50;
	speed = 100;
	m_sprite->setOrigin(64/2, 64/2);
};

bool RepairKit::Update(PlayerObject* p_player, float deltatime){

	float delta_x = p_player->GetPosition().x - m_position.x;
	float delta_y = p_player->GetPosition().y - m_position.y;

	float dist = sqrt(delta_x*delta_x + delta_y*delta_y);

	if(dist < m_radius*4){

		m_velocity.x += speed*delta_x/(2*dist);
		m_velocity.y += speed*delta_y/(2*dist);

		if(m_velocity.x>0 && delta_x<0){
			m_velocity.x *= 0.9;
		}
		if(m_velocity.x<0 && delta_x>0){
			m_velocity.x *= 0.9;
		}
		if(m_velocity.y>0 && delta_y<0){
			m_velocity.y *= 0.9;
		}
		if(m_velocity.y<0 && delta_y>0){
			m_velocity.y*= 0.9;
		}

		m_position += m_velocity*deltatime;
	}
	else m_velocity = sf::Vector2f(0,0);
	m_sprite->setPosition(m_position);
	if(dist < m_radius){
		return true;
	}
	return false;
};

bool RepairKit::GetType()
{
	return true;
};

RepairKit::~RepairKit(){
	m_sprite = nullptr;
}