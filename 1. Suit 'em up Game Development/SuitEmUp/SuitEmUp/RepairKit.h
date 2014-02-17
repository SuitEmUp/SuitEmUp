//Repairkit.h

#pragma once

#include "MovingGameObject.h"

class PlayerObject;
class Truck;

class RepairKit : public MovingGameObject{
public:
	RepairKit(sf::Vector2f p_position, sf::Vector2f p_velocity, sf::Sprite* p_sprite);
	bool Update(Truck* p_truck, PlayerObject* p_player, float deltatime);
	bool GetType();
};