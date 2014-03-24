#include "Button.h"	
#include "SoundManager.h"

Button::Button(SoundManager* sm, InputManager* p_input, std::string p_ButtonName, std::string p_shape, sf::Sprite* p_Sprite, int x_Pos, int y_Pos)
{
	m_sm = sm;
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

Button::~Button()
{
	m_sprite = nullptr;
	m_input = nullptr;

};


std::string Button::Update()
{




	m_previous = m_current;
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
				else
				{
					m_current = "Hovering";
					if(m_previous != "Hovering" && m_current == "Hovering")
					{
						int randomm = ((rand()%(4-1+1))+1);
						if(randomm == 1)
						{
							m_sm->PlaySound("buttons/jarredgibb_05.wav");
						}
						if(randomm == 2)
						{
							m_sm->PlaySound("buttons/jarredgibb_02.wav");
						}
						if(randomm == 3)
						{
							m_sm->PlaySound("buttons/jarredgibb_03.wav");
						}
						if(randomm == 4)
						{
							m_sm->PlaySound("buttons/jarredgibb_04.wav");
						}
					}
					m_previous = "Hovering";
					return "Hovering";
				}
				//m_sprite == annan sprite
			}
		}
		m_previous = "bajs";
		m_current = "bajs";

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

std::string Button::GetPreviousState()
{
	return m_previous;
};