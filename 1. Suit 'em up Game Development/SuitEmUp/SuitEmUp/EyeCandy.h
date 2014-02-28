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

	void ParticleCreator(char* p_type, sf::Vector2f p_position);
	void PictureCreator(sf::Sprite* p_sprite, sf::Vector2f p_position);

	void Update(float deltatime);
	void DrawParticles(float deltatime, sf::RenderWindow* renderwindow);

	void PictureDestroyer();
	void ParticleDestroyer();

private:
	struct Particle{
		float m_duration;
		sf::Vector2f m_direction;
		sf::Vector2f m_position;
		float m_speed;
	};

	int count;

	sf::Vector2f m_startpos;
	sf::Vector2f m_destination;
	std::string m_type;
	int m_amount;
	std::vector<sf::Sprite*> m_pictures;
	std::vector<Particle*> m_particles;
	sf::Vertex* m_vertices;
	//float<*>
	float m_distance;
	
};