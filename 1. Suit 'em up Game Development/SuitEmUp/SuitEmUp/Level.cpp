//level.cpp
#include "Level.h"
#include <sstream>
#include <fstream>
#include "Sprite.h"
#include "SpriteManager.h"
#include "DrawManager.h"
#include "GameObject.h"
#include <string>
#include "Collider.h"
#include "GameObjectManager.h"
#include <iostream>
#include "CollisionManager.h"
#include "PlayerObject.h"
#include "InputManager.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

Level::Level()
{
	m_height =0;
	m_width =0;

	m_collmgr = nullptr;
	gom = nullptr;
	m_player = nullptr;
	m_sprite = nullptr;

	//m_player_start_position = sf::Vector2u(0.0f, 0.0f);

}
bool Level::Load(const std::string &p_filename
				 , SpriteManager *m_sprite_manager
				 ,GameObjectManager *m_manager
				 , CollisionManager *collmgr
				 , InputManager *m_input)
{
	gom = m_manager;
	m_collmgr = collmgr;

	std::ifstream stream(p_filename);
	if(!stream.is_open())
	{
		return false;
	}
	std::string row;
	unsigned int coord_count=0;
	stream >> m_spritemap_filename;
	stream >> coord_count >> m_width >> m_height;
	std::getline(stream,row);
	for(unsigned int i=0;i<coord_count;i++)
	{
		std::getline(stream,row);
		std::stringstream ss(row);
		std::string ch;
		Coords coord;

		ss >> ch;
		ss >> coord.x;
		ss >> coord.y;
		ss >> coord.w;
		ss >> coord.h;

		m_tile_coords.insert( std::pair<char,Coords>(ch[0],coord));
	}
	unsigned int x = 0;
	unsigned int y = 0;

	while (!stream.eof())
	{

		std::getline(stream, row, '\n');
		if(row.length()==0)
		{
			continue;
		}
		x=0;
		for (unsigned int i=0;i<row.length();i++)
		{
			if(row[i]=='0')
			{

				x +=m_width;
				continue;

			}/*else if(row[i] == 'S')
			{

				m_player_start_position.m_x = x;
				m_player_start_position.m_y = y;
				x += m_width;


				if (m_player == nullptr)
				{

					m_player = new PlayerObject( m_input, nullptr, m_collmgr->CreateCollider(m_player_start_position, Vector2(60.0, 60.0)));

					m_player->SetPosition(m_player_start_position);
					m_player->SetStartPosition(m_player_start_position); 


					Animation *sprite = p_sprite_manager->Load("../data/animations/Player_Move.txt");
					m_player->AddAnimation("Player_Move", sprite);
					sprite = p_sprite_manager->Load("../data/animations/Player_Move_Left.txt");
					m_player->AddAnimation("Player_Move_Left", sprite);
					sprite = p_sprite_manager->Load("../data/animations/Player_Move_Down.txt");
					m_player->AddAnimation("Player_Move_Down", sprite);
					sprite = p_sprite_manager->Load("../data/animations/Player_Move_Right.txt");
					m_player->AddAnimation("Player_Move_Right", sprite);
					m_player->SetAnimation("Player_Move");					


					sprite = p_sprite_manager->Load("../data/animations/Player_Moving_Still_Left.txt");
					m_player->AddAnimation("Player_Moving_Still_Left", sprite);
					sprite = p_sprite_manager->Load("../data/animations/Player_Moving_Still.txt");
					m_player->AddAnimation("Player_Moving_Still", sprite);
					sprite = p_sprite_manager->Load("../data/animations/Player_Moving_Still_Right.txt");
					m_player->AddAnimation("Player_Moving_Still_Right", sprite);
					sprite = p_sprite_manager->Load("../data/animations/Player_Moving_Still_Down.txt");
					m_player->AddAnimation("Player_Moving_Still_Down", sprite);

					m_manager->AttachObject(m_player);

					continue;	

				}
			}else if(row[i] == '2')//Water
			{

			}else if(row[i] == '3') //Car
			{

	

			}else if(row[i] == '4')//LOG
			{



			}else if(row[i] == '5') //GOAL
			{


			}*/


			std::map<char,Coords>::iterator it = m_tile_coords.find(row[i]);
			if(it == m_tile_coords.end())
			{
				continue;
			}
			Coords &c = it->second;
			//Sprite *sprite = m_sprite_manager->Load(m_spritemap_filename, c.x,c.y,c.w,c.h);

			x += m_width;

		}
		y += m_height;


	}
	stream.close();
	return true;

}


Level::~Level()
{
	gom->DetachObject();
}

void Level::Draw(DrawManager *p_draw_manager)
{
	gom->DrawObject(p_draw_manager);
}