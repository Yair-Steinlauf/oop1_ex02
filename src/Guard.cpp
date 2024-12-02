#include "Guard.h"
#include "Location.h"
#include "Bomb.h"
#include "Player.h"
#include "vector"
#include <iostream>
#include <random>


Guard::Guard(){}

Guard::Guard(Location loc) : m_location(loc), m_startLocation(loc){}

Location Guard::getLocation()
{
	return m_location;
}

Location Guard::getStartLocation()
{
	return m_startLocation;
}

bool Guard::isGuardBombed(Bomb bomb)
{
	struct Location bombLoc1 = bomb.getLocation();
	struct Location bombLoc2 = Location(bombLoc1.row + 1, bombLoc1.col);
	struct Location bombLoc3 = Location(bombLoc1.row - 1, bombLoc1.col);
	struct Location bombLoc4 = Location(bombLoc1.row, bombLoc1.col + 1);
	struct Location bombLoc5 = Location(bombLoc1.row, bombLoc1.col - 1);
	if (m_location == bombLoc1 || m_location == bombLoc2 || m_location == bombLoc3 || m_location == bombLoc4 || m_location == bombLoc5)
	{
		return true;
	}
	return false;
}

void Guard::resetLocation()
{
	m_location = m_startLocation;
}

void Guard::move(Player player, std::vector<Bomb> bombs)
{
	//std::random_device rd;  // מחולל מספרים אקראיים מבוסס חומרה
	//std::mt19937 gen(rd()); // מחולל פסאודו-אקראי מבוסס Mersenne Twister
	//std::uniform_int_distribution<> dist(0, 3); // טווח המספרים 0 עד 3

	//int randomNumber = dist(gen);
	//std::cout << "Random number: " << randomNumber << std::endl;

	//switch (randomNumber)
	//{
	//case 0:

	//default:
	//	break;
	//}

	//bool isBombExist = bombs.size() > 0; // check not null
	//if (isBombExist) {
	//	struct Location bombLoc = bombs[0].getLocation();
	//	if (m_location.row == bombLoc.row) {
	//		if (m_location.col > bombLoc.col) {
	//			if(m_)
	//			setGuardLoc(Location())
	//		}
	//	}
	//}
}
