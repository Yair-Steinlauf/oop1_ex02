#pragma once
#include "Location.h"
#include "Bomb.h"
class Board;
class Player {
public:
	Player();
	Player(int row, int col);
	struct Location getLocation();
	struct Location getStartLocation();
	struct Location move(Board &board, bool& isBombPutted);
	void setLocation(struct Location newLoc);
	int getHeal();
	void decreaseHeal();
	bool isPlayerBombed(Bomb bomb);
	void resetLocation();
	


private:
	struct Location m_location;
	struct Location m_startLocation;
	int m_heal;
};