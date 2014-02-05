//GameObjectManager.cpp

#include "GameObjectManager.h"
#include "GameObject.h"
#include "DrawManager.h"
#include "Sprite.h"
#include <iostream>
#include "PlayerObject.h"
#include "Truck.h"
#include "Spawner.h"

GameObjectManager::GameObjectManager()
{
	//m_truck = new Truck();
	//m_player = new PlayerObject(m_truck, nullptr);
	//m_spawner = new Spawner(m_truck);
	//m_enemies.clear();
	//m_projectiles.clear();
	//m_game_over = false;
}
GameObjectManager::~GameObjectManager()
{
	if(m_truck != nullptr){
		delete m_truck;
		m_truck = nullptr;
	}
	if(m_player != nullptr){
		delete m_player;
		m_player = nullptr;
	}
	if(m_spawner != nullptr){
		delete m_spawner;
		m_spawner = nullptr;
	}
	// iterator to delete enemies and projectiles
}
//Update
void GameObjectManager::Update(/*float deltatime*/)
{
	//if(m_truck->Update()){
	//	m_game_over = true;
	//};
	//if(m_player->Update()){
	//	//m_projectiles.push_back(m_player->Bullet());
	//}
	//if(m_spawner->Timer()){
	//	m_enemies.push_back(m_spawner->EnemySpawner());
	//}
	//for(int i = 0; i<m_enemies.size(); i++){
	//	if(m_enemies.at(i)!=nullptr){
	//		if(m_enemies.at(i)->Update()){
	//			//m_projectiles.push_back(m_enemies.at(i)->Bullet)
	//		}
	//	}
	//};
	////m_spawner->KillEnemyIfNeeded();
	//for(int i=0; i<m_projectiles.size(); i++){
	//	if(m_projectiles.at(i)->Update()){
	//		//erase that shit
	//	};
	//};

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

void GameObjectManager::DrawObject()
{
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