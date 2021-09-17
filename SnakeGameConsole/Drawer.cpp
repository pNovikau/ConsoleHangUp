#include <iostream>
#include <windows.h>

#include "Drawer.h"

namespace game
{
	void Drawer::Draw()
	{
		Sleep(200);
		system("cls");

		for (size_t x = 0; x < _board->getHeight(); x++)
		{
			for (size_t y = 0; y < _board->getWidth(); y++)
			{
				bool isSnake = false;

				if (x == 0 || x == _board->getHeight() - 1 || y == 0 || y == _board->getWidth() - 1)
				{
					std::cout << '#';
					continue;
				}

				for (const auto& bodyPosition : _snake->getBody())
				{
					if (bodyPosition.x == x && bodyPosition.y == y)
					{
						isSnake = true;
						break;
					}
				}

				if (isSnake)
				{
					std::cout << "*";
				}
				else if (_apple->getPosition().x == x && _apple->getPosition().y == y)
				{
					std::cout << "@";
				}
				else
				{
					std::cout << ' ';
				}

			}

			std::cout << std::endl;
		}


	}
}