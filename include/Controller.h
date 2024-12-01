#pragma once

#include "Board.h"
//#include "Player.h"
//#include "Guard.h"
#include "vector"

class Controller {
public:	
	Controller();
	void run();
	//void loadBoard();
	
private:
	Board m_board;
	//Player m_player;
	//std::vector<Guard> m_guard;
	
};