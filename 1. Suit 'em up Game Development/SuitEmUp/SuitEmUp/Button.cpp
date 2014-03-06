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

	m_buffer1 = new sf::SoundBuffer();
	m_buffer1->loadFromFile("../data/sounds/buttons/jarredgibb_02.wav");
	m_buffer2 = new sf::SoundBuffer();
	m_buffer2->loadFromFile("../data/sounds/buttons/jarredgibb_03.wav");
	m_buffer3 = new sf::SoundBuffer();
	m_buffer3->loadFromFile("../data/sounds/buttons/jarredgibb_04.wav");
	m_buffer4 = new sf::SoundBuffer();
	m_buffer4->loadFromFile("../data/sounds/buttons/jarredgibb_05.wav");

	m_clicksound = new sf::Sound();
	m_clicksound->setBuffer(*m_buffer1);
	m_clicksound->setVolume(200);
	m_clicksound->setPitch(2);
};

Button::~Button()
{
	delete m_buffer1;
	m_buffer1 = nullptr;
	if(m_buffer1 != nullptr)
		printf("Failet to delete m_buffer1");

	delete m_buffer2;
	m_buffer2 = nullptr;
	if(m_buffer2 != nullptr)
		printf("Failet to delete m_buffer2");

	delete m_buffer2;
	m_buffer2 = nullptr;
	if(m_buffer3 != nullptr)
		printf("Failet to delete m_buffer3");

	delete m_buffer2;
	m_buffer2 = nullptr;
	if(m_buffer4 != nullptr)
		printf("Failet to delete m_buffer4");

	delete m_clicksound;
	m_clicksound = nullptr;
	if(m_clicksound != nullptr)
		printf("Failet to delete m_clicksound");

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
							m_clicksound->setBuffer(*m_buffer1);
						}
						if(randomm == 2)
						{
							m_clicksound->setBuffer(*m_buffer2);
						}
						if(randomm == 3)
						{
							m_clicksound->setBuffer(*m_buffer3);
						}
						if(randomm == 4)
						{
							m_clicksound->setBuffer(*m_buffer4);
						}
						m_clicksound->play();
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