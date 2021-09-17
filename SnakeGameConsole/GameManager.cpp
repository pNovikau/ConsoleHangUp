#include "GameManager.h"

#include <iostream>

#include "KeyboardInput.h"

namespace game
{
	void GameManager::init()
	{

	}

	void GameManager::start()
	{
		while (true)
		{
			// 1. read input, if q, return
			// 2. notify input observers
			// 3. update snake
			// 6. handle collisions
			// last: draw everything

			// 1. update everything
			// 2. collisions for everything
			// 3. draw everything


			auto pressedKey = _keyboardReader.readKey();

			if (pressedKey.has_value())
			{
				if (pressedKey.value() == KeyboardInput::Q)
					return;

				_snake->handleInput(pressedKey.value());
			}

			if (_gameBreaker->didWeWin())
			{
				std::cout << "YEEEEEEEEEY";
				return;
			}

			_snake->update();

			_collisionManager.update();

			_snake->postUpdate();

			_drawer.Draw();
		}
	}
}
