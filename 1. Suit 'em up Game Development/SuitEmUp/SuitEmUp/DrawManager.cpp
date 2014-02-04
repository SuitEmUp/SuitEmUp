//DrawManager.cpp

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "DrawManager.h"
#include "Sprite.h"
#include "GameObject.h"

DrawManager::DrawManager()
{
	m_renderer = nullptr;
}
DrawManager::~DrawManager()
{
}
bool DrawManager::initialize(sf::RenderWindow* m_window)
{
	m_renderer = m_window;
	if(m_renderer == nullptr)
	{
		return false;
	}
	return true;
}
void DrawManager::Cleanup()
{
	if(m_renderer != nullptr)
	{
		m_renderer->Window::close();
		m_renderer=nullptr;
	}

}
void DrawManager::Clear()
{
	m_renderer->clear(sf::Color(0x11,0x22,0x33,0xff));

}
void DrawManager::Display()
{
	m_renderer->display();
}
void DrawManager::Draw(std::vector<GameObject*> *m_gameobject)
{
	for (auto object : *m_gameobject)
	{
		//m_renderer->draw( *m_gameobject);
	}
}