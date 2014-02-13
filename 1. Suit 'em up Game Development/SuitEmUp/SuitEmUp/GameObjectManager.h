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
class SuperEnemy;
class PlayerProjectile;
class EnemyProjectile;
class Spawner;
class SpriteManager;
class InputManager;
class Button;

class GameObjectManager
{
public:
	GameObjectManager(SpriteManager* sm, sf::RenderWindow* rw, InputManager* input);
	~GameObjectManager();

	void CreateGameObjects();
	void Update(float deltatime);
	void ClearGameObjects();

	void AttachObject(GameObject* object);

	void DetachObject(GameObject* object);
	void DetachObject();

	sf::Vector2f GetStartPosition(GameObject *GO);

	void DrawGameObjects();

	bool m_game_over;

	SpriteManager* m_spritemanager; ///noooooo
	sf::RenderWindow* m_window;


	//Button related stuff?

	void CreateButtons();
	void DrawButtons();

private:
	//	std::vector<GameObject*> m_gameobject;
	Truck* m_truck;
	PlayerObject* m_player;
	std::vector<EnemyObject*> m_enemies;
	std::vector<SuperEnemy*> m_supers;

	std::vector<PlayerProjectile*> m_player_projectiles;
	std::vector<EnemyProjectile*> m_enemy_projectiles;

	Spawner* m_spawner;
	InputManager* m_input;

	sf::Sprite* m_backgound;
	std::vector<Button*> m_vButtons;
};