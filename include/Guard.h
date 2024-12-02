#pragma once
#include "Location.h"
#include "Bomb.h"
#include "Player.h"
#include "vector"


class Guard {
public:
	Guard();
	Guard(struct Location loc);
	struct Location getLocation();
	struct Location getStartLocation();
	bool isGuardBombed(Bomb bomb);
	void resetLocation();
	void move(Player player, std::vector<Bomb> bombs);
private:
	struct Location m_location;
	struct Location m_startLocation;
	
};