#pragma once

#include <vector>
#include "State.h"
#include "Button.h"
#include "SpriteManager.h"
#include "GameObjectManager.h"

#include "SFML\Audio.hpp"

namespace sf{
	class RenderWindow;
}

class InputManager;

class MainMenu : public State {
public:
	MainMenu(Engine *engine);
	bool Init();
	void Exit();

	bool Update(float deltatime);
	void Draw();

	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	InputManager *m_input;
	std::string tempName_change;
	Engine *m_engine;
	std::vector<Button*> m_Buttons;

	sf::Sprite* m_logo;
	sf::Sprite* m_glow1;
	sf::Sprite* m_glow2;
	sf::Sprite* m_glow3;
	sf::Sprite* m_glow4;

	sf::Sprite* m_Tutorial;

	bool m_ShowTutorial;

	bool m_reset;
	int m_codecount;
	bool m_showREALTITLE;

	bool m_canclick;
	bool m_oneclicklock;

	int m_morepushdown;

	sf::Sprite *m_xbackground;
	Animation *m_fire;
	sf::Sprite *m_fire_sprite;
};