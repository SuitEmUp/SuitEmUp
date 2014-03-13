#pragma once

#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>
#include "InputManager.h"
#include <SFML\Audio.hpp>

class Popup : public GameObject
{
public:
	Popup(InputManager* p_input, std::string p_PopupName, std::string p_Content, sf::Sprite* p_Sprite, int x_Pos, int y_Pos);
	~Popup();

	void Update();
	void FadeAway();
	void CleanUp(); 
	bool exists();

	bool GetType(){return true;};

private:
	InputManager* m_input;
	std::string m_PopupName;
	std::string m_Content;
	sf::Sprite* m_Sprite;
	sf::Vector2f m_position;
	sf::Vector2f m_movepos;
	int m_fadevalue;
	int m_fadespeed;
	float m_movespeed;
	bool m_willfade;
	bool m_exists;
	float m_timer;

	sf::Sound* m_popsound;
	sf::SoundBuffer* m_buffer;

};