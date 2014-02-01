//Projectile.cpp

#include "Projectile.h"
#include "Truck.h"

bool Projectile::Update(/*deltatime*/){
	m_position += m_velocity;
	//if(m_truck->GetPosition()==10415 || || ||) return true;
	return false;
};