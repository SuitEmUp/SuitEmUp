//EnemyProjectile.cpp

#include "EnemyProjectile.h"
#include "Truck.h"

EnemyProjectile::EnemyProjectile(Truck* truck, sf::Sprite* sprite){
	const float Speed = 1000; //Adjust bullet speed
	
	float delta_x=(m_position.x)-(truck->GetPosition().x);	//x difference between player and base
	float delta_y=(m_position.y)-(truck->GetPosition().y);	//y difference between player and base
	
	float dist = sqrt(delta_x*delta_x + delta_y*delta_y); //distance between player and base

	//m_velocity.x=(speed*deltatime*delta_x)/dist;	//sets velocity in an outgoing line between player and base
	//m_velocity.y=(speed*deltatime*delta_y)/dist;   //
};