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
	void BoomWoshCreator(sf::Vector2f p_position, sf::Vector2i p_destination);

	void Update(float deltatime);
	void DrawEyeCandy(float deltatime, sf::RenderWindow* renderwindow);

	void PictureDestroyer();
	void ParticleDestroyer();

private:
	struct Particle{
		float m_duration;
		sf::Vector2f m_direction;
		sf::Vector2f m_position;
		sf::Vector2i m_destination;
		sf::Vector2f m_velocity;
		sf::Vector2f m_acceleration;
		sf::Vector2f m_aacceleration;
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
	std::vector<Particle*> m_boomwoshticles;
	std::vector<sf::RectangleShape*> m_recticles;
	//float<*>
	float m_distance;
	
};