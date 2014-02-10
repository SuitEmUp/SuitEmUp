#pragma once

#include <vector>
#include "State.h"

namespace sf{
	class RenderWindow;
}

class InputManager;

class TitleScreen : public State {
public:
	TitleScreen(InputManager *input);
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
	


};