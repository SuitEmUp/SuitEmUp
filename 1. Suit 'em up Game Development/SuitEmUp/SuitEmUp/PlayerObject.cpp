

#include "PlayerObject.h"

PlayerObject::PlayerObject(sf::Vector2u* truck, sf::Sprite* sprite)
{
	//m_middle = Truck->GetPosition();
	m_sprite = sprite;
	m_cooldown = 0;
};

bool PlayerObject::Update(/*deltatime*/){
	/*const float speed=500.0f;

	m_position += m_truck->GetVelocity();

	float delta_x = m_truck->GetPosition().m_x - m_position.m_x;
	float delta_y = m_truck->GetPosition().m_y - m_position.m_y;

	Vector2u dist1 = Vector2u(delta_x, delta_y).Length;

	float dist2=dist1;

	if(keyispressed a){
		m_velocity.m_x=-speed*deltatime*((delta_y)/dist1);
		m_velocity.m_y=speed*deltatime*((delta_x)/dist1);
	}
	if(keyispressed d){
		m_velocity.m_x=speed*deltatime*((delta_y)/dist1);
		m_velocity.m_y=-speed*deltatime*((delta_x)/dist1);
	}
	if(keyispressed w){
		m_velocity.m_x-=speed*deltatime*((delta_x)/dist1);
		m_velocity.m_y-=speed*deltatime*((delta_y)/dist1);
		distance2+=speed*deltatime;
	}
	if(keyispressed s){
		m_velocity.m_x+=speed*deltatime*((delta_x)/dist1);
		m_velocity.m_y+=speed*deltatime*((delta_y)/dist1);
		distance2-=speed*deltatime;
	}

	if(dist2<100){
		dist2=100;
	}

	m_position+=m_velocity;

	distance1 = Vector2u(delta_x, delta_y).Length;
	float offset = dist2-dist1;

	m_position.m_x+=(offset*delta_x)/distance1;
	m_position.m_y+=(offset*delta_y)/distance1;

	cooldown-=deltatime;
	if(cooldown<0) cooldown=0;
	if(keyispressed space && cooldown==0){
		return true;
	}*/

	//nope
	return true;
};