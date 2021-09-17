#pragma once

#include "CollisionManager.h"
#include "Drawer.h"
#include "KeyboardInputReader.h"
#include "Player.h"

class GameManager
{
public:
	GameManager()
		: _drawer(_player, _oppPlayer, _ball) , _collisionManager(_player, _oppPlayer, _ball) {}

	void init();
	void start();

private:

	std::shared_ptr<Player> _player{ std::make_shared<Player>() };
	std::shared_ptr<OppositePlayer> _oppPlayer{ std::make_shared<OppositePlayer>() };
	std::shared_ptr<Ball> _ball{ std::make_shared<Ball>() };

	Drawer _drawer;
	CollisionManager _collisionManager;
	KeyboardInputReader _keyboardReader;
};
