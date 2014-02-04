//DrawManager.cpp

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "DrawManager.h"
#include "Sprite.h"

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
void DrawManager::Draw(Sprite *m_sprite, int m_x, int m_y, int m_w, int m_h)
{
	//int iW = m_sprite->m_w;
	//int iH = m_sprite->m_h;
	if(m_w != 0 && m_h != 0)
	{
	//	iW = m_w;
	//	iH = m_h;
	}
	//SDL_Rect src = {p_sprite->m_x,p_sprite->m_y,p_sprite->m_width,p_sprite->m_height};
//	SDL_Rect dst = {p_x,p_y,iWidth,iHeight};
	//SDL_RenderCopy(m_renderer, p_sprite->m_texture, &src, &dst);
}