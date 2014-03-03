#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Animation.h"
#include <string>

class SpriteManager
{
public:
	SpriteManager(){};
	~SpriteManager();

	sf::Sprite* Load(const std::string &filename, const std::string spritename, float x_scale = 1.0, float y_scale = 1.0);
	
	Animation* LoadAnimatedSprite(const std::string &xfilename, const std::string xspritename, float frameTime, bool paused, bool looped,
		float x_scale = 1.0, float y_scale = 1.0);

	void SpriteManager::DestroyAnimation();

private:
	std::map<std::string,sf::Texture*> m_Textures; // sparar texturer efter filnamn
	std::map<std::string,sf::Sprite*> m_Sprites; // sparar sprites efter filnamn

	
};
//laban was here
// So was seamus :I