#pragma once
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <string>

class Button : public GameObject
{
public:
	Button(/*std::string p_nextState,*/ sf::Sprite* p_Sprite, int x_Pos, int y_Pos);

	bool Update(/*deltatime*/);

	bool GetType(){ return true;};

private:
	//std::string m_nextState;

};