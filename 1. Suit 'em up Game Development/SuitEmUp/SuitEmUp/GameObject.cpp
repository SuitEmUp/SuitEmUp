//GameObject.cpp

#include "GameObject.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>




sf::Sprite* GameObject::GetSprite()
{
	return m_sprite;
};

sf::Vector2u &GameObject::GetPosition()
{
	return m_position;
};

void GameObject::SetPosition(float x_pos, float y_pos)
{
	m_position = sf::Vector2u(x_pos,  y_pos);
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
void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= sf::Transformable::getTransform();
	target.draw(*m_sprite, states);
}