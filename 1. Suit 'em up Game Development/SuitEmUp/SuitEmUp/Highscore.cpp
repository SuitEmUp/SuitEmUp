//Highscore.cpp

#include "Highscore.h"
#include <fstream>
#include <iostream>


Highscore::Highscore()
{

}
Highscore::~Highscore()
{

}
void Highscore::Arrange_Highscore(std::vector<S_Highscores*> &vector)
{
	for(int x=0; x<vector.size(); x++)
	{
		for(int y=0; y<vector.size()-1; y++)
		{
			if(vector[y+1]->score > vector[y]->score)
			{
				S_Highscores *temp = vector[y+1];
				vector[y+1] = vector[y];
				vector[y] = temp;
			}
		}
	}
}
void Highscore::Save()
{
	std::ofstream save;//skapa ostream

	save.open("../Highscore.txt", std::ofstream::out | std::ofstream::trunc);

	if(!save.is_open())
	{
		return;
	}

	for(int x=0;x<Size();x++)
	{
		if(x >= Size()-1)
		{ 
			save << m_highScores.at(x)->name << " " << m_highScores.at(x)->score << " " << m_highScores.at(x)->kills;
		}
		else 
		{
			save << m_highScores.at(x)->name << " " << m_highScores.at(x)->score << " " << m_highScores.at(x)->kills << "\n";
		}
	}

	Arrange_Highscore(m_highScores);

	save.close();
}
void Highscore::Load()
{
	std::ifstream load;
	/*std::string line;*/


	//first iteration throughout the whole document
	load.open("../Highscore.txt");

	if(!load.is_open())
	{
		return;
	}

	while(!load.eof())
	{
		S_Highscores *m_score;
		m_score = new S_Highscores;
		load >> m_score->name >> m_score->score >> m_score->kills;
		if(m_score->score < 0)
		{
			delete m_score;
			m_score = nullptr;
		}
		Push_Back(m_score);
	}

	Arrange_Highscore(m_highScores);

	load.close();
}
S_Highscores* Highscore::Getdata(int index)
{
	Arrange_Highscore(m_highScores);
	return m_highScores.at(index);
}
int Highscore::Size()
{
	//std::cout << "SIZE: " << m_highScores.size() << std::endl;
	return m_highScores.size(); 
}
void Highscore::Push_Back(S_Highscores *temp)
{
	m_highScores.push_back(temp);
	Arrange_Highscore(m_highScores);
}
/*
1. Datat måste läsas in från highscore.txt (load())
2. Spara datat lokalt - ligger i medlemsvariabler(Load() o arrange())
3. Lägga till ett nytt highscore(läggas till, jämföras med andra highscore och sorteras in)(save() arrange())
4. Spara lokala datat till highscore.txt(save())
*/


