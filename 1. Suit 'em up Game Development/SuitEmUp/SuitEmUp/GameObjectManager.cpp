//GameObjectManager.cpp

#include "GameObjectManager.h"
#include "GameObject.h"
#include "DrawManager.h"
#include "Sprite.h"
#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

GameObjectManager::GameObjectManager()
{

}
GameObjectManager::~GameObjectManager()
{

}
//Update
void GameObjectManager::Update(float deltatime)
{
	for (auto it = m_gameobject->begin(); it != m_gameobject->end(); ++it)
	{
		GameObject *obj = *it;
		obj->Update();
		if(obj->GetType() /*== PLAYER*/)
		{
			/*obj->GetSprite()->Update(deltatime);*/
		}
	}
}
//GetStartPosition
sf::Vector2u GameObjectManager::GetStartPosition(GameObject *GO)
{
	return GO->GetPosition();
}
//attach 
void GameObjectManager::AttachObject(GameObject *object)
{

	m_gameobject->push_back(object);

}
//detach
void GameObjectManager::DetachObject(GameObject *object)
{
	for (auto it = m_gameobject->begin();it != m_gameobject->end();)
	{
		GameObject *obj = *it;
		if (obj = object)
		{
			if(obj != nullptr)
			{
				/*delete (*it)->GetCollider();*/
				
				delete *it;
				*it = nullptr;
			//	auto old = it;
				//m_gameobject.pop_back();
			}

			it++;
		}
	}
}

void GameObjectManager::DetachObject()
{
	for( auto it = m_gameobject->begin();it != m_gameobject->end(); ) 
	{	

		/*delete (*it)->GetCollider();*/
		delete *it;
		auto old = it;

		it++;
		//m_gameobject.erase(old);		
	}

}

void GameObjectManager::DrawObject(DrawManager *draw)
{
	for (auto it = m_gameobject->begin(); it != m_gameobject->end(); ++it)
	{
		GameObject *obj = *it;
		if (obj->HasSprite())
		{
			if(obj->GetType() /*== PLAYER*/)
			{
				/*draw->Draw(obj->GetSprite(), obj->GetPosition().m_x, obj->GetPosition().m_y, 70, 70);*/
			}
			else
			{
				/*draw->Draw(obj->GetSprite(), obj->GetPosition().m_x, obj->GetPosition().m_y);*/
			}
		}
	}
}