#include "Guard.h"
#include "Location.h"
#include "Bomb.h"
#include "Player.h"
#include "vector"
#include <iostream>
#include <random>
#include <io.h>
#include <Board.h>

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
void Guard::setLocation(Location newLoc)
{
	m_location.row = newLoc.row;
	m_location.col = newLoc.col;
}
Location Guard::move(Board &board)
{
	Location newLoc = randMove();

	newLoc = board.isValid(m_location, newLoc);

	return Location(m_location.row +1,m_location.col);










	////player location
	//Location player_loc = player.getLocation();
	////calc diff
	//int x_diff = player.getLocation().col - m_location.col,
	//	y_diff = player.getLocation().row - m_location.col;
	//// check if deseird step is valid
	//if (abs(x_diff) > abs(y_diff))
	//{
	//	m_location.col++;
	//}
	//else m_location

	////check if valid move, not valid? change












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
