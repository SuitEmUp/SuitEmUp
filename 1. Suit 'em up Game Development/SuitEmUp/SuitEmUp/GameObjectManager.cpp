//GameObjectManager.cpp

#include "GameObjectManager.h"
#include "GameObject.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "PlayerObject.h"
#include "Truck.h"
#include "EnemyObject.h"
#include "SuperEnemy.h"
#include "Spawner.h"
#include "Button.h"
#include "Config.h"
#include "RepairKit.h"
#include "SniperGirl.h"
#include "Score.h"

#include <iostream>
#include "HpBar.h"


GameObjectManager::GameObjectManager(SpriteManager* sm, sf::RenderWindow* rw, InputManager* input)
{
	m_input = input;
	m_spritemanager=sm;
	m_window=rw;
	m_truck=nullptr;	//Make sure everything is cleared.
	m_player=nullptr;
	m_spawner=nullptr;
	m_backgound=nullptr;
	m_enemies.clear();
	m_supers.clear();
	m_girls.clear();
	m_player_projectiles.clear();
	m_enemy_projectiles.clear();
	m_vRepairKits.clear();
	m_hpbar = nullptr;
	m_xscore = nullptr;

}

GameObjectManager::~GameObjectManager()
{
	//	m_spritemanager=nullptr;
}
void GameObjectManager::CreateGameObjects()
{
	m_backgound = m_spritemanager->Load("../data/sprites/Background.png", "Background", 1, 1);
	m_backgound->setPosition(0,0);
	//Creates all objects that exists from the beginning
	m_truck = new Truck(m_spritemanager->Load("../data/sprites/truck.png", "Truck", 2, 2));
	m_player = new PlayerObject(m_truck, m_input, m_spritemanager->Load("../data/sprites/ArianaSpriteBlack.png", "Ariana", 1, 1),
		m_spritemanager->Load("../data/sprites/ArianaLevel2Sprite.png", "Ariana2", 1, 1));
	m_spawner = new Spawner(m_truck);
	//Clears all vectors
	m_enemies.clear();
	m_supers.clear();
	m_girls.clear();
	m_vRepairKits.clear();
	m_player_projectiles.clear();
	m_enemy_projectiles.clear();
	//The game is not over
	m_game_over = false;
	m_hpbar = new HpBar(m_spritemanager->Load("../data/sprites/HP_Bar_2.png", "hpbar", 1,1),
		(m_spritemanager->Load("../data/sprites/HP_Bar_Border_2.png", "hpborder", 1,1)), 
		(m_spritemanager->Load("../data/sprites/HP_Bar_Shadows_2.png", "hpshadow", 1,1)));
	m_xscore = new Score();
}

void GameObjectManager::ClearGameObjects()
{

	if(m_hpbar != nullptr)
	{
		delete m_hpbar;
		m_hpbar = nullptr;
	}
	//Deletes objects and clears vectors. Sprite deletion is fucked up
	if(m_truck != nullptr){
		//delete m_truck->GetSprite();
		delete m_truck;
		m_truck = nullptr;
	}
	if(m_player != nullptr){
		//delete m_player->GetSprite();
		delete m_player;
		m_player = nullptr;
	}
	if(m_spawner != nullptr){
		delete m_spawner;
		m_spawner = nullptr;
	}
	//DELETES SCORE
	if(m_xscore !=nullptr)
	{
		delete m_xscore;
		m_xscore = nullptr;
	}
	for (auto it = m_enemies.begin();it != m_enemies.end(); it++)
	{
		if(*it != nullptr) {
			//delete (*it)->GetSprite();
			delete *it;
		}

	}
	m_enemies.clear();
	for (auto it = m_supers.begin();it != m_supers.end(); it++)
	{
		if(*it != nullptr) {
			//delete (*it)->GetSprite();
			delete *it;
		}

	}
	m_supers.clear();
	for (auto it = m_girls.begin();it != m_girls.end(); it++)
	{
		if(*it != nullptr) {
			//delete (*it)->GetSprite();
			delete *it;
		}

	}
	m_girls.clear();
	for (auto it = m_enemy_projectiles.begin();it != m_enemy_projectiles.end(); it++)
	{
		if(*it != nullptr) {
			//delete (*it)->GetSprite();
			delete *it;
		}

	}
	m_enemy_projectiles.clear();
	for (auto it = m_player_projectiles.begin();it != m_player_projectiles.end(); it++)
	{
		if(*it != nullptr) {
			//delete (*it)->GetSprite();
			delete *it;
		}

	}
	m_player_projectiles.clear();
	for (auto it = m_vRepairKits.begin();it != m_vRepairKits.end(); it++)
	{
		if(*it != nullptr) {
			//delete (*it)->GetSprite();
			delete *it;
		}

	}
	m_vRepairKits.clear();
}
//Update
void GameObjectManager::Update(float deltatime)
{
	if(m_truck->Update(deltatime)){ //When the truck gets 0 hp it returns true.
		m_game_over = true;
	};
	if(m_player->Update(deltatime)){ 
		//When the player presses the fire-button Update returns true and a player projectile is push_back'd into the playerbullet vector
		m_player_projectiles.push_back(new PlayerProjectile
			(m_truck, m_player, m_spritemanager->Load("../data/sprites/BulletProjectile.png", "PlayerBullet", 0.3, 0.3), 
			m_spritemanager->Load("../data/sprites/BulletProjectileNeedle.png", "PlayerNeedle", 1, 1)));
	}
	if(m_spawner->Timer(deltatime)){ 
		//Keeps track of when enemies spawn
		int c=rand()%10;
		if(c>3) m_enemies.push_back(m_spawner->EnemySpawner(m_spritemanager));
		else if(c<3) m_supers.push_back(m_spawner->SuperSpawner(m_spritemanager));
		else if(c==3) m_girls.push_back(m_spawner->SniperSpawner(m_spritemanager));
	}
	for(int i = 0; i<m_enemies.size(); i++){ 
		//Updates all enemies.
		if(m_enemies.at(i)!=nullptr){
			if(m_enemies.at(i)->Update(deltatime)){ 
				//Update returns true when enemy are close to the truck and their fire-cooldown is 0, 
				//a bullet is pushbacked into the enemybullet vector
				m_enemy_projectiles.push_back(new EnemyProjectile(m_truck, m_enemies.at(i)->GetPosition(),
					m_spritemanager->Load("../data/sprites/BulletProjectile.png", "EnemyBullet", 0.3, 0.3)));
			}
		}
	};

	for(int i = 0; i<m_supers.size(); i++){ 
		//Updates all enemies.
		if(m_supers.at(i)!=nullptr){
			if(m_supers.at(i)->Update(deltatime)){ 
				//Update returns true when enemy are close to the truck and their fire-cooldown is 0, 
				//a bullet is pushbacked into the enemybullet vector
				m_enemy_projectiles.push_back(new EnemyProjectile(m_truck, m_supers.at(i)->GetPosition(),
					m_spritemanager->Load("../data/sprites/BulletProjectile.png", "EnemyBullet", 0.3, 0.3)));
			}
		}
	};
	for(int i = 0; i<m_girls.size(); i++){ 
		//Updates all enemies.
		if(m_girls.at(i)!=nullptr){
			if(m_girls.at(i)->Update(deltatime)){ 
				//Update returns true when enemy are close to the truck and their fire-cooldown is 0, 
				//a bullet is pushbacked into the enemybullet vector
				m_enemy_projectiles.push_back(new EnemyProjectile(m_truck, m_girls.at(i)->GetPosition(),
					m_spritemanager->Load("../data/sprites/BulletProjectile.png", "EnemyBullet", 0.3, 0.3)));
			}
		}
	};


	for(int i = 0; i< m_enemy_projectiles.size(); i++){ 
		//Updates all enemy projectiles. The return true if they collide with the truck. The truck is also damaged.
		if(m_enemy_projectiles.at(i)->Update(m_truck, deltatime)){
			delete m_enemy_projectiles.at(i)->GetSprite();
			m_enemy_projectiles.erase(m_enemy_projectiles.begin()+i);
			i--;
		};
	};


	for(int i = 0; i< m_player_projectiles.size(); i++){
		if(m_player_projectiles.at(i)->Update(m_truck, deltatime)){
			delete m_player_projectiles.at(i)->GetSprite();
			m_player_projectiles.erase(m_player_projectiles.begin()+i);
			i--;
		};
	};

	for(int i = 0; i < m_player_projectiles.size(); i++){

		for(int j = 0; j<m_enemies.size(); j++){

			if(m_spawner->EnemyDestroyer(m_enemies.at(j), m_player_projectiles.at(i))){
				//delete (*it)->GetSprite();
				//delete (*at)->GetSprite();
				m_player_projectiles.erase(m_player_projectiles.begin()+i);
				if(m_enemies.at(j)->Damaged(m_player->GetDamage())<=0){
					

					delete m_enemies.at(j)->GetSprite();

				int chance = rand()%20;
					if(chance == 15)
					{
						m_vRepairKits.push_back(new RepairKit(m_enemies.at(j)->GetPosition(), m_enemies.at(j)->GetVelocity(), 
						m_spritemanager->Load("../data/sprites/ToolBox.png", "Toolbox", 1, 1)));
					}


					m_enemies.erase(m_enemies.begin()+j);
					//SCORE COUNT
					m_xscore->PutInScore(enemyscore = 10);
					--j;
				}
				--i;
				break;
			};
		};
	};

	for(int i = 0; i < m_player_projectiles.size(); i++){
		for(int j = 0; j<m_supers.size(); j++){

			if(m_spawner->SuperDestroyer(m_supers.at(j), m_player_projectiles.at(i))){
				//delete (*it)->GetSprite();
				//delete (*at)->GetSprite();
				delete m_player_projectiles.at(i)->GetSprite();
				m_player_projectiles.erase(m_player_projectiles.begin()+i);
				if(m_supers.at(j)->Damaged(m_player->GetDamage())<=0){
					int chance = rand()%10;
					if(chance == 1)
					{
						m_vRepairKits.push_back(new RepairKit(m_supers.at(j)->GetPosition(), m_supers.at(j)->GetVelocity(), 
							m_spritemanager->Load("../data/sprites/ToolBox.png", "Toolbox", 1, 1)));
					}
					delete m_supers.at(j)->GetSprite();
					m_supers.erase(m_supers.begin()+j);
					
					//SCORE COUNT
					m_xscore->PutInScore(enemyscore = 25);
					--j;
				}
				--i;
				break;
			};

		};
	};
	

	for(int i = 0; i < m_player_projectiles.size(); i++){
		for(int j = 0; j<m_girls.size(); j++){

			if(m_spawner->SniperDestroyer(m_girls.at(j), m_player_projectiles.at(i))){
				//delete (*it)->GetSprite();
				//delete (*at)->GetSprite();
				delete m_player_projectiles.at(i)->GetSprite();
				m_player_projectiles.erase(m_player_projectiles.begin()+i);
				if(m_girls.at(j)->Damaged(m_player->GetDamage())<=0){
					m_vRepairKits.push_back(new RepairKit(m_girls.at(j)->GetPosition(), m_girls.at(j)->GetVelocity(), 
						m_spritemanager->Load("../data/sprites/ToolBox.png", "Toolbox", 1, 1)));
					delete m_girls.at(j)->GetSprite();
					m_girls.erase(m_girls.begin()+j);
					//SCORE COUNT
					m_xscore->PutInScore(enemyscore = 50);
					--j;
				}
				--i;
				break;
			};

		};
	};

	for(int i = 0; i< m_vRepairKits.size(); i++){
		if(m_vRepairKits.at(i)->Update(m_truck, m_player, deltatime)){
			//delete (*it)->GetSprite();
 			m_truck->Healed();
			delete m_vRepairKits.at(i)->GetSprite();
			m_vRepairKits.erase(m_vRepairKits.begin()+i);
			i--;
		};
	};

	float lol = m_truck->UpdateHP()/100;
	if(lol>1){
		lol=1;
	}
	m_hpbar->GetSprite()->setScale(lol, 1.0);



}

sf::Vector2f GameObjectManager::GetStartPosition(GameObject *GO)
{
	return GO->GetPosition();
}
void GameObjectManager::AttachObject(GameObject *object)
{

	//	m_gameobject.push_back(object);

}
//detach
void GameObjectManager::DetachObject(GameObject *object)
{
	//for (auto it = m_gameobject.begin();it != m_gameobject.end();)
	//{
	//	GameObject *obj = *it;
	//	if (obj = object)
	//	{
	//		if(obj != nullptr)
	//		{
	//			/*delete (*it)->GetCollider();*/
	//			
	//			delete *it;
	//			*it = nullptr;
	//		//	auto old = it;
	//			//m_gameobject.pop_back();
	//		}

	//		it++;
	//	}
	//}
}

void GameObjectManager::DetachObject()
{
	//for( auto it = m_gameobject.begin();it != m_gameobject.end(); ) 
	//{	

	//	/*delete (*it)->GetCollider();*/
	//	delete (*it)->GetSprite();
	//	delete *it;
	//	/*auto old = it;

	//	it++;*/
	//	m_gameobject.erase(it);		
	//}

}

void GameObjectManager::DrawGameObjects()
{
	m_window->draw(*m_backgound);

	m_window->draw(*m_hpbar->Sprite2()); //draws hpsprite
	m_window->draw(*m_hpbar->GetSprite()); //Draws hpbar
	m_window->draw(*m_hpbar->Sprite3()); //draws hpbars shadow


	m_window->draw(*m_truck->GetSprite()); //Draws truck
	m_window->draw(*m_player->GetSprite()); //Draws player

	m_window->draw(m_xscore->DrawScore());

	for(int i=0; i<m_vRepairKits.size(); i++){
		if(m_vRepairKits.at(i)!=nullptr){
			m_window->draw(*m_vRepairKits.at(i)->GetSprite()); // draws all RepairKits
		}
	};
	for(int i=0; i<m_enemies.size(); i++){
		if(m_enemies.at(i)!=nullptr){
			m_window->draw(*m_enemies.at(i)->GetSprite()); // draws all enemies
		}
	};
	for(int i=0; i<m_supers.size(); i++){
		if(m_supers.at(i)!=nullptr){
			m_window->draw(*m_supers.at(i)->GetSprite()); // draws all enemies
		}
	};
	for(int i=0; i<m_girls.size(); i++){
		if(m_girls.at(i)!=nullptr){
			m_window->draw(*m_girls.at(i)->GetSprite()); // draws all enemies
		}
	};
	for(int i=0; i<m_player_projectiles.size(); i++){
		if(m_player_projectiles.at(i)!=nullptr){
			m_window->draw(*m_player_projectiles.at(i)->GetSprite());	// draws all player projectiles
		}
	};
	for(int i=0; i<m_enemy_projectiles.size(); i++){
		if(m_enemy_projectiles.at(i)!=nullptr){
			m_window->draw(*m_enemy_projectiles.at(i)->GetSprite());	// draws all enemy projetiles
		}
	};
}
//////////////////////////////////////////////////////////////////////////// :)
///////////////////////////////////Buttons//////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void GameObjectManager::CreateButtons()
{
	m_vButtons.push_back(new Button(m_input, "StartGame", m_spritemanager->Load("../data/buttons/Start_Game.png", "StartGame"), 
		(Config::getInt("window_w", 0)/2 - 119), Config::getInt("menu_top_padding", 0)));

	m_vButtons.push_back(new Button(m_input, "HighScore", m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"), 
		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + Config::getInt("button_padding", 0))));

	m_vButtons.push_back(new Button(m_input, "Options", m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"), 
		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*2))));

	m_vButtons.push_back(new Button(m_input, "QuitGame", m_spritemanager->Load("../data/buttons/Quit_Game.png", "QuitGame"), 
		(Config::getInt("window_w", 0)/2 - 119), (Config::getInt("menu_top_padding", 0) + (Config::getInt("button_padding", 0)*3))));
};

void GameObjectManager::UpdateButtons()
{


};

void GameObjectManager::DrawButtons()
{
	for(int i=0; i<m_vButtons.size(); i++){
		if(m_vButtons.at(i)!=nullptr){
			m_window->draw(*m_vButtons.at(i)->GetSprite()); // draws all buttons
		}
	}
};

void GameObjectManager::CreateCusomizationButtons()
{
	//Top Suit
	m_vCustomizeButtons.push_back(new Button(m_input, "ChangeSuitLeft", m_spritemanager->Load("../data/buttons/change_left_button.png", "ChangeSuitLeft"), 
		Config::getInt("customize_padding_big", 0), Config::getInt("customize_padding_big", 0)));
	m_vCustomizeButtons.push_back(new Button(m_input, "UpgradeSuit", m_spritemanager->Load("../data/buttons/upgrade_suit.png", "UpgradeSuit"), 
		104, Config::getInt("customize_padding_big", 0)));
	m_vCustomizeButtons.push_back(new Button(m_input, "ChangeSuitRight", m_spritemanager->Load("../data/buttons/change_right_button.png", "ChangeSuitRight"), 
		295, Config::getInt("customize_padding_big", 0)));
	
	//Top Weapon
	m_vCustomizeButtons.push_back(new Button(m_input, "ChangeWeaponLeft", m_spritemanager->Load("../data/buttons/change_left_button.png", "ChangeWeaponLeft"), 
		354, Config::getInt("customize_padding_big", 0)));
	m_vCustomizeButtons.push_back(new Button(m_input, "UpgradeWeapon", m_spritemanager->Load("../data/buttons/upgrade_weapon.png", "UpgradeWeapon"), 
		413, Config::getInt("customize_padding_big", 0)));
	m_vCustomizeButtons.push_back(new Button(m_input, "ChangeWeaponRight", m_spritemanager->Load("../data/buttons/change_right_button.png", "ChangeWeaponRight"), 
		873, Config::getInt("customize_padding_big", 0)));

	//Top Truck
	m_vCustomizeButtons.push_back(new Button(m_input, "ChangeWeaponLeft", m_spritemanager->Load("../data/buttons/change_left_button.png", "ChangeTruckLeft"), 
		932, Config::getInt("customize_padding_big", 0)));
	m_vCustomizeButtons.push_back(new Button(m_input, "UpgradeWeapon", m_spritemanager->Load("../data/buttons/upgrade_suit.png", "UpgradeTruck"), 
		991, Config::getInt("customize_padding_big", 0)));
	m_vCustomizeButtons.push_back(new Button(m_input, "ChangeWeaponRight", m_spritemanager->Load("../data/buttons/change_right_button.png", "ChangeTruckRight"), 
		1182, Config::getInt("customize_padding_big", 0)));

	//back
	m_vCustomizeButtons.push_back(new Button(m_input, "Back", m_spritemanager->Load("../data/buttons/back_button.png", "Back"), 
		Config::getInt("customize_padding_big", 0), ((Config::getInt("window_h", 0) - Config::getInt("customize_padding_big",0) - 64))));
		
};
void GameObjectManager::DrawCustomizationButtons()
{
		for(int i=0; i<m_vCustomizeButtons.size(); i++){
		if(m_vCustomizeButtons.at(i)!=nullptr){
			m_window->draw(*m_vCustomizeButtons.at(i)->GetSprite()); // draws all buttons
		}
	}
}