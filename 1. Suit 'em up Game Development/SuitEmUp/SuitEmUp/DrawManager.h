//DrawManager.h

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class Sprite;
class GameObject;

class DrawManager {
friend class SpriteManager;
friend class GameObjectManager;
public:
	DrawManager();
	~DrawManager();
	bool initialize(sf::RenderWindow & m_window);
	void Cleanup();
	void Clear();
	void Display();
	void Draw(std::vector<GameObject*> *m_gameobject);

	
	sf::RenderWindow GetRenderer();
private:
	 sf::RenderWindow *m_renderer;
};
