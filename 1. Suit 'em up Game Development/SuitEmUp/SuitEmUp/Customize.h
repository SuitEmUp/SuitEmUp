#pragma once

#include <vector>
#include "State.h"


namespace sf{
	class RectangleShape;
	class RenderWindow;
}
class InputManager;

class Customize : public State {
public:
	Customize(InputManager* input, Engine *engine);
	bool Init(Engine *engine);
	void Exit();

	//bool HandleInput();
	bool Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/);
	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	GameObjectManager *m_gom;
	Engine *m_engine;
	std::string tempName_change;
	InputManager *m_input;
	std::vector<sf::RectangleShape*> m_rects;

};