// EyeCandy.h

#pragma once

#include <vector>
#include <string>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class Particles;
class Picture;
class SpriteManager;

class EyeCandy{
public:

	EyeCandy();
	~EyeCandy();

	void BloodCreator(char* p_type, sf::Vector2f p_position, sf::Vector2f p_direction);
	void PictureCreator(sf::Sprite* p_sprite, sf::Vector2f p_position, float p_rotation);

	void Update(float deltatime);
	void DrawEyeCandy(float deltatime, sf::RenderWindow* renderwindow);

	void PictureDestroyer();
	void ParticleDestroyer();

private:
	struct Particle{
		float m_duration;
		sf::Vector2f m_direction;
		sf::Vector2f m_position;
		float m_speed;
	};

	struct Picture{
		float duration;
		sf::Sprite* picture;
	};

	int count;

	sf::Vector2f m_startpos;
	sf::Vector2f m_destination;
	std::string m_type;
	int m_amount;
	std::vector<Picture*> m_pictures;
	std::vector<Particle*> m_particles;
	std::vector<sf::RectangleShape*> m_rectangles;
	//float<*>
	float m_distance;
	
};