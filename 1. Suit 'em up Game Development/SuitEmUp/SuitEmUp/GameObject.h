// GameObject.h

#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "SpriteManager.h"


class GameObject : public sf::Transformable, public sf::Drawable
{
public:
	GameObject(){};
	virtual ~GameObject(){};

	sf::Sprite* GetSprite();
	sf::Vector2u &GetPosition();

	virtual bool Update() = 0; // SCARY
	virtual bool GetType() = 0; //SCARY AS HELL

	void SetPosition(float x_pos, float y_pos);
	bool HasSprite();

	float GetRadius();
	void SetRadius(float radius);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
	
	sf::Vector2u m_position;
	sf::Sprite* m_sprite;
	//sf::Vertex m_vertex;
	float m_radius;
};