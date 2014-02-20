//Score.h

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class Button;

class PlayerObject;

class Score
{
public:

	Score();
	~Score(){};
	int GetScore();
	void PutInScore(int enemykillscore);
	void BuyEquipment(Button *xbutton);
	sf::Text DrawScore();
	
private:
	int m_score;
	sf::Text score;
	sf::Font font;
};

