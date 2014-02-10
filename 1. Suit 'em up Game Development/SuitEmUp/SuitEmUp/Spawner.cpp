// Spawner.cpp

#include "Spawner.h"
#include "Truck.h"
#include "EnemyObject.h"
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
	EnemyObject* enemy = new EnemyObject(m_truck, sm->Load("../data/sprites/virveltuss.png", "Test", 0.1, 0.1));
	
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

bool Spawner::EnemyDestroyer(EnemyObject* enemy, PlayerProjectile* bullet){
	
	float delta_x=enemy->GetPosition().x-bullet->GetPosition().x;
	float delta_y=enemy->GetPosition().y-bullet->GetPosition().y;

	float dist=sqrt(delta_x*delta_x+delta_y*delta_y);

	if(dist<50) return true;
	
	return false;
}