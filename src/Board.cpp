#include "Board.h"
#include "fstream"

Board::Board() {
	m_board.push_back("no text");
}
Board::Board(std::string fileName) {
	auto line = std::string();
	auto file = std::ifstream(fileName);
	while (std::getline(file, line)) {
		m_board.push_back(line);
	}
}
