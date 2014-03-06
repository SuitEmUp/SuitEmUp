#pragma once
#include <vector>

class State;
class InputManager;

namespace sf{
	class RenderWindow;
}

class StateManager
{

public:
	StateManager();
	~StateManager();

	bool Init(const char* title, int width, int height);
	void Cleanup();

	void Attach(State * state);
	void SetState(const std::string &type);
	void ChangeState();


	void HandleEvents();
	void Update(float deltatime);
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	
private:
	std::vector<State*> states;
	State* current;
	bool m_running;
	InputManager *m_input;


};