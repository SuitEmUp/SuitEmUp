#pragma once

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <vector>


class Game;
class GameObject;
class Engine;

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void Update(float deltatime);

	void AttachObject(GameObject* object);

	void DetachObject(GameObject* object);
	void DetachObject();
	
	sf::Vector2f GetStartPosition(GameObject *GO);

	void DrawObject();

private:
	std::vector<GameObject*> m_gameobject;


};