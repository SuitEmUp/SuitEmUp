#pragma once

#include <vector>
#include "State.h"
#include "SpriteManager.h"
#include "GameObjectManager.h"

namespace sf{
	class RenderWindow;
}

class InputManager;

class TitleScreen : public State {
public:
	TitleScreen(Engine* engine);
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
	sf::Text start_game;
	sf::Font font;
	sf::Sprite *m_xbackground;
	sf::Sprite* m_TitleLogo;
	bool m_CanGoToMain;
	float m_blackfade;
	float m_titlefade;

	sf::RectangleShape* Black;

	int m_blTimer;
	int m_tiTimer;
	Animation *m_fire;
	sf::Sprite *m_fire_sprite;


};