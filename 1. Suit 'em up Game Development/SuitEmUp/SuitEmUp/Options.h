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

<<<<<<< HEAD
	//bool HandleInput(); <-- wat do dis meen?
	bool Update();
=======
	//bool HandleInput();
	bool Update(float deltatime);
>>>>>>> 4ebd3bf781b51e63cdfc1bfa1c6c2df1ed1be169
	void Draw(/*sf::RenderWindow *p_window*/){};

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	InputManager* m_input;
	std::string tempName_change;
	
};