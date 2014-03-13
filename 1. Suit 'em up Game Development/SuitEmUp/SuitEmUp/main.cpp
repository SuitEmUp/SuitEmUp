
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
<<<<<<< HEAD
	Engine *suitengine = new Engine();
=======
	Config::set("current_suit", "0");
	Config::set("current_weapon", "0");
	Config::set("current_truck", "0");
	Config::set("weapons_available", "1");
	Config::renew();
	Engine suitengine;
>>>>>>> e464993c68810020295f52dc934f30a498fb8a53

	if(suitengine->Initialize())
	{
		suitengine->Run();
	}

	suitengine->Cleanup();
	return EXIT_SUCCESS;
}