#pragma once

#include <vector>

#include "Entity.h"

namespace game
{
	class GameBoard : public Entity
	{
	public:
		GameBoard(size_t height, size_t width)
			: _height(height), _width(width) {}

		void init() override;
		void update() override;

		size_t getHeight() { return _height; }
		size_t getWidth() { return _width; }

	private:
		size_t _height;
		size_t _width;
	};
}
