#include "Slider.h"
#include "InputManager.h"
#include "SpriteManager.h"

Slider::Slider(SpriteManager* p_sm, std::string type, sf::Vector2f p_position, int level)
{

	m_slider = p_sm->Load("../data/sprites/sliderbase.png", "Slider");
	m_slider->setOrigin(m_slider->getLocalBounds().width/2, m_slider->getLocalBounds().height/2);
	m_slider->setPosition(p_position);

	m_sprite = p_sm->Load("../data/sprites/sliderslider.png", "SliderSlider");
	m_sprite->setOrigin(m_sprite->getLocalBounds().width/2, m_sprite->getLocalBounds().height/2);
	m_sprite->setPosition(p_position);

	m_type = type;

	m_sliderposition = p_position;

	m_position.y = p_position.y;

	float something = m_slider->getLocalBounds().width - 20;

	m_position.x = (m_sliderposition.x-(m_slider->getLocalBounds().width/2))+10+ (level*something)/100;

	m_level = level;

	m_grabbed = false;
}


Slider::~Slider()
{
	m_sprite = nullptr;
	m_slider = nullptr;
}

void Slider::Update(InputManager* p_input)
{

	if(p_input->GetMousePos().x > m_sliderposition.x - ((m_slider->getLocalBounds().width)/2) && p_input->GetMousePos().x < m_sliderposition.x + ((m_slider->getLocalBounds()).width/2)
		){ 
			if(p_input->GetMousePos().y > m_sliderposition.y - ((m_slider->getLocalBounds().height/2)) && p_input->GetMousePos().y < m_sliderposition.y + ((m_slider->getLocalBounds().height/2))
				){
					if(p_input->Mouse_isDownOnce(sf::Mouse::Left))
						m_grabbed = true;
			};
	}
	if(!p_input->Mouse_isDown(sf::Mouse::Left)){
		m_grabbed = false;
	}
	if(m_grabbed){
		m_position.x = p_input->GetMousePos().x;
		if(m_position.x < m_sliderposition.x - ((m_slider->getLocalBounds().width/2) - 10)){
			m_position.x = m_sliderposition.x - ((m_slider->getLocalBounds().width/2) - 10);
		}
		if(m_position.x > m_sliderposition.x + ((m_slider->getLocalBounds().width/2)-10)){
			m_position.x = m_sliderposition.x + ((m_slider->getLocalBounds().width/2)-10);
		}
	}

	float something = m_slider->getLocalBounds().width - 20;
	something/=100;
	m_level = m_position.x - (m_sliderposition.x - (m_slider->getLocalBounds().width/2) + 10);
	m_level/=something;
	m_sprite->setPosition(m_position);
};

float Slider::GetLevel(){
	return m_level;
};

bool Slider::GetType(){
	return true;
};

std::string Slider::GetSliderType(){
	return m_type;
}

sf::Sprite* Slider::GetSliderSprite(){
	return m_slider;
};