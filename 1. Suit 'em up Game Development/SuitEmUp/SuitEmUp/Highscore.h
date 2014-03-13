//Highscore.h

#pragma once

#include <fstream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


struct S_Highscores
{ 
	std::string name; 
	int score;  
	int kills; 
};
class Highscore
{
public:

	Highscore();
	~Highscore();
	void Arrange_Highscore(std::vector<S_Highscores*> &vector);
	void Save();
	void Load();
	void Push_Back(S_Highscores *temp);

	S_Highscores* Getdata(int index);
	
	int Size();

private:

	std::vector<S_Highscores*> m_highScores;

	std::fstream m_highscore;

};