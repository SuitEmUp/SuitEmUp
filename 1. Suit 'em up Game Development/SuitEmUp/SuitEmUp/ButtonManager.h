#pragma once

#include "Button.h"
#include "InputManager.h"

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class InputManager;

class ButtonManager
{
public:
	ButtonManager(SpriteManager* spritemanager, InputManager *input);
	void CreateButton(std::string p_Output, sf::Sprite* p_Sprite);
	bool Update();
	void Cleanup();

private:
	


	//buttons
	std::vector<Button*> m_vButtons;

	SpriteManager* m_spritemanager;
	InputManager* m_inputmanager;

};