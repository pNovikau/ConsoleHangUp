#pragma once
#include <string>
#include <sstream>

#include "CollisionObserver.h"
#include "Entity.h"
#include "Position.h"

class Ball : public CollisionObserver, public Entity
{
public:
	void update();

	void handleCollision(std::shared_ptr<Entity> entity) override;

	Position getActual()
	{
		return _actual;
	}

	Position getSpookyGhost()
	{
		return _spookyGhost;
	}

	std::string getScore()
	{
		std::stringstream ss;
		ss << playerScore << " - " << oppPlayerScore;

		return ss.str();
	}



private:

	void resetBall();

	Position _actual{ 16, 5 };
	Position _spookyGhost{ 15, 6 };

	int _wasUpdatedLastFrame = 0;
	int _pause = 20;

	int playerScore = 0;
	int oppPlayerScore = 0;
};


