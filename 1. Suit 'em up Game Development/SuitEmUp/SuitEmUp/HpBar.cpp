//HpBar.cpp

#include "HpBar.h"
#include "Config.h"

HpBar::HpBar(sf::Sprite *hpbar, sf::Sprite *hpsprite, sf::Sprite *hpshadow)
{

	m_sprite = hpbar;
	hp = hpsprite;
	shadow = hpshadow;
	m_sprite->setOrigin(((m_sprite->getLocalBounds().width)/2),((m_sprite->getLocalBounds().height)/2));
	m_sprite->setPosition((Config::getInt("window_w", 0)/2), ((Config::getInt("window_h", 0)/2) - Config::getInt("hud_padding", 0)));
	
	hp->setOrigin(((m_sprite->getLocalBounds().width)/2),((m_sprite->getLocalBounds().height)/2));
	hp->setPosition((Config::getInt("window_w", 0)/2), ((Config::getInt("window_h", 0)/2) - Config::getInt("hud_padding", 0)));

	
	
	shadow->setOrigin(((m_sprite->getLocalBounds().width)/2),((m_sprite->getLocalBounds().height)/2));
	shadow->setPosition((Config::getInt("window_w", 0)/2), ((Config::getInt("window_h", 0)/2) - Config::getInt("hud_padding", 0)));
}
HpBar::~HpBar()
{
	m_sprite = nullptr;
	shadow = nullptr;
}
sf::Sprite *HpBar::Sprite2()
{
	return hp;
}
sf::Sprite *HpBar::Sprite3()
{
	return shadow;
}
bool HpBar::GetType()
{
	return true;
} 
