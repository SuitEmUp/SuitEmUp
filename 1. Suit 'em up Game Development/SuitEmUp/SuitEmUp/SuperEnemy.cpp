//SuperEnemy.cpp

#include "SuperEnemy.h"
#include "Truck.h"

SuperEnemy::SuperEnemy(Truck* truck, sf::Sprite* sprite){
	m_damage = 4;
	m_truck=truck;
	m_sprite = sprite;
	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);
	m_cooldown = 1;
	speed = 210;
	m_hp = 4;

	//animation
	m_animation = nullptr;

	AddAnimation(sprite);

	m_sprite->setOrigin(50/2, 40/2);

	for(int i=0;i<3;i++)
	{
		m_animation->update(0.1f, 0);
	}
};

bool SuperEnemy::Update(float deltatime){

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

	if(dist<120)
	{	
		m_velocity=m_truck->GetVelocity();//if within a certain radius of the truck it sticks to the truck(if the truck's gonna move in the future)
		m_animation->PausAnimation();
	}
	m_position+=m_velocity*deltatime;//gets new position from velocity
	m_sprite->setPosition(m_position);
	const float pi = 3.141592654f;
	rotation = (atan2(delta_y/dist, delta_x/dist))*(180/pi)+180;
	m_sprite->setRotation(rotation);

	if(dist<120 && m_cooldown<0){ //within a certain radius of the truck and has no cooldown on firing
		m_animation->PausAnimation();
		m_cooldown = 1;	//gets cooldown
		return true;	//if this is returned a bullet will spawn
	}
	else return false;//doesn't matter if false is returned.
};

SuperEnemy::~SuperEnemy()
{
	m_sprite = nullptr;
	m_truck = nullptr;
	delete m_animation;
	m_animation = nullptr;
};

bool SuperEnemy::GetType(){
	return true;
};

float SuperEnemy::Damaged(float playerdmg){
	m_hp-=playerdmg;
	return m_hp;
};

float SuperEnemy::GetDamage(){
	return m_damage;
};

float SuperEnemy::GetRotation(){
	return rotation;
};

void SuperEnemy::AddAnimation(sf::Sprite *sprite)
{
	m_animation = new Animation(sprite, 0.2, false, true);
	m_animation->addFrame(sf::IntRect (8, 22, 50, 40));
	m_animation->addFrame(sf::IntRect (73, 19, 50, 40));


}