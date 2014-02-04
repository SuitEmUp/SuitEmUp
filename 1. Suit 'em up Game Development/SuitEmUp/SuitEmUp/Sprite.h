#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include <string>

class Sprite : sf::Sprite
{
public:
	Sprite();

	void CreateSprite(std::string filename, int x, int y, int width, int height);

	virtual void Update(float deltatime){};

protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};