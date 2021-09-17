#pragma once
#include <vector>

#include "Entity.h"
#include "InputObserver.h"
#include "Position.h"

class Player : public InputObserver, public Entity
{
public:
	void handleInput(KeyboardInput inputKey) override;

	std::vector<Position>& getBody()
	{
		return _body;
	}

private:
	std::vector<Position> _body{ {18, 8},{18, 9},{ 18, 10},{18, 11} };
};
