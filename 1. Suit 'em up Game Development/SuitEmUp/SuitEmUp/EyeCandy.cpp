// EyeCandy.cpp

#include "EyeCandy.h"
#include "SpriteManager.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

EyeCandy::EyeCandy()
{
	m_rectangles.clear();
	srand(time(0));
};
EyeCandy::~EyeCandy()
{

	

};

void EyeCandy::BloodCreator(char* p_type, sf::Vector2f p_position, sf::Vector2f p_direction){
	for(int i = 0; i<(rand()%(50-30+1))+30; i++){
		Particle* partickel = new Particle;
		int randomm = ((rand()%(5000-1+1))+1)*3.14/180;
		
		partickel->m_direction = sf::Vector2f(sin(randomm)+(p_direction.x)/1000, cos(randomm)+(p_direction.y)/1000);

		partickel->m_position = p_position;
		partickel->m_speed = (rand()%(200-50+1))+50;
		partickel->m_duration = 0.005*((rand()%(200-100+1))+1);

		m_particles.push_back(partickel);	

		sf::RectangleShape* rect = new sf::RectangleShape;
		rect->setPosition(p_position);
		rect->setSize(sf::Vector2f(5, 5));
		rect->setFillColor(sf::Color::Red);

		m_rectangles.push_back(rect);
	};
	for(int i = 0; i<(rand()%(50-30+1))+30; i++){
		Particle* partickel = new Particle;
		int randomm = ((rand()%(5000-1+1))+1)*3.14/180;
		
		partickel->m_direction = sf::Vector2f(sin(randomm)+(p_direction.x)/500, cos(randomm)+(p_direction.y)/500);

		partickel->m_position = p_position;
		partickel->m_speed = -((rand()%(200-50+1))+50);
		partickel->m_duration = 0.005*((rand()%(200-100+1))+1);

		m_particles.push_back(partickel);	

		sf::RectangleShape* rect = new sf::RectangleShape;
		rect->setPosition(p_position);
		rect->setSize(sf::Vector2f(5, 5));
		rect->setFillColor(sf::Color::Red);

		m_rectangles.push_back(rect);
	};
};

void EyeCandy::ShockCreator(sf::Vector2f p_position){
	for(int i = 0; i<(rand()%(150-100+1))+100; i++){
		Particle* partickel = new Particle;
		int randomm = ((rand()%(5000-1+1))+1)*3.14/180;
		
		partickel->m_direction = sf::Vector2f(sin(randomm), cos(randomm));

		partickel->m_position = p_position;
		partickel->m_speed = (rand()%(200-50+1))+50;
		partickel->m_duration = 0.1*((rand()%(200-100+1))+1);

		m_shocks.push_back(partickel);	

		sf::RectangleShape* rect = new sf::RectangleShape;
		rect->setPosition(p_position);
		rect->setSize(sf::Vector2f(5, 5));
		randomm = (rand()%(2));
		if(randomm == 0){
			rect->setFillColor(sf::Color::Blue);
		}
		else if (randomm == 1){
			rect->setFillColor(sf::Color::White);
		};

		m_squares.push_back(rect);
	};
	
};

void EyeCandy::PictureCreator(sf::Sprite* p_sprite, sf::Vector2f p_position, float p_rotation)
{
	Picture* t_picture= new Picture();
	t_picture->duration = 6;
	t_picture->picture = p_sprite;
	t_picture->picture->setPosition(p_position);
	t_picture->picture->setOrigin(t_picture->picture->getLocalBounds().width/4, t_picture->picture->getLocalBounds().height*0.8);
	t_picture->picture->setRotation(p_rotation+50);
	m_pictures.push_back(t_picture);
};

void EyeCandy::Update(float deltatime){
	for(int i = 0; i<m_particles.size(); i++){
		m_particles.at(i)->m_duration -= deltatime;
		m_particles.at(i)->m_position += m_particles.at(i)->m_speed * m_particles.at(i)->m_direction * deltatime;
		
		if(m_particles.at(i)->m_duration < 0){
			m_particles.erase(m_particles.begin()+i);
			m_rectangles.erase(m_rectangles.begin()+i);
			i--;
			if(i<0) i=0;
		}
	};
	for(int i = 0; i<m_shocks.size(); i++){
		m_shocks.at(i)->m_duration -= deltatime;
		m_shocks.at(i)->m_position += m_shocks.at(i)->m_speed * m_shocks.at(i)->m_direction * deltatime;
		
		if(m_shocks.at(i)->m_duration < 0){
			m_shocks.erase(m_shocks.begin()+i);
			m_squares.erase(m_squares.begin()+i);
			i--;
			if(i<0) i=0;
		}
	};
};

void EyeCandy::DrawEyeCandy(float deltatime, sf::RenderWindow* renderwindow){
	for(int i = 0; i<m_particles.size(); i++){
		m_rectangles.at(i)->setPosition(m_particles.at(i)->m_position);
		renderwindow->draw(*m_rectangles.at(i));
		m_rectangles.at(i)->setScale(m_rectangles.at(i)->getScale().x * 0.9, m_rectangles.at(i)->getScale().y * 0.9);
	};
	for(int i = 0; i<m_squares.size(); i++){
		m_squares.at(i)->setPosition(m_shocks.at(i)->m_position);
		renderwindow->draw(*m_squares.at(i));
		m_squares.at(i)->setScale(m_squares.at(i)->getScale().x * 0.9, m_squares.at(i)->getScale().y * 0.9);
	};
	for(int i = 0; i<m_pictures.size(); i++){
		renderwindow->draw(*m_pictures.at(i)->picture);
		m_pictures.at(i)->duration -= deltatime;
		if(m_pictures.at(i)->duration < 0){
			m_pictures.erase(m_pictures.begin()+i);
			i--;
			if(i<0) i=0;
		}
	};
	for(int i = 0; i<m_texts.size(); i++){
		renderwindow->draw(m_texts.at(i).texts);
		m_texts.at(i).duration_text -= deltatime;
		if(m_texts.at(i).duration_text < 0){
			m_texts.erase(m_texts.begin()+i);
			i--;
			if(i<0) i=0;
		}
	}
};
void EyeCandy::PictureDestroyer(){};
void EyeCandy::ParticleDestroyer(){};
void EyeCandy::TextCreator(sf::Text p_text, sf::Vector2f p_position)
{
	Text t_text;
	t_text.duration_text = 3;
	t_text.texts = p_text;
	t_text.texts.setPosition(p_position);
	t_text.texts.setOrigin(t_text.texts.getLocalBounds().width/4, t_text.texts.getLocalBounds().height*0.8);
	m_texts.push_back(t_text);
};
