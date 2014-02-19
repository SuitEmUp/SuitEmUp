
//SFML
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

//Important stuff
#include "Utils.h"
#include "Config.h"
#include "Engine.h"

//Managers
#include "StateManager.h"

//States
#include "MainMenu.h"
#include "Options.h"
#include "Customize.h"



int main()
{
	Config::parseFile("../config.txt");
	Engine suitengine;

	if(suitengine.Initialize())
	{
		suitengine.Run();
	}
	suitengine.Cleanup();
	return EXIT_SUCCESS;
}