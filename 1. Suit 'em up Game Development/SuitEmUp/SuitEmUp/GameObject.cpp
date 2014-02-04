#include "GameObject.h"

sf::Sprite* GameObject::GetSprite()
{
	return m_sprite;
};

sf::Vector2f &GameObject::GetPosition()
{
	return m_position;
};

void GameObject::SetPosition(float x_pos, float y_pos)
{
	m_position = sf::Vector2f(x_pos,  y_pos);
};

bool GameObject::HasSprite()
{
	if(m_sprite!=nullptr){
		return true;
	}
	else return false;
};

float GameObject::GetRadius()
{
	return m_radius;
};

void GameObject::SetRadius(float radius)
{
	m_radius = radius;
};