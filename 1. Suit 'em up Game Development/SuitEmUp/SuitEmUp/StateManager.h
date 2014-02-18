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
	//hoppas att det inte är jobbigt att jag lägger kommentarer här och där
	void Attach(State * state);
	void SetState(const std::string &type);
	void ChangeState();

	//void UpdateTime(float deltatime);
	void HandleEvents();
	void Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/);

	bool Running() { return m_running; }
	void Quit() { m_running = false; }
	void SetInput(InputManager *input);
	Engine *engine;
private:
	std::vector<State*> states;
	State* current;
	bool m_running;
	//ladbon
	InputManager *m_input;


};