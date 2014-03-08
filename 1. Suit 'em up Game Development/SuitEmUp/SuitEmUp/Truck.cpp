//Truck.cpp

#include "Truck.h"
#include "EnemyProjectile.h"

Truck::Truck(sf::Sprite* sprite, sf::Sprite* sprite2,sf::Sprite* sprite3,sf::Sprite* sprite4)
{
	sprite_truck.push_back(sprite);
	sprite_truck.push_back(sprite2);
	sprite_truck.push_back(sprite3);
	sprite_truck.push_back(sprite4);

	m_sprite = sprite_truck.at(0);
	
	m_maxhp = 100;
	m_hp = 100;

	m_truck_hp  = nullptr;
	//m_truck_lowhp = nullptr;
	
	m_position=sf::Vector2f(1280/2, 720/2);

	//Animation

	//Set_Animation(sprite_truck.at(0), 2);
	Set_Animation(sprite_truck.at(0), 1);
	
	
	//initialize
	for(int i=0; i<sprite_truck.size();i++)
	{
	sprite_truck.at(i)->setOrigin(136.0f/2.0f, 52.0f/2.0f);
	sprite_truck.at(i)->setPosition(m_position);
	}

	//m_truck_lowhp->update(0.1f, 0);
	m_truck_hp->update(0.1f, 1);

};

bool Truck::Update(float deltatime)
{
	m_sprite->setPosition(m_position);

	m_truck_hp->update(deltatime, 1);

	//if(m_hp >75){m_sprite = m_unupdate;}

	//else 
	//{
	//	m_unupdate = m_update;	
	//	m_sprite = m_unupdate;
	//}

	if(m_hp>m_maxhp){m_hp=m_maxhp;}

	if(m_hp > 75)
	{
		m_sprite = m_truck_hp->getCurrentFrame(1);
	}
	if(m_hp < 75)
	{	
		m_sprite = sprite_truck.at(1);
	}
	if(m_hp < 50)
	{
		m_sprite = sprite_truck.at(2);
	}
	if(m_hp < 25)
	{
		m_sprite = sprite_truck.at(3);
	}

	if(m_hp<1) return true;
	return false;

};
float Truck::UpdateHP()
{
	return m_hp;
}

sf::Vector2f Truck::GetVelocity()
{
	return m_velocity;
};

void Truck::SetVelocity(sf::Vector2f vel)
{
	m_velocity=vel;
};

bool Truck::GetType(){
	return true;
};

void Truck::Damaged(float damage)
{
	m_hp-= damage;
}

void Truck::Healed()
{
	m_hp+=100;
}
void Truck::Set_Animation(sf::Sprite *m_xsprite, int sprite_number)
{
	//Animation
	if(sprite_number == 1)
	{
		m_truck_hp = new Animation(m_xsprite, 0.2, false, true);
		m_truck_hp->setSpriteSheet(m_xsprite);
		m_truck_hp->addFrame(sf::IntRect (0, 0, 135, 51));
		m_truck_hp->addFrame(sf::IntRect (144, 0, 135, 51));
		m_truck_hp->addFrame(sf::IntRect (285, 0, 135, 51));
	}

	/*if(sprite_number == 2)
	{
		m_truck_lowhp = new Animation(m_xsprite, 0.2, false, true);
		m_truck_lowhp->addFrame(sf::IntRect (0, 0, 142, 54));
		m_truck_lowhp->addFrame(sf::IntRect (151, 0, 142, 54));
		m_truck_lowhp->addFrame(sf::IntRect (299, 0, 142, 54));
		m_truck_lowhp->setSpriteSheet(m_xsprite);
	}*/
}

