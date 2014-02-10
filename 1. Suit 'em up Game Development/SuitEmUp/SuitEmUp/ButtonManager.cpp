#include "ButtonManager.h"
#include "Button.h"



ButtonManager::ButtonManager(SpriteManager* m_spritemanager, InputManager *input)
{
	m_vButtons.clear();
};

void ButtonManager::CreateButton(std::string p_Output, sf::Sprite* p_Sprite)
{
		m_vButtons.push_back(new Button("Bajs", m_spritemanager->Load("../data/sprites/virveltuss.png", "Test", 0.3, 0.3)));


};

bool ButtonManager::Update()
{


	//if (m_input->Mouse_isDownOnce /*&& collision med rätt knapp && p_Output == MainMenu*/)
	//{
	//	//setNextState
	//	return false;
	//}
	//if (m_input->Mouse_isDownOnce /*&& collision med rätt knapp && p_Output == MainMenu*/)
	//{
	//	//setNextState
	//	return false;
	//}

	return true;
};

void ButtonManager::Cleanup()
{

};
