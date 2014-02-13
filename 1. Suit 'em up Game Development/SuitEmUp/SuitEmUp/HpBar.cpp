//HpBar.cpp

#include "HpBar.h"

HpBar::HpBar(sf::Sprite *hpbar, sf::Sprite *hpsprite)
{

	m_sprite = hpbar;
	hp = hpsprite;
	m_sprite->setOrigin((m_sprite->getLocalBounds().height)/2, (m_sprite->getLocalBounds().width)/2);
	m_sprite->setPosition(25,710);
	hp->setOrigin((m_sprite->getLocalBounds().height)/2, (m_sprite->getLocalBounds().width)/2);
	hp->setPosition(25,710);
}
HpBar::~HpBar()
{

}
sf::Sprite *HpBar::Sprite2()
{
	return hp;
}
bool HpBar::GetType()
{
	return true;
}