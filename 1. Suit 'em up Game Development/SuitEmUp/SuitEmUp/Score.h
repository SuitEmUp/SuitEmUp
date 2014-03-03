//Score.h

#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

class PlayerObject;

class Score
{
public:

	Score();
	~Score(){};
	int GetScore();
	void PutInScore(int enemykillscore);
	void BuyEquipment(int enemykillscore);
	sf::Text DrawScore();
	sf::Text DrawWhenDead();
	
private:
	int m_score;
	sf::Text score;
	sf::Font font;

};

