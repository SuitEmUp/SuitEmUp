// CollisionManager.h

#pragma once;
#include <vector>

class PlayerBullet;
class EnemyObject;

class CollisionManager{
public:
	CollisionManager();
	void EnemyDeathCollision(std::vector<EnemyObject*> enemies, std::vector<PlayerBullet*> bullets);

};