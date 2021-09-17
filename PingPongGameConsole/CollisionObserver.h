#pragma once

#include <memory>

class Entity;

class CollisionObserver
{
public:
	virtual void handleCollision(std::shared_ptr<Entity> entity) = 0;
};