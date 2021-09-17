#pragma once

enum class KeyboardInput : char;

class InputObserver
{
public:
	virtual void handleInput(KeyboardInput inputKey) = 0;
};