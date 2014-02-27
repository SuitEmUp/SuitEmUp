// EyeCandy.cpp

#include "EyeCandy.h"

EyeCandy::EyeCandy(){
	//m_vertices->setPrimitiveType(sf::Points);
};
EyeCandy::~EyeCandy(){};



void EyeCandy::ParticleCreator(std::string* p_type, sf::Vector2f p_position){
	for(int i = 0; i<5; i++){
		m_particles.push_back(new Particle);
	};
	
	m_vertices.push_back(sf::VertexArray(sf::Points, 5));

	for(int i = 0; i<m_particles.size(); i++){
		//m_particles.at(0)->m_duration =
		m_particles.at(0)->m_position = p_position;
		//m_particles.at(0)->m_direction = ...
		//m_particles.at(0)->m_speed = ...
	};
};
void EyeCandy::PictureCreator(sf::Vector2f p_position){

};

void EyeCandy::Update(float deltatime){
	for(int i = 0; i<m_particles.size(); i++){
		m_particles.at(i)->m_duration -= deltatime;
		m_particles.at(i)->m_position += m_particles.at(i)->m_speed * m_particles.at(i)->m_direction * deltatime;
	};
};
void EyeCandy::DrawParticles(float deltatime, sf::RenderWindow* renderwindow){
	for(int i; i<m_vertices.size(); i++){
		renderwindow->draw(m_vertices.at(i));
	};
};

void EyeCandy::PictureDestroyer(){};
void EyeCandy::ParticleDestroyer(){};