#include "Ball.h"

#include <memory>

#include "OppositePlayer.h"
#include "Player.h"

void Ball::resetBall()
{
	_actual = Position{ 16, 5 };
	_spookyGhost = Position{ 15, 6 };
	_wasUpdatedLastFrame = 0;
	_pause = 20;
}

void Ball::update()
{
	if (_wasUpdatedLastFrame < _pause)
	{
		_wasUpdatedLastFrame ++;
		return;
	}

	int deltaX = _spookyGhost.x - _actual.x;
	int deltaY = _spookyGhost.y - _actual.y;

	std::swap(_actual, _spookyGhost);

	_spookyGhost.x = _actual.x + deltaX;
	_spookyGhost.y = _actual.y + deltaY;

	if (_spookyGhost.y == 0)
	{
		_spookyGhost.y = 2;
	}

	if (_spookyGhost.y == 19)
	{
		_spookyGhost.y = 17;
	}

	if (_spookyGhost.x == 0)
	{
		playerScore++;

		resetBall();
		return;
	}

	if (_spookyGhost.x == 19)
	{
		oppPlayerScore++;

		resetBall();
		return;
	}

	_wasUpdatedLastFrame = 0;
	_pause = 2;
}

void Ball::handleCollision(std::shared_ptr<Entity> entity)
{
	if (auto player = std::dynamic_pointer_cast<Player>(entity); player)
	{
		_spookyGhost.x = 16;
	}

	if (auto oppPlayer = std::dynamic_pointer_cast<OppositePlayer>(entity); oppPlayer)
	{
		_spookyGhost.x = 3;
	}
}
