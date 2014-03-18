//Score.cpp

#include "Score.h"
#include <iostream>
#include <ostream>
#include <sstream>

Score::	Score()
{
	m_score = 800000; 

	if (!font.loadFromFile("../assets/fonts/Viking_n.ttf"))
	{ printf("Could not load font\n"); }

	score.setFont(font);
	score.setCharacterSize(25);
	score.setColor(sf::Color::Black);
	score.move(1030.f, 0.f);	
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
void Score::BuyEquipment(int buyequipment)
{
	m_score -= buyequipment;
}
sf::Text Score::DrawScore()
{
	score.setColor(sf::Color::Black);
	std::ostringstream ss;
	ss << "Score: " << GetScore();
	score.setString( ss.str());
	return score;
}
sf::Text Score::FeedbackScore(int enemykillscore)
{
	std::ostringstream ss;
	ss << enemykillscore;
	score.setString( ss.str());
	score.setColor(sf::Color::Yellow);
	return score;
}
sf::Text Score::DrawWhenDead()
{
	score.setColor(sf::Color::Black);
	score.setCharacterSize(20);
	score.setPosition(150.f, 100.f);
	std::ostringstream ss;
	ss << "\t\t\t\t\t\t\tYou have lost your truck\n \t\tyou have been left defenseless against the bandits.\n \t\t\t\t\t\t\t\tYour Score: " << GetScore();
	score.setString( ss.str());
	return score;
}