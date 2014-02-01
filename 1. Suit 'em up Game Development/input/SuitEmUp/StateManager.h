#pragma once
#include <vector>

class State;
class InputManager;

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

	void UpdateTime(float DeltaTime);
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }
	void SetInput(InputManager *input);
private:
	std::vector<State*> states;
	State* current;
	bool m_running;
	InputManager *m_input;
	unsigned int iTicks();
	float m_deltatime;
};