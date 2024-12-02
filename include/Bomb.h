#pragma once
#include "Location.h"

class Bomb {
public:
	Bomb();
	Bomb(struct Location loc);
	void act();
	int getTime();
	struct Location getLocation();
private:
	struct Location m_loc;
	int m_time;
};