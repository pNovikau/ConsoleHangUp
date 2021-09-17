#include "KeyboardInputReader.h"

#include <conio.h>
#include <optional>

#include "KeyboardInput.h"

namespace game
{
	std::optional<KeyboardInput> KeyboardInputReader::readKey()
	{
		if (_kbhit())
		{
			switch (const char inputKey = _getch(); inputKey)
			{
				case 'q':
				case 'a':
				case 'w':
				case 's':
				case 'd':
					return KeyboardInput{ inputKey };
				default:
					return KeyboardInput::Other;
			}
		}

		return std::nullopt;
	}
}
