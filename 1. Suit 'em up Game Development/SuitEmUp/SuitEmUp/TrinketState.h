#pragma once

#include "State.h"

class TrinketState : public State
{
public:
	TrinketState(Engine *engine);
	bool Init();
	void Exit();

	//bool HandleInput();
	bool Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/);
	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);


private:
	std::string next_state;
	Engine *m_engine;
};