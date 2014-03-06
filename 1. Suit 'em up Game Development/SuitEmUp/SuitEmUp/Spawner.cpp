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
	m_wavenumber = 0;
	m_alarm=20;
	srand(time(NULL));
};

bool Spawner::Timer(float deltatime){
	
	m_time+=deltatime*4;
	if(m_time>m_alarm){
		m_time=0;
		m_alarm*=0.9f;
		if(m_alarm<2.9f) m_alarm=2.9f;
		return true;
	};
	return false;
};

EnemyObject* Spawner::EnemySpawner(SpriteManager* sm){

	EnemyObject* enemy = new EnemyObject(m_truck, sm->Load("../data/sprites/Spritesheet_enemy_1_2.png", "Bandit1", 1, 1));
	
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

	if(dist<25) return true;
	
	return false;
}

bool Spawner::SuperDestroyer(SuperEnemy* enemy, PlayerProjectile* bullet){
	
	float delta_x=enemy->GetPosition().x-bullet->GetPosition().x;
	float delta_y=enemy->GetPosition().y-bullet->GetPosition().y;

	float dist=sqrt(delta_x*delta_x+delta_y*delta_y);

	if(dist<25) return true;
	
	return false;
}

bool Spawner::SniperDestroyer(SniperGirl* enemy, PlayerProjectile* bullet){
	
	float delta_x=enemy->GetPosition().x-bullet->GetPosition().x;
	float delta_y=enemy->GetPosition().y-bullet->GetPosition().y;

	float dist=sqrt(delta_x*delta_x+delta_y*delta_y);

	if(dist<25) return true;
	
	return false;
}

SuperEnemy* Spawner::SuperSpawner(SpriteManager* sm){

	SuperEnemy* enemy = new SuperEnemy(m_truck, sm->Load("../data/sprites/Spritesheet_enemy_1_2.png", "SuperBandit", 1.0, 1.0));

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

	SniperGirl* enemy = new SniperGirl(m_truck, sm->Load("../data/sprites/new_82_87.png", "SniperBandit", 1, 1));

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

sf::Vector3i Spawner::Wave(){
	// vilken våg man är på
	m_wavenumber +=1;

	if (m_wavenumber == 1){ return sf::Vector3i(100, 1, 1); m_hpmultiplier = 1;}
	if (m_wavenumber == 2){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 1.2;}
	if (m_wavenumber == 3){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 1.4;}
	if (m_wavenumber == 4){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 1.6;}
	if (m_wavenumber == 5){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 1.8;}
	if (m_wavenumber == 6){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 2;}
	if (m_wavenumber == 7){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 2.2;}
	if (m_wavenumber == 8){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 2.4;}
	if (m_wavenumber == 9){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 2.6;}
	if (m_wavenumber == 10){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 2.8;}
	if (m_wavenumber == 11){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 3;}
}

float Spawner::GetHpMultiplier(){
	return m_hpmultiplier;
}

std::vector<EnemyObject*> Spawner::EnemySpawner2(float deltatime, int numberofenemies){
	m_koeffecient = numberofenemies*2;
	m_enemytime+=deltatime;
	m_spawningenemies = m_koeffecient*m_enemytime;
	std::vector<EnemyObject*> t_enemies;
	if(m_spawningenemies >=1){
		int t_spawningenemies = m_spawningenemies;
		for(int i = 0; i<t_spawningenemies; i++){
			//t_enemies.push_back(new enemy);
		}
		m_spawningenemies -= t_spawningenemies;
	}


	return t_enemies;
};