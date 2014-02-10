#pragma once

#include "Button.h"
#include "InputManager.h"

class InputManager;

class ButtonManager
{
public:
	ButtonManager();
	void CreateButton(std::string p_Output, sf::Sprite* p_Sprite);
	bool Update();
	void Cleanup();

private:
	InputManager *m_input;


	//buttons
	Button* m_Button_Play;

};