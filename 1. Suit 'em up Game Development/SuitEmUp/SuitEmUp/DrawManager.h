//DrawManager.h

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class Sprite;

class DrawManager {
friend class SpriteManager;
public:
	DrawManager();
	~DrawManager();
	bool initialize(sf::RenderWindow* m_window);
	void Cleanup();
	void Clear();
	void Display();
	void Draw(Sprite *m_sprite,int m_x,int m_y,int m_w = 0,int m_h = 0);
	
	sf::RenderWindow GetRenderer();
private:
	 sf::RenderWindow *m_renderer;
};
