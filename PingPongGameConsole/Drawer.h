#pragma once

#include <memory>

#include "Ball.h"
#include "OppositePlayer.h"
#include "Player.h"

class Drawer
{
public:
	Drawer(std::shared_ptr<Player> player, std::shared_ptr<OppositePlayer> oppPlayer, std::shared_ptr<Ball> ball)
		: _player(std::move(player)), _oppPlayer(std::move(oppPlayer)), _ball(std::move(ball)) {}

	void Draw();

private:

	std::shared_ptr<Player> _player;
	std::shared_ptr<OppositePlayer> _oppPlayer;
	std::shared_ptr<Ball> _ball;
};
