#include "Player.h"

#include "KeyboardInput.h"

void Player::handleInput(KeyboardInput inputKey)
{
	if (inputKey == KeyboardInput::D)
	{
		if (_body.back().y != 18)
		{
			for (auto& pos : _body)
			{
				pos.y++;
			}
		}
	}
	else if (inputKey == KeyboardInput::A)
	{
		if (_body.front().y != 1)
		{
			for (auto& pos : _body)
			{
				pos.y--;
			}
		}
	}
}
