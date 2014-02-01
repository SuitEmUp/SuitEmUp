#pragma once

#include <vector>
#include "State.h"


class InputManager;

class MainMenu : public State {
public:
	MainMenu(InputManager *input);
	bool Init();
	void Exit();

	bool Update();
	//void draw

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	InputManager *m_input;
	std::string tempName_change;
	


};