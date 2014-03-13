//SniperGirl.cpp

#include "SniperGirl.h"
#include "Truck.h"

SniperGirl::SniperGirl(Truck* truck, sf::Sprite* sprite){
	
	m_damage = 9;
	m_truck=truck;
	m_sprite = sprite;
	m_cooldown = 1;
	speed = 50;
	m_hp = 7;

		//Animation

	m_animation = nullptr;
	AddAnimation(sprite);
	
	m_sprite->setOrigin(((m_sprite->getLocalBounds().width)/2.3), 16);
	m_animation->update(0.1f, 0);
};

bool SniperGirl::Update(float deltatime){

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

	if(dist<400)		
	{	
		m_velocity=m_truck->GetVelocity();//if within a certain radius of the truck it sticks to the truck(if the truck's gonna move in the future)
		m_animation->PausAnimation();
	}
	m_position+=m_velocity*deltatime;//gets new position from velocity
	m_sprite->setPosition(m_position);
	const float pi = 3.141592654f;
	m_sprite->setRotation((atan2(delta_y/dist, delta_x/dist))*(180/pi)+180);

	if(dist<400 && m_cooldown<0){ //within a certain radius of the truck and has no cooldown on firing
		m_cooldown = 3;	//gets cooldown
		return true;	//if this is returned a bullet will spawn
	}
	else return false;//doesn't matter if false is returned.
};

SniperGirl::~SniperGirl(){
	m_truck = nullptr;
	m_sprite = nullptr;
};

bool SniperGirl::GetType(){
	return true;
};

float SniperGirl::Damaged(float playerdmg){
	m_hp-=playerdmg;
	return m_hp;
};

float SniperGirl::GetDamage(){
	return m_damage;
};
void SniperGirl::AddAnimation(sf::Sprite *sprite)
{
	m_animation = new Animation(sprite, 0.2, false, true);
	m_animation->addFrame(sf::IntRect (0, 0, 82, 34));
	m_animation->addFrame(sf::IntRect (86, 0, 82, 34));

}