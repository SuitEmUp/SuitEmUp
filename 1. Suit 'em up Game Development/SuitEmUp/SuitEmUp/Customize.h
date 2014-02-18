#pragma once

#include <vector>
#include "State.h"

#include "Button.h"
#include "SpriteManager.h"
#include "GameObjectManager.h"


namespace sf{
	class RectangleShape;
	class RenderWindow;
}
class InputManager;

class Customize : public State {
public:
<<<<<<< HEAD
	Customize(Engine *engine);
	bool Init();
=======
<<<<<<< HEAD
	Customize(InputManager* input, GameObjectManager* gom);
	bool Init();
=======
	Customize(InputManager* input, Engine *engine);
	bool Init(Engine *engine);
>>>>>>> 5ff85ee799fbfebce5ebe69859d48c834abc72e4
>>>>>>> cd4987c04e00677ea80ba874e4a1270b05829907
	void Exit();

	//bool HandleInput();
	bool Update(float deltatime);
	void Draw(/*sf::RenderWindow *p_window*/);
	std::string Next();
	void setNextState(std::string state);
	bool IsType(const std::string &type);

private:
	std::string next_state;
	Engine *m_engine;
	InputManager *m_input;
	std::string tempName_change;
	std::vector<sf::RectangleShape*> m_rects;

	std::vector<Button*> m_CutomizeButtons;
	GameObjectManager* m_gom;
};