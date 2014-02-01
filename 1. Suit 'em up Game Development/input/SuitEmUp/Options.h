#pragma once

#include <vector>
#include "State.h"

class Options : public State {
public:
	Options();
	bool Init();
	void Exit();

	bool Update();
	//draw

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;

	std::string tempName_change;
	


};