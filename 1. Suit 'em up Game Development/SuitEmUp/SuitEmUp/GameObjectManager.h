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
class RepairKit;
class SniperGirl;

class HpBar;
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
	void UpdateButtons();
	void DrawButtons();
	void CreateCusomizationButtons();
	void DrawCustomizationButtons();


	std::vector<Button*> m_vButtons;
	std::vector<Button*> m_vCustomizeButtons;
private:
	//	std::vector<GameObject*> m_gameobject;
	Truck* m_truck;
	PlayerObject* m_player;
	HpBar *m_hpbar;
	std::vector<EnemyObject*> m_enemies;
	std::vector<SuperEnemy*> m_supers;
	std::vector<SniperGirl*> m_girls;

	std::vector<PlayerProjectile*> m_player_projectiles;
	std::vector<EnemyProjectile*> m_enemy_projectiles;

	Spawner* m_spawner;
	InputManager* m_input;

	sf::Sprite* m_backgound;
<<<<<<< HEAD
=======

<<<<<<< HEAD
	//std::vector<Button*> m_vButtons;

	std::vector<RepairKit*> m_vRepairKits;
=======
	std::vector<RepairKit*> m_vRepairKits;
=======


>>>>>>> cd4987c04e00677ea80ba874e4a1270b05829907

	//std::vector<Button*> m_vButtons;

	std::vector<RepairKit*> m_vRepairKits;

<<<<<<< HEAD

=======
>>>>>>> 1a6c8b5360e57be636a0346d92d080beb822115b
>>>>>>> 5ff85ee799fbfebce5ebe69859d48c834abc72e4
>>>>>>> cd4987c04e00677ea80ba874e4a1270b05829907
};