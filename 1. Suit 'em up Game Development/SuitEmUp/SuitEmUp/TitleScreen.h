#pragma once

#include <vector>
#include "State.h"
#include "SpriteManager.h"
#include "GameObjectManager.h"

namespace sf{
	class RenderWindow;
}

class InputManager;

class TitleScreen : public State {
public:
	TitleScreen(InputManager *input, GameObjectManager* gom);
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
	InputManager *m_input;
	std::string tempName_change;


	GameObjectManager* m_gom;

	sf::Sprite* m_background;
	


};