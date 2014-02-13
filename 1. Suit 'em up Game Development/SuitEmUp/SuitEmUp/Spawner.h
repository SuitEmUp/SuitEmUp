// Spawner.h

#pragma once;

#include "EnemyObject.h"
#include "EnemyProjectile.h"
#include "PlayerProjectile.h"

class SpriteManager;
class Truck;
class PlayerProjectile;

class Spawner{
public:
	Spawner(Truck* truck);
	bool Timer(float deltatime);

	EnemyObject* EnemySpawner(SpriteManager* sm);
	bool EnemyDestroyer(EnemyObject* enemy, PlayerProjectile* bullet);

private:
	float m_time;
	float m_alarm;

	Truck* m_truck;
};