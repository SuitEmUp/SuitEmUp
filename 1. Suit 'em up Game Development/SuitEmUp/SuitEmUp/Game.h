#pragma once

#include <vector>
#include "State.h"

namespace sf{
	class RenderWindow;
}

class InputManager;
class GameObjectManager;

class Game : public State {
public:
	Game(InputManager *input, Engine *engine);
	bool Init(Engine *engine);
	void Exit();

	bool Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/);

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	Engine *m_engine;
	std::string next_state;
	InputManager *m_input;
	std::string tempName_change;
	GameObjectManager* m_gom;
};