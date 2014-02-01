// GameObject.h

#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "SpriteManager.h"

class GameObject{
public:
	GameObject(){};
	virtual ~GameObject(){};

	sf::Sprite* GetSprite();
	sf::Vector2u &GetPosition();

	void SetPosition(float x_pos, float y_pos);
	bool HasSprite();

	float GetRadius();
	void SetRadius(float radius);

protected:
	sf::Vector2u m_position;
	sf::Sprite* m_sprite;
	float m_radius;
};