#pragma once

#include "Board.h"
#include "Player.h"
#include "Guard.h"
#include "vector"
#include "Bomb.h"

class Controller {
public:	
	Controller();
	void run();
	void playBoard(Board& board);
	
private:
	Board m_board;
	//Player m_player;
	//std::vector<Guard> m_guard;
	//std::vector<Bomb> m_bombs;
	
};