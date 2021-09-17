#pragma once

#include <optional>

namespace game
{
	enum class KeyboardInput : char;

	class KeyboardInputReader
	{
	public:
		std::optional<KeyboardInput> readKey();
	};
}
