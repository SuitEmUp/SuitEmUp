// Spawner.cpp

#include "Spawner.h"
#include "Truck.h"
#include "EnemyObject.h"
#include "EnemyProjectile.h"
#include "PlayerProjectile.h"


Spawner::Spawner(Truck* truck){
	m_truck = truck;
	m_time=0;
	m_alarm=20;
	srand(time(NULL));
};

bool Spawner::Timer(/*deltatime*/){
	m_time+=0.1;
	if(m_time>m_alarm){
		m_time=0;
		return true;
	};
	return false;
};

EnemyObject* Spawner::EnemySpawner(SpriteManager* sm){
	EnemyObject* enemy = new EnemyObject(m_truck, sm->Load("../data/sprites/virveltuss.png", "Test", 0.3, 0.3));
	
	int q=rand()%2;
	int y;
	if(q==1){
		y=720;
	}
	else if(q==0){
		y=0;
	}
	int x=rand()%1281;
	enemy->SetPosition(x, y);
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