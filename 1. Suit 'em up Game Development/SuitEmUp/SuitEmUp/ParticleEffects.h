//#pragma once
//
//#include <SFML\Graphics.hpp>
//#include <SFML\Window.hpp>
//#include <vector>
//
//class ParticleEffects
//{
//public:
//	ParticleEffects();
//	
//	void CreateParticles(sf::Vector2f p_startpos, sf::Vector2f p_destination, float p_duration, std::string m_type, int p_amount);
//	void Update();
//	void Draw();
//	void Cleanup();
//
//private:
//	sf::Vector2f m_startpos;
//	sf::Vector2f m_destination;
//	float m_duration;
//	std::string m_type;
//	int m_amount;
//	std::vector<sf::Vertex*> m_particles;
//	float m_distance;
//	float m_direction;
//
//};