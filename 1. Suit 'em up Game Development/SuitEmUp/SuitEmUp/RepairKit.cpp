//RepairKit.cpp

#include "RepairKit.h"
#include "Truck.h"
#include "PlayerObject.h"

RepairKit::RepairKit(sf::Vector2f p_position, sf::Vector2f p_velocity, sf::Sprite* p_sprite){
	m_position = p_position;
	m_sprite = p_sprite;
	m_radius = 50;
	speed = 100;
	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);
};

bool RepairKit::Update(Truck* p_truck, PlayerObject* p_player, float deltatime){
	
	float delta_x = p_truck->GetPosition().x - m_position.x;
	float delta_y = p_truck->GetPosition().y - m_position.y;

	float dist1 = sqrt(delta_x*delta_x + delta_y*delta_y);

	m_velocity.x = speed*delta_x/dist1;
	m_velocity.y = speed*delta_y/dist1;

	/*m_position += m_velocity*deltatime;*/

	m_sprite->setPosition(m_position);

	float delta_X = p_player->GetPosition().x - m_position.x;
	float delta_Y = p_player->GetPosition().y - m_position.y;

	float dist = sqrt(delta_X*delta_X + delta_Y*delta_Y);

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