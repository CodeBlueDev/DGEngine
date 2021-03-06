#pragma once

#include "Action.h"
#include "Game.h"
#include "Game/Level.h"

class ActLevelMove : public Action
{
private:
	std::string id;
	sf::Vector2i pos;

public:
	ActLevelMove(const std::string& id_, const sf::Vector2i& pos_) : id(id_), pos(pos_) {}

	virtual bool execute(Game& game)
	{
		auto item = game.Resources().getLevel(id);
		if (item != nullptr)
		{
			item->move(pos);
		}
		return true;
	}
};

class ActLevelMoveToClick : public Action
{
private:
	std::string id;

public:
	ActLevelMoveToClick(const std::string& id_) : id(id_) {}

	virtual bool execute(Game& game)
	{
		auto item = game.Resources().getLevel(id);
		if (item != nullptr)
		{
			item->move(game);
		}
		return true;
	}
};

class ActLevelMoveToPlayer : public Action
{
private:
	std::string id;
	std::string idPlayer;

public:
	ActLevelMoveToPlayer(const std::string& id_, const std::string& idPlayer_)
		: id(id_), idPlayer(idPlayer_) {}

	virtual bool execute(Game& game)
	{
		auto level = game.Resources().getLevel(id);
		if (level != nullptr)
		{
			auto player = level->getPlayer(idPlayer);
			if (player != nullptr)
			{
				level->move(player->MapPosition());
			}
		}
		return true;
	}
};
