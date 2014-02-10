#include "Button.h"	

Button::Button(std::string p_Output, sf::Sprite* p_Sprite)
{
	m_output = p_Output;
	m_sprite = p_Sprite;
};

bool Button::Update(/*deltatime*/)
{

	return true;
};

std::string Button::GetOutput()
{
	return m_output;
};