//EnemyObject.cpp

#include "EnemyObject.h"
#include "Truck.h"
#include "SpriteManager.h"
#include <iostream>

EnemyObject::EnemyObject(Truck* truck, SpriteManager* sm){
	m_damage = 2;
	m_truck=truck;
	m_sprite = sm->Load("../data/sprites/Spritesheet_enemy_1_2.png", "Bandit1", 1, 1);
	m_cooldown = 0;
	speed = 150;
	m_hp = 2;

	m_shooting = sm->Load("../data/sprites/BanditEnblack.png", "Banditshootidle1", 1, 1);
	m_shooting->setOrigin(m_shooting->getLocalBounds().width/2, m_shooting->getLocalBounds().height/2);
	m_shooting;

	//Animation

	m_animation = nullptr;
	AddAnimation(m_sprite);
	
	m_sprite->setOrigin(29/2, 35/2);

	for(int i=0;i<3;i++)
	{
		m_animation->update(0.1f, 0);
	}
};

bool EnemyObject::Update(float deltatime){
	//animation
	m_animation->update(deltatime, 0);
	/*Calculations for where to move*/
	float delta_x=m_truck->GetPosition().x-m_position.x;
	float delta_y=m_truck->GetPosition().y-m_position.y;
	
	float dist = sqrt(delta_x*delta_x + delta_y*delta_y);
	/*End of them*/

	/*Movement towards base*/
	m_velocity.x = speed*delta_x/dist;
	m_velocity.y = speed*delta_y/dist;
	/*End of movement*/

	m_cooldown-=0.02f;	//cooldown goes down
	delta_x=m_truck->GetPosition().x-m_position.x;
	delta_y=m_truck->GetPosition().y-m_position.y;

	dist = sqrt(delta_x*delta_x + delta_y*delta_y);

	if(dist<200)
	{	
		m_velocity=m_truck->GetVelocity();//if within a certain radius of the truck it sticks to the truck(if the truck's gonna move in the future)
		m_animation->PausAnimation();
		m_sprite = m_shooting;
		
	}
	m_position+=m_velocity*deltatime;//gets new position from velocity
	m_sprite->setPosition(m_position);
	const float pi = 3.141592654f;
	m_sprite->setRotation((atan2(delta_y/dist, delta_x/dist))*(180/pi)+180);

	if(dist<200 && m_cooldown<0){ //within a certain radius of the truck and has no cooldown on firing
		m_cooldown = 1.f;	//gets cooldown
		return true;	//if this is returned a bullet will spawn
	}
	else return false;//doesn't matter if false is returned.
};

EnemyObject::~EnemyObject()
{
	m_truck = nullptr;
	m_sprite = nullptr;
	delete m_animation;
	m_animation = nullptr;
	m_shooting = nullptr;
};

bool EnemyObject::GetType(){
	return true;
};

float EnemyObject::Damaged(float playerdmg){
	m_hp-=playerdmg;
	return m_hp;
}

float EnemyObject::GetDamage(){
	return m_damage;
};
void EnemyObject::AddAnimation(sf::Sprite *sprite)
{
	m_animation = new Animation(sprite, 0.2, false, true);
	m_animation->addFrame(sf::IntRect (32, 80, 29, 35));
	m_animation->addFrame(sf::IntRect (95, 78, 29, 35));

}

