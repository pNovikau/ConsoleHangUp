#include <iostream>
#include <windows.h>

#include "Drawer.h"

void Drawer::Draw()
{
	Sleep(5);
	system("cls");

	for (int x = 0; x < 20; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (x == 0 || x == 20 - 1 || y == 0 || y == 20 - 1)
			{
				std::cout << '*';
				continue;
			}

			bool isPlayer = false;

			for (const auto& bodyPosition : _player->getBody())
			{
				if (bodyPosition.x == x && bodyPosition.y == y)
				{
					isPlayer = true;
					break;
				}
			}			

			for (const auto& bodyPosition : _oppPlayer->getBody())
			{
				if (bodyPosition.x == x && bodyPosition.y == y)
				{
					isPlayer = true;
					break;
				}
			}



			if (isPlayer)
			{
				std::cout << "#";
			}
			else if (_ball->getActual().x == x && _ball->getActual().y == y)
			{
				std::cout << "O";
			}
			/*else if (_ball->getSpookyGhost().x == x && _ball->getSpookyGhost().y == y)
			{
				std::cout << "x";
			}*/
			else
			{
				std::cout << ' ';
			}
		}

		std::cout << std::endl;
	}

	std::cout << _ball->getScore() << std::endl;
}