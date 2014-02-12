#pragma once

#include <vector>
#include "State.h"

namespace sf{
	class RenderWindow;
}
class InputManager;


class Options : public State {
public:
	Options(InputManager * input);
	bool Init();
	void Exit();

<<<<<<< HEAD


	//bool HandleInput(); <-- wat do dis meen?
	bool Update();


	//bool HandleInput(); <-- wat do dis meen?


=======
>>>>>>> 74270ce1bf8ce92b7400633a84bf0e92b78e1d34
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