//DieState.h

#pragma once

#include "State.h"
#include "GameObjectManager.h"

#include "Button.h"
#include "SpriteManager.h"
#include "Config.h"
#include "Highscore.h"

namespace sf{
	class RectangleShape;
	class RenderWindow;
}

class InputManager;

class DieState : public State {
public:
	DieState(Engine* engine);
	bool Init();
	void Exit();

	bool Update(float deltatime);
	void Draw();

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	std::string tempName_change;
	Engine* m_engine;
	InputManager *m_input;
	//bool paused;
	sf::Sprite *m_xbackground;

	//buttons

	std::vector<sf::RectangleShape*> m_rects;
	std::vector<Button*> m_xbuttons;

	sf::Sprite* m_glow1;
	sf::Sprite* m_glow2;
	sf::Sprite* m_glow3;
	sf::Sprite* m_glow4;

	//highscore
	sf::Text *m_text;
	sf::Font m_font;
	Highscore *m_highscore;
	S_Highscores *player_score;

	bool once;
};