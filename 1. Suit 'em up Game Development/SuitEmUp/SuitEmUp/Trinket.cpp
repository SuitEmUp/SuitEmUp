#include "Trinket.h"	

Trinket::Trinket(std::string p_TrinketType, int p_TrinketMode,  sf::Sprite* p_Sprite, int x_Pos, int y_Pos)
{
	//m_nextState = p_nextState;
	m_sprite = p_Sprite;
	m_position = sf::Vector2f(x_Pos, y_Pos);
	m_sprite->setPosition(m_position);


	m_Type = p_TrinketType;
	m_Mode = p_TrinketMode;

	m_sprite->setOrigin(m_sprite->getLocalBounds().width / 2, m_sprite->getLocalBounds().height / 2);
};


std::string Trinket::Update()
{
return "bajs";	
};

std::string Trinket::GetType2()
{
	return m_Type;
};

int Trinket::GetMode()
{
	return m_Mode;
};

sf::Vector2f Trinket::GetPos()
{
	return m_position;
};