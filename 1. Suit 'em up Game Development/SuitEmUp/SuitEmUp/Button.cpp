#include "Button.h"	

Button::Button(InputManager* p_input, std::string p_ButtonName, std::string p_shape, sf::Sprite* p_Sprite, int x_Pos, int y_Pos)
{
	//m_nextState = p_nextState;
	m_sprite = p_Sprite;
	m_position = sf::Vector2f(x_Pos, y_Pos);
	m_sprite->setPosition(m_position);
	m_input = p_input;

	m_Type = p_ButtonName;
	m_Shape = p_shape;
	if(m_Shape == "Circle")
	{
		m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2, m_sprite->getLocalBounds().height / 2);
	}
};


std::string Button::Update()
{
	if(m_Shape == "Square")
	{
		if(m_input->GetMousePos().x > m_position.x && m_input->GetMousePos().x < m_position.x + m_sprite->getLocalBounds().width)
		{
			if(m_input->GetMousePos().y > m_position.y && m_input->GetMousePos().y < m_position.y + m_sprite->getLocalBounds().height)
			{
				if(m_input->Mouse_isDownOnce(sf::Mouse::Button::Left))
				{
					printf("Button Clicked!\n");
					return "Clicked";
				}
				//m_sprite == annan sprite
			}
		}
	};

	if(m_Shape == "Circle")
	{
		float dx = (m_input->GetMousePos().x - m_position.x);
		float dy = (m_input->GetMousePos().y - m_position.y);

		float hyp = sqrt((dx*dx)+(dy*dy));

		if(hyp <= (m_sprite->getLocalBounds().width)/2)
		{
			if(m_input->Mouse_isDownOnce(sf::Mouse::Button::Left))
			{
				printf("Button Clicked!\n");
				return "Clicked";
			}
		}
	};


	return "bajs";
};

std::string Button::GetType2()
{
	return m_Type;
};