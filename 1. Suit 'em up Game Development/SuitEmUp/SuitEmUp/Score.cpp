//Score.cpp

#include "Score.h"


Score::	Score(sf::Sprite *m_Score, sf::Text *score)
{
	sf::Font font;
	if (!font.loadFromFile("../assets/fonts/AdobeGothicStd-Bold")) { printf("Could not load font\n"); }
	sf::Text text;
	text.setFont(font);
	text.setString("Is this working?");
	text.setCharacterSize(24);
	text.setColor(sf::Color::Red);
}