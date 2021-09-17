#pragma once
#include <vector>

#include "Entity.h"
#include "InputObserver.h"
#include "Position.h"

class OppositePlayer : public InputObserver, public Entity
{
public:
	void handleInput(KeyboardInput inputKey) override;

	std::vector<Position>& getBody()
	{
		return _body;
	}

private:
	std::vector<Position> _body{ {1, 8},{1, 9},{ 1, 10},{1, 11} };
};
