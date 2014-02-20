//EnemyProjectile.cpp

#include "EnemyProjectile.h"
#include "Truck.h"
#include "EnemyObject.h"

EnemyProjectile::EnemyProjectile(float damage, Truck* truck, sf::Vector2f start, sf::Sprite* sprite){
	speed = 2000; //Adjust bullet speed

	m_damage = damage;
	
	m_sprite=sprite;
	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);

	m_position=start;

	float delta_x=(m_position.x)-(truck->GetPosition().x);	//x difference between player and base
	float delta_y=(m_position.y)-(truck->GetPosition().y);	//y difference between player and base
	
	float dist = sqrt(delta_x*delta_x + delta_y*delta_y); //distance between player and base

	m_velocity.x=-(speed*delta_x)/dist;	//sets velocity in an outgoing line between player and base
	m_velocity.y=-(speed*delta_y)/dist;   //
	const float pi = 3.141592654f;
	m_sprite->setRotation((atan2(delta_y/dist, delta_x/dist))*(180/pi));
};

bool EnemyProjectile::Update(Truck* truck, float deltatime){
	m_position += m_velocity*deltatime;
	m_sprite->setPosition(m_position);
	float delta_x=truck->GetPosition().x-m_position.x;
	float delta_y=truck->GetPosition().y-m_position.y;
	float dist = sqrt((delta_x*delta_x)+(delta_y*delta_y));
	if(dist>1000) return true;
	else if(dist<50){
		truck->Damaged(m_damage);
		return true;
	}
	return false;
}

float EnemyProjectile::GetDamage(){
	return m_damage;
};