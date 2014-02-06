//Projectile.cpp

#include "Projectile.h"
#include "Truck.h"

bool Projectile::Update(/*deltatime*/){
	m_position += m_velocity;
	m_sprite->setPosition(m_position);
	//if(m_truck->GetPosition()==10415 || || ||) return true;
	return false;
};

bool Projectile::GetType(){
	return true;
};