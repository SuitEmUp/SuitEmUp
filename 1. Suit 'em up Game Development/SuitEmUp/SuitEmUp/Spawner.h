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

	int NumberOfEnemieslvl1(float numberofenemies);
	int NumberOfEnemieslvl2(float numberofenemies);
	int NumberOfEnemieslvl3(float numberofenemies);

	float GetHpMultiplier();

	sf::Vector3i Wave();
	void UpdateTime(float deltatime);
	void NextWaveCheck();
	bool m_win;

private:

	float m_alarm;
	float m_time;
	float m_hpmultiplier;
	int m_wavenumber;

	int m_lastenemies;
	float m_enemytime;

	float m_spawningenemieslvl1;
	float m_currentenemieslvl1;
	float m_koeffecientlvl1;

	float m_spawningenemieslvl2;
	float m_currentenemieslvl2;
	float m_koeffecientlvl2;

	float m_spawningenemieslvl3;
	float m_currentenemieslvl3;
	float m_koeffecientlvl3;

	float m_waveduration;

	
	Truck* m_truck;
};