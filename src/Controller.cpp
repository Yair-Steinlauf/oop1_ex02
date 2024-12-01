
#include "io.h"
#include "Controller.h"
#include "Board.h"
#include "conio.h"
#include "cstdlib"
#include "iostream"
#include "string"
#include "vector"
#include "fstream"
//#include "istream"
Controller::Controller(){}
void Controller::run() {

	//// read playlist:
	std::vector<std::string> playlist;
	auto line = std::string();
	auto file = std::ifstream("playlist.txt");
	/*if (!std::getline(file, line)) {
		std::cerr << "Can't read from file\n";
		exit(EXIT_FAILURE);
	}*/
	
	while (std::getline(file, line)) {
		playlist.push_back(line);
	}
	
	m_board.loadBoard(playlist[0]);
		m_board.print();
	// for playlist
//	for (int  i = 0; i < playlist.size(); i++)
//	{
//		Board board1  = Board(playlist[i]);
//		board1.print();
//		//playBoard()
////			{
//		//while (!board_victory)
//		//		board.victory =player.move(*this) 
//		//		for each  guard.move(*this)
//		//		for each  bomb.act(*this)
//
//	}

}

//void Controller::playBoard(Board& board)
//{
//	while (!m_board.getVictory())
//	{
//		m_player.  
//	}
//}
//
