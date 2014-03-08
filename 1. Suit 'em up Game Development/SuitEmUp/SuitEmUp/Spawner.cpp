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
	m_enemytime = 0;
	srand(time(NULL));
	m_currentenemieslvl1 = 0;
	m_spawningenemieslvl1 = 0;
	m_currentenemieslvl2 = 0;
	m_spawningenemieslvl2 = 0;
	m_currentenemieslvl3 = 0;
	m_spawningenemieslvl3 = 0;

	m_waveduration = 60;
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
			y=800;
		}
		else if(q==0){
			y=-60;
		}
		int x=rand()%1310;
		enemy->SetPosition(x, y);
		return enemy;
	}
	else if(spawndirection==1){
		int q=rand()%2;
		int x;
		if(q==1){
			x=-60;
		}
		else if(q==0){
			x=1340;
		}
		int y=rand()%780;
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
			y=800;
		}
		else if(q==0){
			y=-80;
		}
		int x=rand()%1281;
		enemy->SetPosition(x, y);
		return enemy;
	}
	else if(spawndirection==1){
		int q=rand()%2;
		int x;
		if(q==1){
			x=-80;
		}
		else if(q==0){
			x=1360;
		}
		int y=rand()%800;
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
			y=800;
		}
		else if(q==0){
			y=-80;
		}
		int x=rand()%1281;
		enemy->SetPosition(x, y);
		return enemy;
	}
	else if(spawndirection==1){
		int q=rand()%2;
		int x;
		if(q==1){
			x=-80;
		}
		else if(q==0){
			x=1360;
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

	if (m_wavenumber == 0){ return sf::Vector3i(40, 0, 0); m_hpmultiplier = 1;}
	if (m_wavenumber == 1){ return sf::Vector3i(50, 10, 1); m_hpmultiplier = 1;}
	if (m_wavenumber == 2){ return sf::Vector3i(60, 20, 5); m_hpmultiplier = 1.2;}
	if (m_wavenumber == 3){ return sf::Vector3i(100, 40, 10); m_hpmultiplier = 1.4;}
	if (m_wavenumber == 4){ return sf::Vector3i(100, 80, 20); m_hpmultiplier = 1.6;}
	if (m_wavenumber == 5){ return sf::Vector3i(100, 100, 40); m_hpmultiplier = 1.8;}
	if (m_wavenumber == 6){ return sf::Vector3i(200, 100, 50); m_hpmultiplier = 2;}
	if (m_wavenumber == 7){ return sf::Vector3i(200, 150, 80); m_hpmultiplier = 2.2;}
	if (m_wavenumber == 8){ return sf::Vector3i(1, 1, 1000); m_hpmultiplier = 2.4;}
	if (m_wavenumber == 9){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 2.6;}
	if (m_wavenumber == 10){ return sf::Vector3i(1, 1, 1); m_hpmultiplier = 2.8;}

	return sf::Vector3i(0,0,0);

}

void Spawner::UpdateTime(float deltatime){
	m_time += deltatime;
};

void Spawner::NextWaveCheck(){
	if(m_time > 60){
		m_wavenumber +=1;
		m_time = 0;
		m_currentenemieslvl1 = 0;
		m_spawningenemieslvl1 = 0;
		m_currentenemieslvl2 = 0;
		m_spawningenemieslvl2 = 0;
		m_currentenemieslvl3 = 0;
		m_spawningenemieslvl3 = 0;
	};
};

float Spawner::GetHpMultiplier(){
	return m_hpmultiplier;
}

int Spawner::NumberOfEnemieslvl1(float numberofenemies){
	m_koeffecientlvl1 = (numberofenemies/(m_waveduration*m_waveduration));

	float t_previousenemies = m_currentenemieslvl1;

	m_currentenemieslvl1 = m_koeffecientlvl1*m_time*m_time;

	float m_deltaenemies = m_currentenemieslvl1 - t_previousenemies;

	m_spawningenemieslvl1 += m_deltaenemies;

	if(m_spawningenemieslvl1 > 1){
	int t_spawningenemies = m_spawningenemieslvl1;
	m_spawningenemieslvl1 -= t_spawningenemies;
	return t_spawningenemies;
	}
	return 0;
};

int Spawner::NumberOfEnemieslvl2(float numberofenemies){
	m_koeffecientlvl2 = (numberofenemies/(m_waveduration*m_waveduration));

	float t_previousenemies = m_currentenemieslvl2;

	m_currentenemieslvl2 = m_koeffecientlvl2*m_time*m_time;

	float m_deltaenemies = m_currentenemieslvl2 - t_previousenemies;

	m_spawningenemieslvl2 += m_deltaenemies;

	if(m_spawningenemieslvl2 > 1){
	int t_spawningenemies = m_spawningenemieslvl2;
	m_spawningenemieslvl2 -= t_spawningenemies;
	return t_spawningenemies;
	}
	return 0;
};

int Spawner::NumberOfEnemieslvl3(float numberofenemies){
	m_koeffecientlvl3 = (numberofenemies/(m_waveduration*m_waveduration));

	float t_previousenemies = m_currentenemieslvl3;

	m_currentenemieslvl3 = m_koeffecientlvl3*m_time*m_time;

	float m_deltaenemies = m_currentenemieslvl3 - t_previousenemies;

	m_spawningenemieslvl3 += m_deltaenemies;

	if(m_spawningenemieslvl3 > 1){
	int t_spawningenemies = m_spawningenemieslvl3;
	m_spawningenemieslvl3 -= t_spawningenemies;
	return t_spawningenemies;
	}
	return 0;
};