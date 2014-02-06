//Projectile.cpp

#include "Projectile.h"
#include "Truck.h"

bool Projectile::Update(/*deltatime*/Truck* truck){
	m_position += m_velocity;
	m_sprite->setPosition(m_position);
	float delta_x=truck->GetPosition().x-m_position.x;
	float delta_y=truck->GetPosition().y-m_position.y;
	float dist = sqrt((delta_x*delta_x)+(delta_y*delta_y));
	if(dist>1000 || dist<50) return true;
	return false;
};

bool Projectile::GetType(){
	return true;
};