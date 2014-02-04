// Collider.h

#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class GameObject;

class Collider 
{
public:
	Collider();
	Collider(const sf::Vector2u &p_position, const sf::Vector2u &p_exstension);
	~Collider();

	bool Overlap(const Collider &p_other, sf::Vector2u &p_offset);
	void NotifyParent(GameObject* go1);

	GameObject *m_xobject; //min collider en pekare till ett gameobject
	sf::Vector2u m_position;
	sf::Vector2u m_extension;
private:


};