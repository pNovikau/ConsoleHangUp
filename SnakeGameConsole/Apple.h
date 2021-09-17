#pragma once
#include "CollisionObserver.h"
#include "Entity.h"
#include "Position.h"

namespace game
{
	class Apple :
		public Entity,
		public CollisionObserver
	{
	public:

		Apple(Position pos) : _position(pos) {};

		void handleCollision(std::shared_ptr<Entity> entity) override;

		Position getPosition() const
		{
			return _position;
		}

	private:
		Position _position;
	};
}
