#pragma once
#include <vector>

class State;
class InputManager;

namespace sf{
	class RenderWindow;
}

class StateManager
{
	friend class Engine;
public:
	StateManager();
	~StateManager();

	bool Init(const char* title, int width, int height);
	void Cleanup();

	void Attach(State * state);
	void SetState(const std::string &type);
	void ChangeState();

	void UpdateTime(float deltatime);
	void HandleEvents();
	void Update();
	void Draw(sf::RenderWindow *p_window);

	bool Running() { return m_running; }
	void Quit() { m_running = false; }
		void SetInput(InputManager *input);
private:
	std::vector<State*> states;
	State* current;
	bool m_running;
//ladbon
	InputManager *m_input;
	unsigned int iTicks();
	float m_deltatime;

};