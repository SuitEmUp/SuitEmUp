#pragma once

#include <vector>
#include "State.h"
#include "SpriteManager.h"
#include "GameObjectManager.h"

namespace sf{
	class RenderWindow;
}
class InputManager;


class Options : public State {
public:
	Options(Engine* engine);
	bool Init();
	void Exit();

	//bool HandleInput();
	bool Update(float deltatime);
	void Draw();

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	Engine *m_engine;
	InputManager *m_input;
	std::string next_state;
	std::string tempName_change;

	sf::Sprite *m_background;
};