
#include "Board.h"
#include "fstream"
#include "iostream"

void Board::loadBoard(std::string fileName) {
	auto line = std::string();
	auto file = std::ifstream(fileName);
	while (std::getline(file, line)) {
		m_board.push_back(line);
	}
	m_victory = false;
}




void Board::print() const
{
	for (int row = 0; row < m_board.size(); row++)
	{
		std::cout << m_board[row] << '\n';
	}
}
 //אופרטור השמה
Board& Board::operator=(const Board& other) {
	return *this; 
}

