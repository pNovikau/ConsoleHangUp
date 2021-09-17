#include "GameManager.h"

#include <iostream>

int main()
{
	game::GameManager manager;

	manager.init();
	manager.start();

    std::cout << "Hello World!\n";
}
