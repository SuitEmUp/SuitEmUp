//Score.cpp

#include "Score.h"
#include <iostream>
#include <ostream>
#include <sstream>

Score::	Score()
{
	m_score = 0; 

	if (!font.loadFromFile("../assets/fonts/Viking_n.ttf"))
	{ printf("Could not load font\n"); }

	score.setFont(font);
	score.setCharacterSize(25);
	score.setColor(sf::Color::Black);
	score.move(1050.f, 0.f);	
	score.setStyle(sf::Text::Bold);

}
int Score::GetScore()
{
	return m_score;
}
void Score::PutInScore(int enemykillscore)
{
	m_score += enemykillscore;
}
void Score::BuyEquipment(Button *xbutton)
{

}
sf::Text Score::DrawScore()
{
	std::ostringstream ss;
	ss << "Score: " << GetScore();
	score.setString( ss.str());
	return score;
}