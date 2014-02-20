#pragma once

#include <vector>
#include "State.h"

#include "Button.h"
#include "SpriteManager.h"


namespace sf{
	class RectangleShape;
	class RenderWindow;
}
class InputManager;

class Customize : public State {
public:
	Customize(Engine *engine);
	bool Init();
	void Exit();

	//bool HandleInput();
	bool Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/);
	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	Engine *m_engine;
	InputManager *m_input;
	std::string tempName_change;
	std::vector<sf::RectangleShape*> m_rects;
	std::vector<Button*> m_CutomizeButtons;

	//backgrounds and stuff
	sf::Sprite* m_border;
	sf::Sprite* m_suit;
	sf::Sprite* m_weapon;
	sf::Sprite* m_truck;
	sf::Sprite* m_statbox;
	sf::Sprite* m_trinketbox;

	int m_currentSuit;
	int m_currentWeapon;
	int m_currentTruck;

	bool m_trinketboxactivator;
	bool m_trinketboxlock;
	sf::Sprite* m_trinketboxsprite;


};