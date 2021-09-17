#include "Snake.h"

#include "Apple.h"
#include "GameBoard.h"
#include "KeyboardInput.h"

namespace game
{
	void Snake::update()
	{
		if (_currentDirection == Direction::Up)
		{
			_headPosition = { _headPosition.x - 1, _headPosition.y };
		}
		else if (_currentDirection == Direction::Right)
		{
			_headPosition = { _headPosition.x, _headPosition.y + 1 };
		}
		else if (_currentDirection == Direction::Left)
		{
			_headPosition = { _headPosition.x, _headPosition.y - 1 };
		}
		else if (_currentDirection == Direction::Down)
		{
			_headPosition = { _headPosition.x + 1, _headPosition.y };
		}
		else
		{
			return;
		}

		auto temp = _headPosition;

		for (size_t i = 0; i < _body.size(); ++i)
		{
			std::swap(temp, _body[i]);
		}
	}

	void Snake::postUpdate()
	{
		if (_body.back() != _ghostTail)
		{
			_ghostTail = _body.back();
		}
	}

	void Snake::handleInput(KeyboardInput input)
	{
		if (input == KeyboardInput::A && _currentDirection != Direction::Right)
			_currentDirection = Direction::Left;
		else if (input == KeyboardInput::D && _currentDirection != Direction::Left)
			_currentDirection = Direction::Right;
		else if (input == KeyboardInput::W && _currentDirection != Direction::Down)
			_currentDirection = Direction::Up;
		else if (input == KeyboardInput::S && _currentDirection != Direction::Up)
			_currentDirection = Direction::Down;
	}

	void Snake::handleCollision(std::shared_ptr<Entity> entity)
	{
		if (auto apple = std::dynamic_pointer_cast<Apple>(entity); apple)
		{
			_body.push_back(_ghostTail);
		}
		
		if (auto board = std::dynamic_pointer_cast<GameBoard>(entity); board)
		{
			_gameBreaker->stopFuckingGame();
		}
	}
}
