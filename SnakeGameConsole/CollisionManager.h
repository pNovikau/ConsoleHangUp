#pragma once
#include <memory>
#include <vector>

namespace game
{
	class GameBoard;
	class Apple;
	class Snake;
	class CollisionObserver;

	class CollisionManager
	{
	public:
		CollisionManager(std::shared_ptr<Snake> snake, std::shared_ptr<Apple> apple, std::shared_ptr<GameBoard> board)
			: _snake(std::move(snake)), _apple(std::move(apple)), _board(std::move(board)) {}

		void update();

	private:
		std::shared_ptr<Snake> _snake;
		std::shared_ptr<Apple> _apple;
		std::shared_ptr<GameBoard> _board;
	};
}
