#include "OppositePlayer.h"

#include "KeyboardInput.h"

void OppositePlayer::handleInput(KeyboardInput inputKey)
{
	if (inputKey == KeyboardInput::Right)
	{
		if (_body.back().y != 18)
		{
			for (auto& pos : _body)
			{
				pos.y++;
			}
		}
	}
	else if (inputKey == KeyboardInput::Left)
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
