//PausState.h

#pragma once

#include "State.h"
#include "GameObjectManager.h"

#include "Button.h"
#include "SpriteManager.h"
#include "Config.h"

namespace sf{
	class RectangleShape;
	class RenderWindow;
}

class InputManager;

class PausState : public State {
public:
	PausState(Engine* engine);
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
	std::string tempName_change;
	Engine* m_engine;
	InputManager *m_input;
    //bool paused;
	sf::Sprite *m_vbackground;

	//buttons

	std::vector<sf::RectangleShape*> m_rects;
	std::vector<Button*> m_buttons;
};