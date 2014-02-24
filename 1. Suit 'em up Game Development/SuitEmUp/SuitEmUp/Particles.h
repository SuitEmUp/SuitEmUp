// Particles.h

#pragma once
#include <SFML\Window.hpp>

class Particles{
public:
	Particles(sf::Vector2f* p_direction, sf::Vector2f* p_position);
	~Particles();

	void GetVertices(int i); // For drawing them
	bool Update(float deltatime);

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;

	int m_particles;
	float m_duration;
	int speed;
	//Vector of vertices

};