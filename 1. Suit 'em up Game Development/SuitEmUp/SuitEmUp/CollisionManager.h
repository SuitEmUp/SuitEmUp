//CollisionManager.h


#pragma once

#include <vector>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class GameObject;
class Collider;
class Vector2;
class GameObjectManager;

class CollisionManager
{
public:
	CollisionManager(GameObjectManager *gom);
	~CollisionManager();

	void CheckCollision();
	Collider *CreateCollider(sf::Vector2f &position, sf::Vector2f &extension);
	void DestroyCollider(Collider *collider);

protected:

	int score; //the lower the better
	bool once;
	GameObjectManager *m_gom;
//	int amount_of_objects;
	std::vector<Collider*> m_object;

};