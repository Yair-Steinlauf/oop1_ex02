
#include "Bomb.h"

Bomb::Bomb(int row, int col) : m_row(row), m_col(col) {}

void Bomb::act()
{
	m_time--;
};

int Bomb::getTime()
{
	return m_time;
}