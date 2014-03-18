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
	sf::Sprite* m_decal;

	sf::Sprite* m_smallupgrade1;
	sf::Sprite* m_smallupgrade2;
	sf::Sprite* m_bigupgrade;
	sf::Sprite* m_leftbutton;
	sf::Sprite* m_rightbutton;
	sf::Sprite* m_back;
	/*sf::RectangleShape* m_suitrect;
	sf::RectangleShape* m_weaponrect;
	sf::RectangleShape* m_truckrect;*/

	sf::Font* m_foont;
	sf::Text* m_suitcostText;
	sf::Text* m_weaponcostText;
	sf::Text* m_truckcostText;

	std::string m_currentsuitcost;
	std::string m_currentweaponcost;
	std::string m_currenttruckcost;

	int m_currentSuit;
	int m_currentWeapon;
	int m_currentTruck;

	int counts;

	bool m_trinketboxactivator;
	bool m_trinketboxlock;
	sf::Sprite* m_trinketboxsprite;

	int howmuchitcosts_suit;
	int howmuchitcosts_weapon;
	int howmuchitcosts_truck;
	int howmuchitcosts_trinket;
	int howmuchmoneyihave;

	int m_weapons_available;
	bool m_pauselock;

	//text i mitten

	sf::Text *m_stats;
	sf::Font *m_font;
	std::string items[9];
	std::string m_currentweapon;
	std::string m_currentsuit;
	std::string m_currenttruck;
	int once;

};