//HighScoreState.h

#pragma once

#include "State.h"
#include "Score.h"
#include "Highscore.h"
#include <ostream>
#include <sstream>
#include "Button.h"
#include "Config.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


namespace sf{
	class RectangleShape;
	class RenderWindow;
}

class HighScoreState : public State {
public:

	HighScoreState(Engine *engine);
	bool Init();
	void Exit();

	bool Update(float deltatime);
	void Draw();
	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:

	//S_Highscores *Scores;
	Highscore *m_highscore;
	float index;

	std::string next_state;
	std::string tempName_change;
	Engine* m_engine;
	InputManager *m_input;

	sf::Sprite *m_background;
	sf::Text* text;
	sf::Font *font;

	std::vector<sf::Text*>Texts;

	// buttons

	std::vector<sf::RectangleShape*> m_rects;
	std::vector<Button*> m_xbuttons;
	sf::Sprite* m_glow1;

	
};