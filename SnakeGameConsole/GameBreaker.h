#pragma once

namespace game
{
	class GameBreaker
	{
	public:
		void stopFuckingGame()
		{
			_weDidIt = true;
		}

		bool didWeWin() { return _weDidIt; }

	private:
		bool _weDidIt = false;
	};
}
