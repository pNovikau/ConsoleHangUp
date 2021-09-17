#include "CollisionManager.h"

#include <algorithm>

#include "Apple.h"
#include "GameBoard.h"
#include "Snake.h"

namespace game
{
	void CollisionManager::update()
	{
		if (_snake->getPosition().x == 0 ||
			_snake->getPosition().y == 0 ||
			_snake->getPosition().x == _board->getHeight() - 1 ||
			_snake->getPosition().y == _board->getWidth() -1)
		{
			_snake->handleCollision(_board);
		}

		if (_snake->getPosition() == _apple->getPosition())
		{
			_snake->handleCollision(_apple);
			_apple->handleCollision(_snake);
		}

		for (size_t i = 1; i < _snake->getBody().size(); ++i)
		{
			if (_snake->getBody()[i] == _snake->getPosition())
			{
				_snake->handleCollision(_board);
			}
		}
	}
}
