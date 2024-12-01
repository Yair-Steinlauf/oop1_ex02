#pragma once
class Bomb {
public:
	Bomb(int row, int col);
	void act();
	int getTime();
private:
	int m_row, m_col;
	int m_time = 5;
};