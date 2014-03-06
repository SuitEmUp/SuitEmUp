// Spawner.h

#pragma once;

#include "EnemyObject.h"
#include "EnemyProjectile.h"
#include "PlayerProjectile.h"

class SpriteManager;
class Truck;
class PlayerProjectile;
class SuperEnemy;
class SniperGirl;

class Spawner{
public:
	Spawner(Truck* truck);
	bool Timer(float deltatime);
	SuperEnemy* SuperSpawner(SpriteManager* sm);
	EnemyObject* EnemySpawner(SpriteManager* sm);
	SniperGirl* SniperSpawner(SpriteManager* sm);
	bool EnemyDestroyer(EnemyObject* enemy, PlayerProjectile* bullet);
	bool SuperDestroyer(SuperEnemy* enemy, PlayerProjectile* bullet);
	bool SniperDestroyer(SniperGirl* girl, PlayerProjectile* bullet);

	void KillCounter();
	bool SpawnAlarm();

	std::vector<EnemyObject*> EnemySpawner2(float deltatime, int numberofenemies);

	float GetHpMultiplier();

	sf::Vector3i Wave();


private:

	float m_time;
	float m_alarm;
	float m_hpmultiplier;
	int m_wavenumber;

	float m_enemytime;
	float m_koeffecient;
	float m_spawningenemies;

	Truck* m_truck;
};