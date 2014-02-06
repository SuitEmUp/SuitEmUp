// Spawner.h

#pragma once;

#include "EnemyObject.h"
#include "EnemyProjectile.h"
#include "PlayerProjectile.h"

class SpriteManager;
class Truck;

class Spawner{
public:
	Spawner(Truck* truck);
	bool Timer(/*deltatime*/);

	EnemyObject* EnemySpawner(SpriteManager* sm);

private:
	float m_time;
	float m_alarm;

	Truck* m_truck;
};