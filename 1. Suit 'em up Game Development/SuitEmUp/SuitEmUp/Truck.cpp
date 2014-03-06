//Truck.cpp

#include "Truck.h"
#include "EnemyProjectile.h"

Truck::Truck(sf::Sprite* sprite, sf::Sprite* sprite2)
{
	m_update = sprite2;
	m_unupdate = sprite;
	m_sprite = m_unupdate;
	m_maxhp = 100;
	m_hp = 100;
	m_position=sf::Vector2f(1280/2, 720/2);

	//Animation
	m_truck = new Animation(sprite, 0.1, false, true);
	m_truck->addFrame(sf::IntRect (3, 10, 136, 52));
	m_truck->addFrame(sf::IntRect (144, 10, 136, 52));
	m_truck->addFrame(sf::IntRect (285, 10, 136, 52));

	sprite->setOrigin(136.0f/2.0f, 52.0f/2.0f);
	sprite2->setOrigin(136.0f/2.0f, 52.0f/2.0f);
};

bool Truck::Update(float deltatime)
{
	m_truck->update(deltatime);

	m_sprite = m_truck->getCurrentFrame();
	m_sprite->setPosition(m_position);

	if(m_hp>100){m_hp=100;}

	if(m_hp >75){m_sprite = m_unupdate;}

	else 
	{
		m_unupdate = m_update;	
		m_sprite = m_unupdate;
	}


	if(m_hp>m_maxhp){m_hp=m_maxhp;}
	if(m_hp >75){m_sprite = m_update;}
	else m_sprite = m_unupdate;
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
/*AnimatedSprite Truck::GetAnimation(sf::Texture t_truck)
{

}*/
