#include "SpriteManager.h"


SpriteManager::~SpriteManager()
{
	{
		auto it = m_Sprites.begin();
		while (it != m_Sprites.end())
		{
			if(it->second != nullptr){
				delete it->second;
				it->second = nullptr;
				it++;
			}
		}
		m_Sprites.clear();
	}
	{
		auto it = m_Textures.begin();
		while (it != m_Textures.end())
		{
			if(it->second != nullptr){
				delete it->second;
				it->second = nullptr;
				it++;
			}
		}
		m_Textures.clear();
	}

}; 

// Faktumet �r ju att man absolut inte b�r koda med bokst�verna ��� eftersom att inte allas tangentbord har dessa bokst�ver

sf::Sprite* SpriteManager::Load(const std::string &filename, const std::string spritename, float x_scale, float y_scale)
{
	auto it = m_Textures.find(filename); //searches for texture
	if(it == m_Textures.end()) //if texture isnt found
	{
		sf::Texture* xTexture = new sf::Texture; //skapa en ny textur

		if(!xTexture->loadFromFile(filename)) // ladda texturen fr�n en fil
			return nullptr;

		std::pair<std::string, sf::Texture*> xTexturePair(filename, xTexture); //l�gg in den nya texturen i map'en
		m_Textures.insert(xTexturePair);
		it = m_Textures.find(filename);
	}
	sf::Sprite* xSprite = new sf::Sprite; //skapa en ny sprite
	xSprite->setTexture(*it->second); //s�tt spritens textur
	xSprite->setScale(x_scale, y_scale); //s�tt scale
	std::pair<std::string,sf::Sprite*>xSpritePair(spritename, xSprite); //l�gg in den nya spriten i map'en
	m_Sprites.insert(xSpritePair);
	return xSprite; //returnera den nya spriten

};