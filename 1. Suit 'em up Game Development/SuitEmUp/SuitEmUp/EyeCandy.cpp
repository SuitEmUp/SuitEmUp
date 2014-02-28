// EyeCandy.cpp

#include "EyeCandy.h"
#include "SpriteManager.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

EyeCandy::EyeCandy()
{
	m_vertices = new sf::Vertex[4000];
};
EyeCandy::~EyeCandy()
{

	delete[] m_vertices;

};



void EyeCandy::ParticleCreator(char* p_type, sf::Vector2f p_position){
	for(int i = 0; i<1000; i++){
		Particle* partickel = new Particle;

		partickel->m_direction = sf::Vector2f(1, 2);
		partickel->m_position = p_position;
		partickel->m_speed = 50;
		partickel->m_duration = 10;

		m_particles.push_back(partickel);	
		m_vertices;
	};

};
void EyeCandy::PictureCreator(sf::Sprite* p_sprite, sf::Vector2f p_position)
{
	//sf::Sprite* t_sprite = p_sprite;
	//t_sprite->setPosition(p_position);
	//t_sprite->setOrigin(t_sprite->getLocalBounds().width/2, t_sprite->getLocalBounds().height/2);
	//m_pictures.push_back(t_sprite);
	//int* duration = new int;
	//*duration = 1;
	//m_picturetimer.push_back(duration);
};

void EyeCandy::Update(float deltatime){
	for(int i = 0; i<m_particles.size(); i++){
		m_particles.at(i)->m_duration -= deltatime;
		m_particles.at(i)->m_position += m_particles.at(i)->m_speed * m_particles.at(i)->m_direction * deltatime;
	};
};

void EyeCandy::DrawParticles(float deltatime, sf::RenderWindow* renderwindow){
	for(int i = 0; i<4000; i++){
		m_vertices[i].position = m_particles.at(i)->m_position;
		m_vertices[i].color = sf::Color::Red;
	};
	
};

void EyeCandy::PictureDestroyer(){};

void EyeCandy::ParticleDestroyer(){};