//#include "ParticleEffects.h"
////This code obviously doesnt work but it shows what I want to do at least
//
//ParticleEffects::ParticleEffects()
//{
//
//};
//
//void ParticleEffects::CreateParticles(sf::Vector2f p_startpos, sf::Vector2f p_destination, float p_duration, std::string p_type, int p_amount)
//{
//	m_startpos = p_startpos;
//	m_destination = p_destination;
//	m_duration = p_duration;
//	m_type = p_type;
//	m_amount = p_amount;	
//	m_distance = sqrt(((m_startpos.x - m_destination.x)*(m_startpos.x - m_destination.x))+((m_startpos.y - m_destination.y)*(m_startpos.y - m_destination.y)));
//
//	if (m_type == "BoomWosh")
//	{
//		for (int i = 0; i < m_amount; i++)
//		{
//			m_particles[i].position = p_startpos;
//			m_particles[i].color == sf::Color::Red;
//
//		}
//	}
//
//};
//
//void ParticleEffects::Update()
//{
//	if (m_type == "BoomWosh")
//	{
//		for (int i = 0; i < m_amount; i++)
//		{
//			if(true/*stage 1*/) //makes the particle shoot in random directions
//			{
//				float speed = (std::rand() % 50) + 50.f;
//				float angle = (std::rand() % 360) * 3.14f / 180.f;
//				m_particles[i].position += sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
//			}
//			if(true/*stage 2*/) //sort of curves the particles against the direction that they are going, need more calculations here, this will do atm
//			{
//				float speed = (std::rand() % 50) + 50.f;
//				float angle = (std::rand() % 360) * 3.14f / 180.f;
//				m_particles[i].position += sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
//				m_particles[i].position += sf::Vector2f(std::cos(m_direction) * speed, std::sin(m_direction) * speed);
//			}
//			if(true/*stage 3*/) //moves the partivles to its destination
//			{
//				float speed = (std::rand() % 50) + 50.f;
//				m_particles[i].position += sf::Vector2f(std::cos(m_direction) * speed, std::sin(m_direction) * speed);
//			}
//		}
//	}
//
//};
//
//void ParticleEffects::Draw()
//{
//	//idk how do draw :(((
//};
//
//void ParticleEffects::Cleanup()
//{
//	for(int i = 0; i < m_particles.size(); i++){
//	//	delete m_vCustomizeButtons.at(i)->GetSprite();
//		delete m_particles[i];
//		m_particles.erase(m_particles.begin()+i);
//		i--;
//	};
//	m_particles.clear();
//};