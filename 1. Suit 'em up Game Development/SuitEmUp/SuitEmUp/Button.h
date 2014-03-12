#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>
#include "InputManager.h"
#include <SFML\Audio.hpp>

class Button : public GameObject
{
public:
	Button(InputManager* p_input, std::string p_ButtonName, std::string p_shape, sf::Sprite* p_Sprite, int x_Pos, int y_Pos);
	~Button();

	std::string Update();

	bool GetType(){return true;};

	std::string GetType2();
	
	std::string GetPreviousState();

private:
	std::string m_Type;
	std::string m_Shape;
	InputManager* m_input;

	std::string m_current;
	std::string m_previous;

	sf::Sound* m_PressedSound;
	sf::Sound* m_clicksound;
	sf::SoundBuffer* m_buffer1;
	sf::SoundBuffer* m_buffer2;
	sf::SoundBuffer* m_buffer3;
	sf::SoundBuffer* m_buffer4;
	sf::SoundBuffer* m_pressedbuffer;


};