//HpBar.h

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Truck.h"


class HpBar : public GameObject
{
	friend class Truck;
public:
	HpBar(sf::Sprite *hpbar = nullptr, sf::Sprite *hpsprite = nullptr, sf::Sprite *hpshadow = nullptr);
	~HpBar();
	bool GetType();
	sf::Sprite *Sprite2();
	sf::Sprite *Sprite3();
protected:
	sf::Sprite *hp;
	sf::Sprite *shadow;
	
};