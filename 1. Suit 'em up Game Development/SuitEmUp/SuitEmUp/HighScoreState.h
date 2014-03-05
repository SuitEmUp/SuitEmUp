//HighScoreState.h

#pragma once

#include "State.h"


class HighScore : public State {
public:

	HighScore(Engine *engine);
	bool Init();
	void Exit();

	bool Update(float deltatime);
	void Draw();
	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	std::string tempName_change;
	Engine* m_engine;
	InputManager *m_input;


};