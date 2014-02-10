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
	sf::Vector2f &GetPosition();

	//virtual bool Update(); // SCARY
	virtual bool GetType()=0; //SCARY AS HELL

	void SetPosition(float x_pos, float y_pos);
	bool HasSprite();

	float GetRadius();
	void SetRadius(float radius);

protected:
	sf::Vector2f m_position;
	sf::Sprite* m_sprite;
	float m_radius;
};