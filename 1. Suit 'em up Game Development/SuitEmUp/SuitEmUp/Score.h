//Score.h

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "GameObject.h"
#include "GameObjectManager.h"

class PlayerObject;

class Score : public GameObject
{
	friend class GameObjectManager;
public:
	
	Score(sf::Sprite *m_Score, sf::Text *score);

private:
	Truck *m_truck;
	PlayerObject *m_player;
};