
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Game.h"



Game::Game(InputManager* input)
{
	next_state = "";
};

bool Game::Init()
{
	printf("State: Game,      Initialized\n");

	return true;
};

void Game::Exit(){};

//bool Game::HandleInput()
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//	{
//		setNextState("");
//		return false;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
//	{
//		setNextState("Options");
//		return false;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
//	{
//		setNextState("Customize");
//		return false;
//	}
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
//	{
//		setNextState("Game");
//		return false;
//	}
//	return true;
//};

bool Game::Update()
{
	return true;
};

//draw stuff

std::string Game::Next()
{
	return next_state;
};

void Game::setNextState(std::string state)
{
	next_state = state;
};

bool Game::IsType(const std::string &type)
{
	return type.compare("Game") == 0;
};