// Spawner.h

#pragma once;

#include "EnemyObject.h"
#include "EnemyProjectile.h"
#include "PlayerProjectile.h"

class Truck;

class Spawner{
public:
	Spawner(Truck* truck);
	bool Timer(/*deltatime*/);

	EnemyObject* EnemySpawner();
	EnemyProjectile* EnemyProjectileSpawner(EnemyObject* enemy, Truck* truck);

	PlayerProjectile* PlayerProjectileSpawner(PlayerObject* player, Truck* truck);

private:
	float m_time;
	float m_alarm;

	Truck* m_truck;
};