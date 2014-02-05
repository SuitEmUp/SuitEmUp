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
class SpriteManager;
class InputManager;

class GameObjectManager
{
public:
	GameObjectManager(SpriteManager* sm, sf::RenderWindow* rw);
	~GameObjectManager();

	void CreateGameObjects();
	void Update(/*float deltatime*/InputManager* input);
	void ClearGameObjects();

	void AttachObject(GameObject* object);

	void DetachObject(GameObject* object);
	void DetachObject();
	
	sf::Vector2f GetStartPosition(GameObject *GO);

	void DrawGameObjects();

	bool m_game_over;
private:
//	std::vector<GameObject*> m_gameobject;
	Truck* m_truck;
	PlayerObject* m_player;
	std::vector<EnemyObject*> m_enemies;
	std::vector<Projectile*> m_projectiles;
	Spawner* m_spawner;
	SpriteManager* m_spritemanager;
	sf::RenderWindow* m_window;
};