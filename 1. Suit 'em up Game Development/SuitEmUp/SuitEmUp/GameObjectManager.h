#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <vector>

class Game;
class GameObject;
class Engine;
class Truck;
class PlayerObject;
class EnemyObject;
class Projectile;
class Spawner;

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void Update(/*float deltatime*/);

	void AttachObject(GameObject* object);

	void DetachObject(GameObject* object);
	void DetachObject();
	
	sf::Vector2f GetStartPosition(GameObject *GO);

	void DrawObject();

private:
//	std::vector<GameObject*> m_gameobject;
	Truck* m_truck;
	PlayerObject* m_player;
	std::vector<EnemyObject*> m_enemies;
	std::vector<Projectile*> m_projectiles;
	Spawner* m_spawner;
};