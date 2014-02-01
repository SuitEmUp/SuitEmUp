#pragma once

#include <vector>
#include "State.h"


namespace sf{
	class RectangleShape;
}


class Customize : public State {
public:
	Customize();
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
	
	std::vector<sf::RectangleShape*> m_rects;

};