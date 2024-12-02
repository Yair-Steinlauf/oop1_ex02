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
	void setLocation(Location newLoc);
	Location move(Board& board);
private:
	struct Location m_location;
	struct Location m_startLocation;
	
};