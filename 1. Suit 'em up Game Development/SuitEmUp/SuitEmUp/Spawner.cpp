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
	tm_message = new sf::Text;
	fm_font = new sf::Font;
	if (!fm_font->loadFromFile("../assets/fonts/Viking_n.ttf"))
	{ printf("Could not load font\n"); }
	sm_message = "";
	tm_message->setFont(*fm_font);
	tm_message->setCharacterSize(30);
	tm_message->setColor(sf::Color::Black);
	tm_message->setOrigin(30/2, 30/2);
	tm_message->setPosition(440.f, 50.f);	
	tm_message->setStyle(sf::Text::Bold);

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

	EnemyObject* enemy = new EnemyObject(m_truck, sm);

	if(m_wavenumber >= 7)
	{
		enemy->SetSpeed(400.0f);
	}
	else if(m_wavenumber >= 3)
	{
		enemy->SetSpeed(250.0f);
	}
	else
	{
		enemy->SetSpeed(150.0f);
	}

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

	float delta_x=enemy->GetPosition().x -bullet->GetPosition().x;
	float delta_y=enemy->GetPosition().y -bullet->GetPosition().y;

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
	float offsetX = sin(enemy->GetSprite()->getRotation()*3.14/180) * -25;
	float offsetY = cos(enemy->GetSprite()->getRotation()*3.14/180) * -25;

	float delta_x=enemy->GetPosition().x - offsetY +-bullet->GetPosition().x;
	float delta_y=enemy->GetPosition().y - offsetX -bullet->GetPosition().y;

	float dist=sqrt(delta_x*delta_x+delta_y*delta_y);

	if(dist<25) return true;

	return false;
}

SuperEnemy* Spawner::SuperSpawner(SpriteManager* sm){

	SuperEnemy* enemy = new SuperEnemy(m_truck, sm);

	if(m_wavenumber >= 10)
	{
		enemy->SetSpeed(460.0f);
	}
	else if(m_wavenumber >= 3)
	{
		enemy->SetSpeed(310.0f);
	}
	else
	{
		enemy->SetSpeed(210.0f);
	}

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

SniperGirl* Spawner::SniperSpawner(SpriteManager* sm)
{
	SniperGirl* enemy = new SniperGirl(m_truck, sm);

	if(m_wavenumber >= 7)
	{
		enemy->SetSpeed(250.0f);
	}
	else if(m_wavenumber >= 3)
	{
		enemy->SetSpeed(100.0f);
	}
	else
	{
		enemy->SetSpeed(50.0f);
	}

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

	if (m_wavenumber == 0)
	{
		sm_message = "Wave 1\n'NoobFilter'"; 
		return sf::Vector3i(40, 0, 0); 
		m_hpmultiplier = 1;
	}
	if (m_wavenumber == 1)
	{
		sm_message = "Wave 2\n'You Think This is a Game?' ";
		m_waveduration = 150;
		return sf::Vector3i(100, 10, 0); 
		m_hpmultiplier = 1;}
	if (m_wavenumber == 2)
	{
		sm_message = "Wave 3\n'You Wont Win This One' "; 
		m_waveduration = 80;
		return sf::Vector3i(100, 15, 0); 
		m_hpmultiplier = 1;
	}
	if (m_wavenumber == 3)
	{
		m_waveduration = 60 ;
		sm_message = "Wave 4\n'Shooting From Afar' ";
		return sf::Vector3i(70, 15, 1);
		m_hpmultiplier = 1;
	}
	if (m_wavenumber == 4){sm_message = "Wave 5\n'Unfomfortable Sofa' "; return sf::Vector3i(70, 30, 3); m_hpmultiplier = 1.2;}
	if (m_wavenumber == 5){sm_message = "Wave 6\n'Playtime is OVER' "; return sf::Vector3i(40, 40, 10); m_hpmultiplier = 1.4;}
	if (m_wavenumber == 6){sm_message = "Wave 7\n'Stop Cheating Wave' "; return sf::Vector3i(40, 20, 25); m_hpmultiplier = 1.6;}
	if (m_wavenumber == 7)
	{
		m_waveduration = 30;
		sm_message = "Wave 8\n'Bandits are now on Cocaine' "; 
		return sf::Vector3i(0, 0, 40); 
		m_hpmultiplier = 1.8; 
	}
	if (m_wavenumber == 8)
	{
		m_waveduration = 50;
		sm_message = "Wave 9\n'Bandimons! Attack!'"; 
		return sf::Vector3i(100, 40, 30); 
		m_hpmultiplier = 2;
	}
	if (m_wavenumber == 9){m_waveduration = 40;sm_message = "Wave 10\n'Don't Froth it Doesn't 'Suit' You' "; return sf::Vector3i(50, 60, 40); m_hpmultiplier = 2.2;}
	if (m_wavenumber == 10){m_waveduration = 40;sm_message = "Wave 11\n'Last Level!"; return sf::Vector3i(0,75, 50); m_hpmultiplier = 2.4;}
	if (m_wavenumber == 11){m_waveduration = 50; sm_message = "Wave 11\n'Joking Ha! Take This!"; return sf::Vector3i(60, 60, 60); m_hpmultiplier = 2.6;}
	if(m_wavenumber == 12) 
	{
		sm_message = "ugh...how?...I will...\ncough....return...";
		m_waveduration = 10; 
		return sf::Vector3i(0,0,0);
	}
	if(m_wavenumber == 13)
	{
		m_win = true;
	}

	return sf::Vector3i(0,0,0);

}

void Spawner::UpdateTime(float deltatime){
	m_time += deltatime;
};

void Spawner::NextWaveCheck(){
	if(m_time > m_waveduration){
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

	if(m_spawningenemieslvl3 > 1) {
		int t_spawningenemies = m_spawningenemieslvl3;
		m_spawningenemieslvl3 -= t_spawningenemies;
		return t_spawningenemies;
	}
	return 0;
};
sf::Text *Spawner::WaveTitle()
{
	tm_message->setString(sm_message);
	return tm_message;
}
float Spawner::WaveCheck()
{
	return m_time;
}
