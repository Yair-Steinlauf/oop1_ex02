#pragma once
#include "Location.h"
#include "Bomb.h"
class Board;
class Player {
public:
	Player();
	Player(int row, int col);
	struct Location getLocation();
	struct Location move(Board &board, bool& isBombPutted);
	void setLocation(struct Location newLoc);
	int getHeal();
	void decreaseHeal();
	bool isPlayerBombed(Bomb bomb);
	


private:
	struct Location m_location;
	int m_heal;
};