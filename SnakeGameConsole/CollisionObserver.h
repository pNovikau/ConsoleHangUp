#pragma once

#include <memory>

class Entity;

namespace game
{
	class CollisionObserver
	{
	public:
		virtual void handleCollision(std::shared_ptr<Entity> entity) = 0;
	};
}
