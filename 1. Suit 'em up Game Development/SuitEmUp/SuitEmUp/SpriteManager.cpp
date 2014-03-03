#include "SpriteManager.h"
#include "Animation.h"

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

// Faktumet är ju att man absolut inte bör koda med bokstäverna åäö eftersom att inte allas tangentbord har dessa bokstäver

sf::Sprite* SpriteManager::Load(const std::string &filename, const std::string spritename, float x_scale, float y_scale)
{
	auto it = m_Textures.find(filename); //searches for texture
	if(it == m_Textures.end()) //if texture isnt found
	{
		sf::Texture* xTexture = new sf::Texture; //skapa en ny textur

		if(!xTexture->loadFromFile(filename)) // ladda texturen från en fil
			return nullptr;

		std::pair<std::string, sf::Texture*> xTexturePair(filename, xTexture); //lägg in den nya texturen i map'en
		m_Textures.insert(xTexturePair);
		it = m_Textures.find(filename);
	}
	sf::Sprite* xSprite = new sf::Sprite; //skapa en ny sprite
	xSprite->setTexture(*it->second); //sätt spritens textur
	xSprite->setScale(x_scale, y_scale); //sätt scale
	std::pair<std::string,sf::Sprite*>xSpritePair(spritename, xSprite); //lägg in den nya spriten i map'en
	m_Sprites.insert(xSpritePair);
	return xSprite; //returnera den nya spriten

};
/*Animation* SpriteManager::LoadAnimatedSprite(const std::string &xfilename, const std::string xspritename, float frameTime, bool paused, bool looped,
		float x_scale = 1.0, float y_scale = 1.0)
{
		
	auto it = m_Textures.find(xfilename); //searches for texture
	if(it == m_Textures.end()) //if texture isnt found
	{
		sf::Texture* xTexture = new sf::Texture; //skapa en ny textur

		if(!xTexture->loadFromFile(xfilename)) // ladda texturen från en fil
			return nullptr;

		std::pair<std::string, sf::Texture*> xTexturePair(xfilename, xTexture); //lägg in den nya texturen i map'en
		m_Textures.insert(xTexturePair);
		it = m_Textures.find(xfilename);
	}

	sf::Sprite* x_Sprite = new sf::Sprite; //skapa en ny sprite
	x_Sprite->setTexture(*it->second); //sätt spritens textur
	x_Sprite->setScale(x_scale, y_scale); //sätt scale
	std::pair<std::string,sf::Sprite*>xSpritePair(xspritename, x_Sprite); //lägg in den nya spriten i map'en
	m_Sprites.insert(xSpritePair);
	Animation *m_animation = new Animation(x_Sprite, frameTime, paused, looped);
	return m_animation; //returnera den nya spriten

}*/
void SpriteManager::DestroyAnimation()
{

}
