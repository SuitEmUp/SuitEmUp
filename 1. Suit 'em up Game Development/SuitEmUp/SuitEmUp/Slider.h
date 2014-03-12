#pragma once

#include "gameobject.h"

class InputManager;
class SpriteManager;

class Slider :
	public GameObject
{
public:
	Slider(SpriteManager* p_sm);
	~Slider();
	void Update(InputManager* p_input);
	float GetLevel();

private:
	float m_slider_length;
	sf::Sprite* m_slider;
	sf::Vector2f m_sliderposition;
	float m_level;
	bool m_grabbed;
};

