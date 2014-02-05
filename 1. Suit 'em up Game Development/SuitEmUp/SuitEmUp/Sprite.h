#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include <string>

class Sprite : sf::Sprite
{
public:
	Sprite(sf::Sprite, float x_scale = 1.0, float y_scale = 1.0);

	virtual void Update(float deltatime){};

protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};