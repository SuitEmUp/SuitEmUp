#include "Animation.h"

Animation::Animation(sf::Sprite *sprite,float frameTime, bool paused, bool looped)
{	

	m_sprite = nullptr;
	

	m_frameTime = 0.0f;
	m_current_frame = 0;
	m_time = 0;

	m_sprite = sprite;
	m_frameTime = frameTime;
	m_paused = paused;
	m_looped = looped ;

	


}

void Animation::addFrame(sf::IntRect rect)
{
	m_animation_frames.push_back(rect);
}

void Animation::setSpriteSheet( sf::Sprite* sprite)
{
	m_sprites.push_back(sprite);
}

sf::Sprite* Animation::getSpriteSheet(int number) 
{
	//return m_sprites.at(number);
	return m_sprite;
}
std::size_t Animation::getSize() 
{
	return m_animation_frames.size();
}
sf::IntRect& Animation::getFrame(std::size_t n) 
{
	return m_animation_frames[n];	
}
void Animation::update(float deltaTime, int number)
{

	// if not paused and we have a valid animation
	if (!m_paused)
	{
		// add delta time
		m_time += deltaTime;

		// if current time is bigger then the frame time advance one frame
		if (m_time >= m_frameTime)
		{
			// reset time, but keep the remainder
			m_time = deltaTime;

			// get next Frame index
			if (m_current_frame + 1 < getSize())
				m_current_frame++;
			else
			{
				// animation has ended
				m_current_frame = 0; // reset to start

				if (!m_looped)
				{
					m_paused = true;
				}

			}

			// set the current frame, not reseting the time
			//m_sprites.at(number)->setTextureRect(m_animation_frames[m_current_frame]);
			m_sprite->setTextureRect(m_animation_frames[m_current_frame]);
		}
	}

}

sf::Sprite* Animation::getCurrentFrame(int number)
{
 	return m_sprite;
	//return m_sprites.at(number);
}

