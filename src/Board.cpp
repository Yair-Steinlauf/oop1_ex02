#pragma once
#include "Board.h"
#include "fstream"


Board::Board(std::string fileName) {
	auto line = std::string();
	auto file = std::ifstream(fileName);
	while (std::getline(file, line)) {
		m_board.push_back(line);
	}
}
