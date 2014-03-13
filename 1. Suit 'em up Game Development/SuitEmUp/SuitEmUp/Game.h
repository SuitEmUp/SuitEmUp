#pragma once

#include <vector>
#include "State.h"
#include "Popup.h"

namespace sf{
	class RenderWindow;
}
class InputManager;

class Game : public State {
public:
	Game(Engine *engine);
	bool Init();
	void Exit();

	bool Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/);

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	Engine *m_engine;
	InputManager *m_input;
	std::string next_state;
	std::string tempName_change;
	int paused;
	float m_deltatime;
	int m_score;
	bool popuplock;
	bool onepopuplock;

	Popup* m_popup;
};