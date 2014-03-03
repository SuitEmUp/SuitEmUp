//Animation.h



#pragma once 

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Animation
{
public:
	Animation(sf::Sprite *sprite,float frameTime, bool paused, bool looped);

	void update(float deltaTime, int number);
	void addFrame(sf::IntRect rect);
	void setSpriteSheet( sf::Sprite * sprite);
	sf::Sprite* getSpriteSheet(int number) ;
	std::size_t getSize() ;
	sf::IntRect& getFrame(std::size_t n) ;

	sf::Sprite* getCurrentFrame(int number);


	//extragrejer EJ IMPLEMENTERADE

	//void setAnimation(const Animation& animation);
	//void setFrameTime(float time);
	//const Animation* getAnimation() const;
	//bool isLooped() const;
	//bool isPlaying() const;
	//float getFrameTime() const;
	//void setFrame(std::size_t newFrame, bool resetTime = true);

private:

	float m_time;
	float m_frameTime;


	int m_current_frame;

	bool m_paused;
	bool m_looped;

	sf::Sprite *m_sprite;


	std::vector<sf::Sprite*> m_sprites;
	std::vector<sf::IntRect> m_animation_frames;
};