#pragma once

#include <memory>

#include "Apple.h"
#include "GameBoard.h"
#include "Snake.h"

namespace game
{
	class Drawer
	{
	public:
		Drawer(std::shared_ptr<Snake> snake, std::shared_ptr<Apple> apple, std::shared_ptr<GameBoard> board)
			: _snake(std::move(snake)), _apple(std::move(apple)), _board(std::move(board)) {}

		void Draw();

	private:
		std::shared_ptr<Snake> _snake;
		std::shared_ptr<Apple> _apple;
		std::shared_ptr<GameBoard> _board;
	};
}
