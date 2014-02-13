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
class PlayerProjectile;
class EnemyProjectile;
class Spawner;
class SpriteManager;
class InputManager;
<<<<<<< HEAD
class HpBar;
=======
class Button;
>>>>>>> c42c71919f772c39d66c58414c85ae2c7030474d

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
	HpBar *m_hpbar;
	std::vector<EnemyObject*> m_enemies;
	std::vector<PlayerProjectile*> m_player_projectiles;
	std::vector<EnemyProjectile*> m_enemy_projectiles;

	float minus;
	float current;

	Spawner* m_spawner;
	InputManager* m_input;

<<<<<<< HEAD
	sf::Sprite* m_backgound;
=======
	std::vector<Button*> m_vButtons;

>>>>>>> f5626915c20a6be1bbda3a8fdc293ecd9796d345
};