// Spawner.cpp

#include "Spawner.h"
#include "Truck.h"
#include "EnemyObject.h"
#include "EnemyProjectile.h"
#include "PlayerProjectile.h"

Spawner::Spawner(Truck* truck){
	m_truck = truck;
	m_time=0;
};

bool Spawner::Timer(/*deltatime*/){
	/*N�n formel h�r som g�r att tiden minskar...*/
	
	if(m_time>m_alarm){
		m_time=0;
		return true;
	};
	return false;
};

EnemyObject* Spawner::EnemySpawner(){
	EnemyObject* enemy = new EnemyObject(m_truck, nullptr);
	return enemy;
};
//EnemyProjectile* Spawner::EnemyProjectileSpawner(EnemyObject* enemy, Truck* truck){
//	EnemyProjectile* enemyprojectile = new EnemyProjectile(m_truck, nullptr);
//	return enemyprojectile;
//};
//
//PlayerProjectile* Spawner::PlayerProjectileSpawner(PlayerObject* player, Truck* truck){
//	PlayerProjectile* playerprojectile = new PlayerProjectile(m_truck, nullptr);
//	return playerprojectile;
//};