#pragma once
#include <memory>
#include <vector>

#include "Ball.h"
#include "OppositePlayer.h"
#include "Player.h"

class CollisionObserver;

class CollisionManager
{
public:
	CollisionManager(std::shared_ptr<Player> player, std::shared_ptr<OppositePlayer> oppPlayer, std::shared_ptr<Ball> ball)
		: _player(std::move(player)), _oppPlayer(std::move(oppPlayer)), _ball(std::move(ball)) {}

	void update();

private:
	std::shared_ptr<Player> _player;
	std::shared_ptr<OppositePlayer> _oppPlayer;
	std::shared_ptr<Ball> _ball;

};