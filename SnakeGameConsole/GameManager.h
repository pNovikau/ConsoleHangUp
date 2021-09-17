#pragma once

#include "Apple.h"
#include "CollisionManager.h"
#include "Drawer.h"
#include "GameBoard.h"
#include "GameBreaker.h"
#include "KeyboardInputReader.h"
#include "Snake.h"

namespace game
{
	class GameManager
	{
	public:
		GameManager()
			: _gameBreaker(std::make_shared<GameBreaker>())
			, _board(std::make_shared<GameBoard>(20, 20))
			, _snake(std::make_shared<Snake>(Position{5, 5}, _gameBreaker))
			, _apple(std::make_shared<Apple>(Position{ 8, 8 }))
			, _drawer(_snake, _apple, _board)
			, _collisionManager(_snake, _apple, _board) {}

		void init();
		void start();

	private:
		std::shared_ptr<GameBreaker> _gameBreaker;
		KeyboardInputReader _keyboardReader;
		std::shared_ptr<GameBoard> _board;
		std::shared_ptr<Snake> _snake;
		std::shared_ptr<Apple> _apple;

		Drawer _drawer;
		CollisionManager _collisionManager;
	};
}
