//Level.h

#pragma once
#include <string>
#include <map>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>


class SpriteManager;
class DrawManager;
class GameObject;
class GameObjectManager;
class CollisionManager;
class InputManager;
class PlayerObject;
class Sprite;

class Level
{
	struct Coords
	{
		int x,y,w,h;
	};
public:
	Level();
	~Level();

	bool Load(const std::string &p_filename, SpriteManager *p_sprite_manager
		, GameObjectManager *m_manager
		, CollisionManager *collmgr,
		InputManager *input);

	void Draw(DrawManager *p_draw_manager);

protected:

	std::string m_spritemap_filename;
	unsigned int m_width;
	unsigned int m_height;
	std::map<char,Coords> m_tile_coords;


	CollisionManager *m_collmgr;
	GameObjectManager *gom;

	sf::Vector2u m_player_start_position;


	
	PlayerObject* m_player;
	Sprite *m_sprite;
};