#pragma once
#include <vector>

#include "CollisionObserver.h"
#include "Entity.h"
#include "GameBreaker.h"
#include "InputObserver.h"
#include "Position.h"

namespace game
{
	class Snake :
		public Entity,
		public InputObserver,		
		public CollisionObserver
	{
		enum class Direction
		{
			None = 0,
			Up,
			Down,
			Left,
			Right,
		};
	
	public:
		explicit Snake(const Position pos, std::shared_ptr<GameBreaker> gameBreaker)
			: _headPosition(pos)
			, _gameBreaker(std::move(gameBreaker)){ _ghostTail = pos; }

		void update() override;
		void postUpdate() override;

		void handleInput(KeyboardInput input) override;
		void handleCollision(std::shared_ptr<Entity> entity) override;

		std::vector<Position>& getBody() { return _body; }

		[[nodiscard]] Position getPosition() const
		{
			return _headPosition;
		}

	private:
		Position _headPosition;
		Direction _currentDirection = Direction::None;

		std::vector<Position> _body { _headPosition };
		Position _ghostTail;
		std::shared_ptr<GameBreaker> _gameBreaker;
	};
}


