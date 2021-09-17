#pragma once

namespace game
{
	struct Position
	{
		int x = 0;
		int y = 0;

		bool operator==(const Position& pos) const
		{
			return pos.x == x &&
				   pos.y == y;
		}
	};
}
