//HpBar.h

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Truck.h"


class HpBar : public GameObject
{
	friend class Truck;
public:
	HpBar(sf::Sprite *hpbar = nullptr, sf::Sprite *hpsprite = nullptr);
	~HpBar();
	bool GetType();
	sf::Sprite *Sprite2();
protected:
	sf::Sprite *hp;
	
};