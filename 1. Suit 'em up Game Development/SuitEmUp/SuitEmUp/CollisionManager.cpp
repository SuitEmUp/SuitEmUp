// CollisionManager.cpp

#include "CollisionManager.h"

CollisionManager::CollisionManager(){

};

void CollisionManager::EnemyDeathCollision(std::vector<EnemyObject*> enemies, 
										   std::vector<PlayerBullet*> bullets){
	for(int i=0; i<bullets.size(); i++){
		for(int j=0; j<enemies.size(); i++){
			//if they collide...
			//DELETE THE ENEMY WITH AN ITERATOR \m/
		};
	};
};
