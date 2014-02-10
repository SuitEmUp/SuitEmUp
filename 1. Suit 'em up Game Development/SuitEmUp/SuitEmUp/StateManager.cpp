#include "StateManager.h"
#include "State.h"

StateManager::StateManager(){
	current = nullptr;
	m_running = true;
	m_deltatime  = 0.0f; //Ladbon
};

StateManager::~StateManager() 
{
	auto it = states.begin();
	while(it != states.end())
	{
		delete (*it);
		++it;
	}
};

bool StateManager::Init(const char* title, int width, int height) // enginepekare 
{
	return true;
};

void StateManager::Cleanup()
{
	if(current != nullptr) 
	{
		current->Exit();
		current = nullptr;
	}
	this->Quit();
};

void StateManager::UpdateTime(float DeltaTime)
{
	m_deltatime = DeltaTime; 
};

void StateManager::HandleEvents()
{
	//Input and reactions and stuff

};

void StateManager::Update()
{
	if(current == nullptr) { return; };
	//UpdateTime(m_deltatime);
	if(!current->Update()) {
		ChangeState();
	};
};

void StateManager::Draw(/*sf::RenderWindow *p_window*/)
{
	if(current == nullptr) { return; }
	
	
	current->Draw(/*p_window*/);
	//Window Updates goes here

	//1. clear
	//2. Draw
};

//State Related Methods

void StateManager::Attach(State* state)
{
	states.push_back(state);
};

void StateManager::SetState(const std::string &type)
{
	for(unsigned int i = 0; i < states.size(); i++) {
		if(states[i]->IsType(type)) {
			current = states[i];
			//current->deltatime = 0.0f;
			//current->ticks = 0;
			current->Init();
		}
	}
};

void StateManager::ChangeState()
{
	std::string next = current->Next();
	if(current != nullptr)
	{
		current->Exit();
		current = nullptr;
	}

	if(next.empty()) {this->Cleanup(); return; }

	for(unsigned int i = 0; i < states.size(); i++)
	{
		if(states[i]->IsType(next)) {
			current = states[i];
			//current->deltatime = 0.0f;
			//current->ticks = 0;
			current->Init();
		}
	}
};
void StateManager::SetInput(InputManager *input)
{
	m_input = input;

}

