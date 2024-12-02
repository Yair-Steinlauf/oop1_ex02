
#include "Bomb.h"

Bomb::Bomb()
{
}

Bomb::Bomb(struct Location loc) : m_loc(loc), m_time(5) {}

void Bomb::act()
{
	m_time--;
};

int Bomb::getTime()
{
	return m_time;
}

Location Bomb::getLocation()
{
	return m_loc;
}
