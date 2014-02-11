#include "Button.h"	

Button::Button(/*std::string p_nextState,*/ sf::Sprite* p_Sprite, int x_Pos, int y_Pos)
{
	//m_nextState = p_nextState;
	m_sprite = p_Sprite;
	m_position = sf::Vector2f(x_Pos, y_Pos);
	m_sprite->setPosition(m_position);
};
