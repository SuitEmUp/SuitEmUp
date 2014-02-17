#pragma once

#include <string>
#include "Engine.h"
class InputManager;

namespace sf{
	class RenderWindow;
}

class State
{
public:
	virtual ~State() {};
	
	virtual bool Init(Engine*) = 0;
	virtual void Exit() = 0;

	//virtual bool HandleInput() = 0;
	virtual bool Update(float deltatime) = 0;
	virtual void Draw(/*sf::RenderWindow *p_window*/) = 0;

	virtual std::string Next() = 0;
	virtual void setNextState(std::string state) = 0;
	virtual bool IsType(const std::string &type) = 0;

	//unsigned int ticks;

	//static InputManager* m_InputManager;

};