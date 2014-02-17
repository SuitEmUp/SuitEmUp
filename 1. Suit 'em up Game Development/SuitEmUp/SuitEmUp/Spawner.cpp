// Spawner.cpp

#include "Spawner.h"
#include "Truck.h"
#include "EnemyObject.h"
#include "SuperEnemy.h"
#include "PlayerProjectile.h"
#include "SniperGirl.h"


Spawner::Spawner(Truck* truck){
	m_truck = truck;
	m_time=0;
	m_alarm=20;
	srand(time(NULL));
};

bool Spawner::Timer(float deltatime){
	
	m_time+=deltatime*4;
	if(m_time>m_alarm){
		m_time=0;
		m_alarm*=0.9;
		if(m_alarm<2.5) m_alarm=2.5;
		return true;
	};
	return false;
};

EnemyObject* Spawner::EnemySpawner(SpriteManager* sm){

	EnemyObject* enemy = new EnemyObject(m_truck, sm->Load("../data/sprites/BanditEnBlack.png", "Bandit1", 1, 1));
	
	int spawndirection = rand()%2;
	if(spawndirection == 0){
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
	}
	else if(spawndirection==1){
		int q=rand()%2;
		int x;
		if(q==1){
			x=0;
		}
		else if(q==0){
			x=1280;
		}
		int y=rand()%720;
		enemy->SetPosition(x, y);
		return enemy;
	}
	delete enemy;
	enemy=nullptr;
	return nullptr;
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

bool Spawner::SuperDestroyer(SuperEnemy* enemy, PlayerProjectile* bullet){
	
	float delta_x=enemy->GetPosition().x-bullet->GetPosition().x;
	float delta_y=enemy->GetPosition().y-bullet->GetPosition().y;

	float dist=sqrt(delta_x*delta_x+delta_y*delta_y);

	if(dist<50) return true;
	
	return false;
}

bool Spawner::SniperDestroyer(SniperGirl* enemy, PlayerProjectile* bullet){
	
	float delta_x=enemy->GetPosition().x-bullet->GetPosition().x;
	float delta_y=enemy->GetPosition().y-bullet->GetPosition().y;

	float dist=sqrt(delta_x*delta_x+delta_y*delta_y);

	if(dist<50) return true;
	
	return false;
}

SuperEnemy* Spawner::SuperSpawner(SpriteManager* sm){
<<<<<<< HEAD
	SuperEnemy* enemy = new SuperEnemy(m_truck, sm->Load("../data/sprites/SuperBandit.png", "SuperBandit", 1, 1));
	
	int spawndirection = rand()%2;
	if(spawndirection == 0){
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
	}
	else if(spawndirection==1){
		int q=rand()%2;
		int x;
		if(q==1){
			x=0;
		}
		else if(q==0){
			x=1280;
		}
		int y=rand()%720;
		enemy->SetPosition(x, y);
		return enemy;
	}
	delete enemy;
	enemy=nullptr;
	return nullptr;
};

SniperGirl* Spawner::SniperSpawner(SpriteManager* sm){
	SniperGirl* enemy = new SniperGirl(m_truck, sm->Load("../data/sprites/Bandit_2.png", "SniperBandit", 1, 1));
=======
<<<<<<< HEAD
	
=======
>>>>>>> 4c7192e126055f24c3b21ff3ef05814d9a8cab55
	SuperEnemy* enemy = new SuperEnemy(m_truck, sm->Load("../data/sprites/SuperBandit.png", "SuperBandit", 1.0, 1.0));
>>>>>>> 3b249d3c7d29b499bad311b0b23267fb3c38b58c
	
	int spawndirection = rand()%2;
	if(spawndirection == 0){
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
	}
	else if(spawndirection==1){
		int q=rand()%2;
		int x;
		if(q==1){
			x=0;
		}
		else if(q==0){
			x=1280;
		}
		int y=rand()%720;
		enemy->SetPosition(x, y);
		return enemy;
	}
	delete enemy;
	enemy=nullptr;
	return nullptr;
};