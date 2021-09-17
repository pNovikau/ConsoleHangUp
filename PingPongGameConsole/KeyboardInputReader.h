#pragma once

#include <optional>

enum class KeyboardInput : char;

class KeyboardInputReader
{
public:
	std::optional<KeyboardInput> readKey();
};