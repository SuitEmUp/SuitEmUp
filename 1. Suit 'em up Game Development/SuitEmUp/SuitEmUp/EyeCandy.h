// EyeCandy.h

#pragma once

#include <vector>
#include <string>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class Particles;
class SpriteManager;
class Animation;

struct Picture{
	float duration;
	//Animation* ani;
	sf::Sprite* picture;
};

struct Particle{
	float m_duration;
	sf::Vector2f m_direction;
	sf::Vector2f m_position;
	sf::Vector2f m_destination;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_aacceleration;
	sf::Vector2f m_aaacceleration;
	float m_speed;
};

class EyeCandy{
public:

	EyeCandy(float degree);
	~EyeCandy();

	void ShockCreator(sf::Vector2f p_position);
	void BloodCreator(char* p_type, sf::Vector2f p_position, sf::Vector2f p_direction);
	void PictureCreator(sf::Sprite* p_sprite, sf::Vector2f p_position, float p_rotation);

	void BoomWoshCreator(sf::Vector2f p_position, sf::Vector2f p_destination);
	void TextCreator(sf::Text p_text, sf::Vector2f p_position);

	void Update(float deltatime);
	void DrawParticles(float deltatime, sf::RenderWindow* renderwindow);
	void DrawPictures(float deltatime, sf::RenderWindow* renderwindow);

	void PictureDestroyer();
	void ParticleDestroyer();

private:



	int count;

	sf::Vector2f m_startpos;
	sf::Vector2f m_destination;
	std::string m_type;
	int m_amount;
	std::vector<Picture*> m_animations;
	std::vector<Particle*> m_particles;
	std::vector<Particle*> m_shocks;
	std::vector<sf::RectangleShape*> m_rectangles;
	std::vector<Particle*> m_boomwoshticles;
	std::vector<sf::RectangleShape*> m_recticles;
	std::vector<sf::RectangleShape*> m_squares;
	//float<*>
	float m_distance;

	float m_degree;
	//text
	struct Text{
		float duration_text;
		sf::Text texts;
	};


	std::vector<Text> m_texts;

};