#pragma once

#include <vector>
#include "State.h"

namespace sf{
	class RenderWindow;
}
class InputManager;


class Options : public State {
public:
	Options();
	Options(InputManager * input);
	bool Init();
	void Exit();



	//bool HandleInput(); <-- wat do dis meen?
	bool Update();


	//bool HandleInput(); <-- wat do dis meen?


	//bool HandleInput();
	bool Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/){};

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	InputManager* m_input;
	std::string tempName_change;
	
};