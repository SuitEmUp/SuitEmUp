// EyeCandy.cpp

#include "EyeCandy.h"
#include "SpriteManager.h"
#include "Animation.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

EyeCandy::EyeCandy(float degree)
{
	m_recticles.clear();
	m_rectangles.clear();
	m_degree = degree/100;
	srand(time(0));
};
EyeCandy::~EyeCandy()
{
	for (auto it = m_particles.begin();it != m_particles.end(); it++)
	{
		if(*it != nullptr) {
			delete *it;
		}
	}
	m_particles.clear();
	for (auto it = m_rectangles.begin();it != m_rectangles.end(); it++)
	{
		if(*it != nullptr) {
			delete *it;
		}
	}
	m_rectangles.clear();
	for (auto it = m_shocks.begin();it != m_shocks.end(); it++)
	{
		if(*it != nullptr) {
			delete *it;
		}
	}
	m_shocks.clear();
	for (auto it = m_squares.begin();it != m_squares.end(); it++)
	{
		if(*it != nullptr) {
			delete *it;
		}
	}
	m_squares.clear();
	for (auto it = m_boomwoshticles.begin();it != m_boomwoshticles.end(); it++)
	{
		if(*it != nullptr) {
			delete *it;
		}
	}
	m_boomwoshticles.clear();
	for (auto it = m_recticles.begin();it != m_recticles.end(); it++)
	{
		if(*it != nullptr) {
			delete *it;
		}
	}
	m_recticles.clear();
	for (auto it = m_animations.begin();it != m_animations.end(); it++)
	{
		if(*it != nullptr) {
			delete *it;
		}
	}
	m_animations.clear();
	for(int i = 0; i<m_texts.size(); i++){

		m_texts.erase(m_texts.begin()+i);
		i--;
		if(i<0) i=0;
	}
	m_texts.clear();
};
void EyeCandy::BloodCreator(char* p_type, sf::Vector2f p_position, sf::Vector2f p_direction){
	//int r = ((rand()%(255-1+1))+1);
	//int g = ((rand()%(255-1+1))+1);
	//int b = ((rand()%(255-1+1))+1);


	//for(int i = 0; i<(rand()%(150-100+1))+100; i++){
	//	Particle* partickel = new Particle;

	//	int randomm = ((rand()%(50000000-1+1))+1)*3.14/180;

	//	partickel->m_direction = sf::Vector2f(sin(randomm)/10+(p_direction.x)/-500, cos(randomm)/10+(p_direction.y)/-500);


	//	partickel->m_position = p_position;
	//	partickel->m_speed = (rand()%(200-100+1))+100;
	//	partickel->m_duration = 0.005*((rand()%(200-100+1))+1);

	//	m_particles.push_back(partickel);	

	//	sf::RectangleShape* rect = new sf::RectangleShape;
	//	rect->setPosition(p_position);
	//	rect->setSize(sf::Vector2f(5, 5));
	//	/*int r = ((rand()%(255-1+1))+1);
	//	int g = ((rand()%(255-1+1))+1);
	//	int b = ((rand()%(255-1+1))+1);*/
	//	rect->setFillColor(sf::Color::Red/*(r, g, b,200)*/);

	//	m_rectangles.push_back(rect);
	//};
	int highest = 200*m_degree;
	int lowest = 150*m_degree;

	for(int i = 0; i<(rand()%(highest-lowest+1))+lowest; i++){
		Particle* partickel = new Particle;
		int randomm = ((rand()%(5000-1+1))+1)*3.14/180;

		partickel->m_direction = sf::Vector2f(sin(randomm)+(p_direction.x)/-500, cos(randomm)+(p_direction.y)/-500);

		partickel->m_position = p_position;
		partickel->m_speed = -((rand()%(400-50+1))+50);
		partickel->m_duration = 0.005*((rand()%(200-100+1))+1);

		m_particles.push_back(partickel);	

		sf::RectangleShape* rect = new sf::RectangleShape;
		rect->setPosition(p_position);
		rect->setSize(sf::Vector2f(2, 2));
		rect->setFillColor(sf::Color::Red);

		m_rectangles.push_back(rect);
	};
};
void EyeCandy::ShockCreator(sf::Vector2f p_position){

	int highest = 100*m_degree;
	int lowest = 50*m_degree;

	for(int i = 0; i<(rand()%(highest-lowest+1))+lowest; i++){
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
			rect->setFillColor(sf::Color(255, 30, 200, 0xff));
		}
		else if (randomm == 1){
			rect->setFillColor(sf::Color::White);
		};

		m_squares.push_back(rect);
	};

};
void EyeCandy::PictureCreator(sf::Sprite* p_sprite, sf::Vector2f p_position, float p_rotation)
{
	/*Picture* t_picture= new Picture();
	p_sprite->setRotation(p_rotation);
	p_sprite->setPosition(p_position);
	p_sprite->setOrigin(79/2, 81/2);
	t_picture->sprite = p_sprite;
	t_picture->duration = 2;
	t_picture->ani = new Animation(t_picture->sprite, 0.1, false, true);
	t_picture->ani->addFrame(sf::IntRect (0, 0, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (79+5, 0, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (158+10, 0, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (237+15, 0, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (316+20, 0, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (395+25, 0, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (474+30, 0, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (553+35, 0, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (0, 81+5, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (79+5, 81+5, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (158+10, 81+5, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (237+15, 81+5, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (316+20, 81+5, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (395+25, 81+5, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (474+30, 81+5, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (553+35, 81+5, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (0, 162+10, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (79+5, 162+10, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (158+10, 162+10, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (237+15, 162+10, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (316+20, 162+10, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (395+25, 162+10, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (474+30, 162+10, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (553+35, 162+10, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (0, 243+15, 79, 81));
	t_picture->ani->addFrame(sf::IntRect (79+5, 243+15, 79, 81));
	t_picture->ani->setSpriteSheet(t_picture->sprite);

	t_picture->ani->update(0.32, 1);


	t_picture->sprite = t_picture->ani->getCurrentFrame(20);
	m_animations.push_back(t_picture);*/

	Picture* t_picture= new Picture();
	t_picture->duration = 6;
	t_picture->picture = p_sprite;
	t_picture->picture->setPosition(p_position);
	t_picture->picture->setOrigin(t_picture->picture->getLocalBounds().width/4, t_picture->picture->getLocalBounds().height*0.8);
	t_picture->picture->setRotation(p_rotation +70);
	m_animations.push_back(t_picture);

};
void EyeCandy::BoomWoshCreator(sf::Vector2f p_position, sf::Vector2f p_destination)
{

	int highest = 200*m_degree;
	int lowest = 100*m_degree;

	for(int i = 0; i<(rand()%(highest-lowest+1))+lowest; i++){
		Particle* partickel = new Particle;
		int randomm = ((rand()%(50000000-1+1))+1)*3.14/180;

		partickel->m_aacceleration = sf::Vector2f(0, 0);
		partickel->m_acceleration = sf::Vector2f(0, 0);

		partickel->m_direction = sf::Vector2f(sin(randomm), cos(randomm));
		partickel->m_destination = p_destination;

		partickel->m_position = p_position;
		partickel->m_speed = ((rand()%(15-10+1))+10);
		partickel->m_velocity = partickel->m_direction * partickel->m_speed;
		partickel->m_duration = 3;

		m_boomwoshticles.push_back(partickel);	

		int r = ((rand()%(255-1+1))+1);
		int g = ((rand()%(255-1+1))+1);
		int b = ((rand()%(255-1+1))+1);

		sf::RectangleShape* rect = new sf::RectangleShape;
		rect->setPosition(p_position);
		rect->setSize(sf::Vector2f(4, 4));
		rect->setFillColor(sf::Color(r, g, b));

		m_recticles.push_back(rect);
	};

};
void EyeCandy::Update(float deltatime){

	for(int i = 0; i<m_texts.size(); i++){
		m_texts.at(i).duration_text -= deltatime;
		if(m_texts.at(i).duration_text < 0){
			m_texts.erase(m_texts.begin()+i);
			i--;
			//if(i<0) i=0;
		}
	}
	for(int i = 0; i<m_particles.size(); i++){
		m_particles.at(i)->m_duration -= deltatime;
		m_particles.at(i)->m_position += m_particles.at(i)->m_speed * m_particles.at(i)->m_direction * deltatime;

		m_particles.at(i)->m_speed *= 0.9f;

		if(m_particles.at(i)->m_duration < 0){
			m_particles.erase(m_particles.begin()+i);
			m_rectangles.erase(m_rectangles.begin()+i);
			i--;
			//if(i<0) i=0;
		}
	};

	for(int i = 0; i<m_boomwoshticles.size(); i++){
		m_boomwoshticles.at(i)->m_duration -= deltatime;

		float deltaX = m_boomwoshticles.at(i)->m_position.x - m_boomwoshticles.at(i)->m_destination.x;
		float deltaY = m_boomwoshticles.at(i)->m_position.y - m_boomwoshticles.at(i)->m_destination.y;
		float distance = sqrt((deltaX*deltaX)+(deltaY*deltaY))*2;

		m_boomwoshticles.at(i)->m_aaacceleration += sf::Vector2f(-(deltaX/distance)/1000, -(deltaY/distance)/1000);

		/*m_boomwoshticles.at(i)->m_aacceleration.x *= 1.01;
		m_boomwoshticles.at(i)->m_aacceleration.y *= 1.01;*/
		m_boomwoshticles.at(i)->m_aacceleration += m_boomwoshticles.at(i)->m_aaacceleration;

		m_boomwoshticles.at(i)->m_acceleration += m_boomwoshticles.at(i)->m_aacceleration;

		m_boomwoshticles.at(i)->m_velocity += m_boomwoshticles.at(i)->m_acceleration;

		m_boomwoshticles.at(i)->m_velocity.x *= 0.8; 
		m_boomwoshticles.at(i)->m_velocity.y *= 0.8;

		m_boomwoshticles.at(i)->m_position += m_boomwoshticles.at(i)->m_velocity;

		if(m_boomwoshticles.at(i)->m_duration < 0 || distance < 100){
			m_boomwoshticles.erase(m_boomwoshticles.begin()+i);
			m_recticles.erase(m_recticles.begin()+i);
		}
	}

	for(int i = 0; i<m_shocks.size(); i++){
		m_shocks.at(i)->m_duration -= deltatime;
		m_shocks.at(i)->m_position += m_shocks.at(i)->m_speed * m_shocks.at(i)->m_direction * deltatime;

		if(m_shocks.at(i)->m_duration < 0){
			m_shocks.erase(m_shocks.begin()+i);
			m_squares.erase(m_squares.begin()+i);
			i--;
			//if(i<0) i=0;
		}
	};
	for(int i = 0; i<m_animations.size(); i++){
		m_animations.at(i)->duration -= deltatime;
		m_animations.at(i)->picture->setColor(sf::Color(255, 255, 255, 42.5 * m_animations.at(i)->duration));
		if(m_animations.at(i)->duration < 0){
			delete m_animations.at(i);
			m_animations.at(i) = nullptr;
			m_animations.erase(m_animations.begin()+i);
			i--;
			//if(i<0) i=0;
		}
	};

};
void EyeCandy::DrawParticles(float deltatime, sf::RenderWindow* renderwindow){
	for(int i = 0; i<m_particles.size(); i++){
		m_rectangles.at(i)->setPosition(m_particles.at(i)->m_position);
		renderwindow->draw(*m_rectangles.at(i));
		m_rectangles.at(i)->setScale(m_rectangles.at(i)->getScale().x * 0.9, m_rectangles.at(i)->getScale().y * 0.9);
	};

	for(int i = 0; i<m_boomwoshticles.size(); i++){
		m_recticles.at(i)->setPosition(m_boomwoshticles.at(i)->m_position);
		renderwindow->draw(*m_recticles.at(i));
	}

	for(int i = 0; i<m_squares.size(); i++){
		m_squares.at(i)->setPosition(m_shocks.at(i)->m_position);
		renderwindow->draw(*m_squares.at(i));
		m_squares.at(i)->setScale(m_squares.at(i)->getScale().x * 0.9, m_squares.at(i)->getScale().y * 0.9);
	};
	for(int i = 0; i<m_texts.size(); i++){
		renderwindow->draw(m_texts.at(i).texts);
	}
};
void EyeCandy::DrawPictures(float deltatime, sf::RenderWindow* renderwindow){
	for(int i = 0; i<m_animations.size(); i++){
		renderwindow->draw(*m_animations.at(i)->picture);

	};
};
void EyeCandy::PictureDestroyer(){};
void EyeCandy::ParticleDestroyer(){};

void EyeCandy::TextCreator(sf::Text p_text, sf::Vector2f p_position)
{
	Text t_text;
	t_text.duration_text = 2;

	t_text.duration_text = 1;

	t_text.texts = p_text;
	t_text.texts.setPosition(p_position);
	t_text.texts.setOrigin(t_text.texts.getLocalBounds().width/4, t_text.texts.getLocalBounds().height*0.8);
	m_texts.push_back(t_text);
};
