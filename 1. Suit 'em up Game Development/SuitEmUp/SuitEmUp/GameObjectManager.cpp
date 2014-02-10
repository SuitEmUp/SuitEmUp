//GameObjectManager.cpp

#include "GameObjectManager.h"
#include "GameObject.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "PlayerObject.h"
#include "Truck.h"
#include "Spawner.h"
#include <iostream>

GameObjectManager::GameObjectManager(SpriteManager* sm, sf::RenderWindow* rw)
{
	m_spritemanager=sm;
	m_window=rw;
	m_truck=nullptr;
	m_player=nullptr;
	m_spawner=nullptr;
	m_enemies.clear();
	m_player_projectiles.clear();
	m_enemy_projectiles.clear();
}

GameObjectManager::~GameObjectManager()
{
//	m_spritemanager=nullptr;
}

void GameObjectManager::CreateGameObjects()
{
	m_truck = new Truck(m_spritemanager->Load("../data/sprites/virveltuss.png", "Virveltuss", 0.1, 0.1));
	m_player = new PlayerObject(m_truck, m_spritemanager->Load("../data/sprites/ArianaSprite.png", "Ariana's sprite", 1, 1));
	m_spawner = new Spawner(m_truck);
	m_enemies.clear();
	m_player_projectiles.clear();
	m_enemy_projectiles.clear();
	m_game_over = false;
}

void GameObjectManager::ClearGameObjects()
{
	if(m_truck != nullptr){
		//delete m_truck->GetSprite();
		delete m_truck;
		m_truck = nullptr;
	}
	if(m_player != nullptr){
		//delete m_player->GetSprite();
		delete m_player;
		m_player = nullptr;
	}
	if(m_spawner != nullptr){
		delete m_spawner;
		m_spawner = nullptr;
	}
	for (auto it = m_enemies.begin();it != m_enemies.end(); it++)
	{
		if(*it != nullptr) {
			//delete (*it)->GetSprite();
			delete *it;
		}
	
	}
	m_enemies.clear();
	for (auto it = m_enemy_projectiles.begin();it != m_enemy_projectiles.end(); it++)
	{
		if(*it != nullptr) {
			//delete (*it)->GetSprite();
			delete *it;
		}
	
	}
	m_enemy_projectiles.clear();
	for (auto it = m_player_projectiles.begin();it != m_player_projectiles.end(); it++)
	{
		if(*it != nullptr) {
			//delete (*it)->GetSprite();
			delete *it;
		}
	
	}
	m_player_projectiles.clear();
}
//Update
void GameObjectManager::Update(/*float deltatime*/InputManager* input)
{
	if(m_truck->Update()){
		m_game_over = true;
	};
	if(m_player->Update(input)){
		m_player_projectiles.push_back(new PlayerProjectile(m_truck, m_player, m_spritemanager->Load("../data/sprites/BulletProjectile.png", "Test", 0.3, 0.3)));
	}
	if(m_spawner->Timer()){
		m_enemies.push_back(m_spawner->EnemySpawner(m_spritemanager));
	}
	for(int i = 0; i<m_enemies.size(); i++){
		if(m_enemies.at(i)!=nullptr){
			if(m_enemies.at(i)->Update()){
				m_enemy_projectiles.push_back(new EnemyProjectile(m_truck, m_enemies.at(i),m_spritemanager->Load("../data/sprites/BulletProjectile.png", "Test", 0.3, 0.3)));
			}
		}
	};
	
	for(int i = 0; i< m_enemy_projectiles.size(); i++){
		if(m_enemy_projectiles.at(i)->Update(m_truck)){
			//delete (*it)->GetSprite();
			m_enemy_projectiles.erase(m_enemy_projectiles.begin()+i);
			i--;
		};
	};

	for(int i = 0; i< m_player_projectiles.size(); i++){
		if(m_player_projectiles.at(i)->Update(m_truck)){
			//delete (*it)->GetSprite();
			m_player_projectiles.erase(m_player_projectiles.begin()+i);
			i--;
		};
	};

	for(int i = 0; i < m_player_projectiles.size(); i++){
		
			for(int j = 0; j<m_enemies.size(); j++){
				
				if(m_spawner->EnemyDestroyer(m_enemies.at(j), m_player_projectiles.at(i))){
						//delete (*it)->GetSprite();
						//delete (*at)->GetSprite();
						m_player_projectiles.erase(m_player_projectiles.begin()+i);
						m_enemies.erase(m_enemies.begin()+j);
						--i;
						--j;
						break;
					};
				
			};
		

	};

	//for (auto it = m_gameobject.begin(); it != m_gameobject.end(); ++it)
	//{
	//	GameObject *obj = *it;

	//	//if(obj->GetType() /*== PLAYER*/)
	//	//{
	//	//	/*obj->GetSprite()->Update(deltatime);*/
	//	//}
	//}
}
//GetStartPosition
sf::Vector2f GameObjectManager::GetStartPosition(GameObject *GO)
{
	return GO->GetPosition();
}
//attach 
void GameObjectManager::AttachObject(GameObject *object)
{

//	m_gameobject.push_back(object);

}
//detach
void GameObjectManager::DetachObject(GameObject *object)
{
	//for (auto it = m_gameobject.begin();it != m_gameobject.end();)
	//{
	//	GameObject *obj = *it;
	//	if (obj = object)
	//	{
	//		if(obj != nullptr)
	//		{
	//			/*delete (*it)->GetCollider();*/
	//			
	//			delete *it;
	//			*it = nullptr;
	//		//	auto old = it;
	//			//m_gameobject.pop_back();
	//		}

	//		it++;
	//	}
	//}
}

void GameObjectManager::DetachObject()
{
	//for( auto it = m_gameobject.begin();it != m_gameobject.end(); ) 
	//{	

	//	/*delete (*it)->GetCollider();*/
	//	delete (*it)->GetSprite();
	//	delete *it;
	//	/*auto old = it;

	//	it++;*/
	//	m_gameobject.erase(it);		
	//}

}

void GameObjectManager::DrawGameObjects()
{
	m_window->draw(*m_truck->GetSprite()); //Draws truck
	m_window->draw(*m_player->GetSprite()); //Draws player
	for(int i=0; i<m_enemies.size(); i++){
		if(m_enemies.at(i)!=nullptr){
			m_window->draw(*m_enemies.at(i)->GetSprite()); // draws all enemies
		}
	};
	for(int i=0; i<m_player_projectiles.size(); i++){
		if(m_player_projectiles.at(i)!=nullptr){
			m_window->draw(*m_player_projectiles.at(i)->GetSprite());	// draws all player projectiles
		}
	};
	for(int i=0; i<m_enemy_projectiles.size(); i++){
		if(m_enemy_projectiles.at(i)!=nullptr){
			m_window->draw(*m_enemy_projectiles.at(i)->GetSprite());	// draws all enemy projetiles
		}
	};
	//for (auto it = m_gameobject.begin(); it != m_gameobject.end(); ++it)
	//{
	//	GameObject *obj = *it;
	//	if (obj->HasSprite())
	//	{
	//		if(obj->GetType() /*== PLAYER*/)
	//		{
	//			/*draw->Draw(obj->GetSprite(), obj->GetPosition().m_x, obj->GetPosition().m_y, 70, 70);*/
	//		}
	//		else
	//		{
	//			/*draw->Draw(obj->GetSprite(), obj->GetPosition().m_x, obj->GetPosition().m_y);*/
	//		}
	//	}
	//}
}