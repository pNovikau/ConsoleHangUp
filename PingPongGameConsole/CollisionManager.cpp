#include "CollisionManager.h"

#include <algorithm>

void CollisionManager::update()
{
	auto it = std::find(_player->getBody().begin(), _player->getBody().end(), _ball->getSpookyGhost());
	if (it != _player->getBody().end())
	{
		_ball->handleCollision(_player);
		return;
	}
	
	it = std::find(_oppPlayer->getBody().begin(), _oppPlayer->getBody().end(), _ball->getSpookyGhost());
	if (it != _oppPlayer->getBody().end())
	{
		_ball->handleCollision(_oppPlayer);
	}
}