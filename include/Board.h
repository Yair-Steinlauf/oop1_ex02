#pragma once
#include "vector"
#include "string"


class Board {
public:
	Board() {};
	void print() const;

	void loadBoard(std::string fileName);
	Board& operator=(const Board& other);
	//bool getVictory();
	//void setVictory();

	
private:
	std::vector<std::string> m_board;
	bool m_victory = false;

};