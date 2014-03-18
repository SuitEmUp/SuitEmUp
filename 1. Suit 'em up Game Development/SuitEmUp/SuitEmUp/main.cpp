
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

	Engine *suitengine = new Engine();

	Config::set("current_suit", "0");
	Config::set("current_weapon", "0");
	Config::set("current_truck", "0");
	Config::set("weapons_available", "1");
	Config::set("currentsuitcost", "1000");
	Config::set("currentweaponcost", "2000");
	Config::set("currenttruckcost", "1500");
	Config::renew();
	//Engine suitengine;


	if(suitengine->Initialize())
	{
		suitengine->Run();
	}

	suitengine->Cleanup();
	return EXIT_SUCCESS;
}