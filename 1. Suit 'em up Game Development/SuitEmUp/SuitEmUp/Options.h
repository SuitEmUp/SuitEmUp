#pragma once

#include <vector>
#include "State.h"

namespace sf{
	class RenderWindow;
}
class InputManager;


class Options : public State {
public:
	Options(InputManager *input, Engine* engine);
	bool Init(Engine*);
	void Exit();

	//bool HandleInput();
	bool Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/){};

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	Engine* m_engine;
	GameObjectManager* m_gom;
	std::string next_state;
	InputManager* m_input;
	std::string tempName_change;

};