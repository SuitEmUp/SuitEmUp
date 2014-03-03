//Animation.h



#pragma once 

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Animation
{
public:
	Animation(sf::Sprite *sprite,float frameTime, bool paused, bool looped);

	void update(float deltaTime);
	void addFrame(sf::IntRect rect);
	void setSpriteSheet( sf::Sprite& sprite);
	sf::Sprite* getSpriteSheet() ;
	std::size_t getSize() ;
	sf::IntRect& getFrame(std::size_t n) ;

	sf::Sprite* getCurrentFrame();

	//extragrejer EJ IMPLEMENTERADE

	void setAnimation(const Animation& animation);
    void setFrameTime(float time);
	const Animation* getAnimation() const;
    bool isLooped() const;
    bool isPlaying() const;
    float getFrameTime() const;
    void setFrame(std::size_t newFrame, bool resetTime = true);

private:

	float m_time;
	int m_current_frame;
	float m_frameTime;
	bool m_paused;
	bool m_looped;
	sf::Sprite* m_sprite;
	std::vector<sf::IntRect> m_animation_frames;

	Animation* m_animation;

};