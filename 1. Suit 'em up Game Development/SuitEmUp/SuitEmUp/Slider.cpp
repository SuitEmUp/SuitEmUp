#include "Slider.h"
#include "InputManager.h"
#include "SpriteManager.h"

Slider::Slider(SpriteManager* p_sm)
{
	m_position = sf::Vector2f(1080/2, 720/2);

	m_level = m_position.x;

	m_sliderposition = sf::Vector2f(100, 50);
	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);
	m_sprite->setPosition(m_position);
	m_slider->setOrigin(m_slider->getLocalBounds().width/2, m_slider->getLocalBounds().height/2);
	m_slider->setPosition(m_sliderposition);

}


Slider::~Slider()
{
	m_sprite = nullptr;
	m_slider = nullptr;
}

void Slider::Update(InputManager* p_input)
{
	if(p_input->Mouse_isDown(sf::Mouse::Left)){
		if(p_input->GetMousePos().x > m_sliderposition.x - (m_slider->getLocalBounds().width/2) && p_input->GetMousePos().x < m_sliderposition.x + (m_slider->getLocalBounds().width/2)
		&& p_input->GetMousePos().y > m_sliderposition.y + (m_slider->getLocalBounds().width/2) && p_input->GetMousePos().y < m_sliderposition.y - (m_slider->getLocalBounds().width/2)
		){
			m_grabbed = true;
		};
	}
	if(!p_input->Mouse_isDown(sf::Mouse::Left)){
		m_grabbed = false;
	}
	if(m_grabbed){
		m_position.x = p_input->GetMousePos().x;
	}
	if(m_position.x < m_sliderposition.x - (m_slider->getLocalBounds().width/2)){
		m_position.x = m_sliderposition.x - (m_slider->getLocalBounds().width/2);
	}
	if(m_position.x > m_sliderposition.x + (m_slider->getLocalBounds().width/2)){
		m_position.x = m_sliderposition.x + (m_slider->getLocalBounds().width/2);
	}

	m_level = m_position.x - (m_sliderposition.x - m_slider->getLocalBounds().width/2);

	m_sprite->setPosition(m_position);
};

float Slider::GetLevel(){
	return m_level;
};