#pragma once

#include <vector>
#include "State.h"
#include "Button.h"
#include "SpriteManager.h"

namespace sf{
	class RenderWindow;
}

class InputManager;

class MainMenu : public State {
public:
	MainMenu(InputManager *input);
	bool Init();
	void Exit();

	//bool HandleInput();
	bool Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/){};

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	InputManager *m_input;
	std::string tempName_change;
	
	std::vector<Button*> m_Buttons;
	SpriteManager* m_spritemanager;


};