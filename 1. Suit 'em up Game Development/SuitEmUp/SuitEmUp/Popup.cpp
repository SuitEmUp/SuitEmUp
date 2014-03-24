#include "Popup.h"



Popup::Popup(InputManager* p_input, std::string p_PopupName, std::string p_Content, sf::Sprite* p_Sprite, int x_Pos, int y_Pos)
{
	m_movespeed = 40;
	m_input = p_input;
	m_PopupName = p_PopupName;
	m_Content = p_Content;
	m_sprite = p_Sprite;
	m_position = sf::Vector2f(x_Pos, y_Pos);
	m_movepos.x = 1280 + m_sprite->getLocalBounds().width;
	m_movepos.y = m_position.y;
	m_sprite->setPosition(m_position);
	m_fadevalue = 255;
	m_fadespeed = 40;
	m_willfade = false;
	printf("Popup Created\n");
	m_exists = true;

	m_timer = 250;
};

Popup::~Popup()
{
	CleanUp();
};

void Popup::Update()
{
	if(m_movepos.x > m_position.x)
	{
		m_movepos.x -= m_movespeed;
		m_sprite->setPosition(m_movepos);
		//if(m_movepos.x < m_position.x)
			//m_sprite->setPosition(m_position);
	}
	else //if(m_movepos.x == m_position.x)
	{
		m_sprite->setPosition(m_position);
	}

	if(m_input->GetMousePos().x > m_position.x && m_input->GetMousePos().x < m_position.x + m_sprite->getLocalBounds().width)
	{
		if(m_input->GetMousePos().y > m_position.y && m_input->GetMousePos().y < m_position.y + m_sprite->getLocalBounds().height)
		{
			if(m_input->Mouse_isDownOnce(sf::Mouse::Button::Right))
			{
				printf("Popup Clicked!\n");
				m_willfade = true;

			}

			//m_sprite == annan sprite
		}
	}
	m_timer -= 1;
	if(m_timer < 0)
	{
		m_willfade = true;
	}

	if(m_willfade)
	{
		FadeAway();

	}
	//	m_Sprite->setPosition(m_position);
};

void Popup::FadeAway()
{
	m_position += sf::Vector2f(1.0f, 2.0f);
	if(m_fadevalue < (255/3)*2)
		m_position += sf::Vector2f(1.0f, 2.0f);
	if(m_fadevalue < 255/3)
		m_position += sf::Vector2f(1.0f, 2.0f);



	m_fadevalue -= m_fadespeed;
	m_sprite->setColor(sf::Color(255, 255, 255, m_fadevalue));

	if (m_fadevalue < 0 ){{
		m_willfade = false;
		m_exists = false;
		//CleanUp();

	}
	}

};

bool Popup::exists()
{
	return m_exists;
}

void Popup::CleanUp()
{
	m_Sprite = nullptr;
	//delete m_buffer;
	//m_buffer = nullptr;
	//delete m_popsound;
	//m_popsound = nullptr;

	//if(m_buffer != nullptr)
	//	printf("Failet to delete m_buffer");
	//if(m_Sprite != nullptr)
	//	printf("Failet to delete m_Sprite");
};





