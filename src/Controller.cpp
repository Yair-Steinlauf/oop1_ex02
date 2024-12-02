
#include "io.h"
#include "Controller.h"
#include "Board.h"
#include "conio.h"
#include "cstdlib"
#include "iostream"
#include "string"
#include "vector"
#include "fstream"
// #include "istream"
void resetGuards(std::vector<Guard> &guards, Board &board);
void checkGuardsBombed(std::vector<Guard>& guards, int &point, Bomb bomb);
Controller::Controller() {}
void Controller::run()
{

    //// read playlist:
    std::vector<std::string> playlist;
    auto line = std::string();
    auto file = std::ifstream("playlist.txt");
    /*if (!std::getline(file, line)) {
        std::cerr << "Can't read from file\n";
        exit(EXIT_FAILURE);
    }*/

    while (std::getline(file, line))
    {
        playlist.push_back(line);
    }
    struct Location doorLocation;
    for (int level = 0; level < playlist.size(); level++)
    {
        int numOfGuards = 0;
        int playerPoints = 0;
        m_board.loadBoard(playlist[level], m_player, m_guard, doorLocation, numOfGuards);
        m_board.print(level + 1);
        while (true)
        {
            bool isBombPutted = false;
            struct Location newPlayerLoc = m_player.move(m_board, isBombPutted);
            if (newPlayerLoc == doorLocation) {
                std::cout << "finish it!!";
            }
            if (isBombPutted) 
            {
                m_bombs.push_back(Bomb(newPlayerLoc));
                m_board.playerOnBomb(newPlayerLoc);             
            }

            m_board.setPlayer(m_player.getLocation(), newPlayerLoc);
            m_player.setLocation(newPlayerLoc);
            for (int index = 0; index < m_guard.size(); index++)
            {
                Location newGuardLoc(m_guard[index].move(m_board,m_player));
                m_board.setGuard(m_guard[index].getLocation(), newGuardLoc);
                m_guard[index].setLocation(newGuardLoc);
            }
            

            for (int bombIndex = 0; bombIndex < m_bombs.size(); bombIndex++)
            {
                bool isBombExploded = false;
                bool isPlayerBombed = false;
                if (newPlayerLoc == m_bombs[bombIndex].getLocation())
                {
                    m_board.playerOnBomb(newPlayerLoc);
                }
                else if (m_bombs[bombIndex].getTime() > 0)
                {
                    m_board.putBombTime(m_bombs[bombIndex]);
                }
                else if (m_bombs[bombIndex].getTime() == 0)
                {
                    m_board.bombExplodes(m_bombs[bombIndex]);
                    // check if guard bombed
                    checkGuardsBombed(m_guard, playerPoints, m_bombs[bombIndex]);
                    m_board.setPoint(playerPoints);
                    // check if player in bomb place:
                    if (m_player.isPlayerBombed(m_bombs[bombIndex]))
                    {
                        m_player.decreaseHeal();
                        isPlayerBombed = true;
                        if (m_player.getHeal() == 0) {
                            //std::cout << "You Lose!! lala";
                        }
                        else {

                            m_board.setNewHeal(m_player.getHeal());                           
                            m_board.finishBombExploeds(m_bombs[bombIndex]);
                            m_board.setPlayer(newPlayerLoc, newPlayerLoc);
                            m_bombs.clear(); // reset bomb                            
                            resetGuards(m_guard, m_board); // reset guards
                            
                        }
                    }
                    else {
                        // move guards:

                    }
                   
                   
                }
                else // time == -1
                {
                    m_board.finishBombExploeds(m_bombs[bombIndex]);
                    m_bombs.erase(m_bombs.begin() + bombIndex);
                    bombIndex--;
                    isBombExploded = true;
                }
                if (!isBombExploded && !isPlayerBombed) {
                    m_bombs[bombIndex].act();
                }


            }

            Screen::setLocation(Location(m_board.size(), 0));

    }
    
        //std::system("cls");
        //m_board.print();
        // handle guards move:
    }
    // repaint the board

    // find player:
    /*std::cout << "\nplayer: " << m_player.getRow() << ": " << m_player.getCol() << "\n";
    for (int i = 0; i < m_guard.size(); i++)
    {
        std::cout << "\nguard " << i <<": " << m_guard[i].getRow() << ": " << m_guard[i].getCol() << "\n";

    }*/

    // playBoard(m_board);

    // for playlist
    /*for (int i = 0; i < playlist.size(); i++)
    {*/
    // play()

    // playBoard()
    //			{
    //		//while (!board_victory)
    //		//		board.victory =player.move(*this)
    //		//		for each  guard.move(*this)
    //		//		for each  bomb.act(*this)
    //
    //	}

    //}
}

void resetGuards(std::vector<Guard>& guards, Board &board)
{
    for (int guardIndex = 0; guardIndex < guards.size(); guardIndex++)
    {
        board.setGuard(guards[guardIndex].getLocation(), guards[guardIndex].getStartLocation());
        guards[guardIndex].resetLocation();
    }

    // update board
}
void checkGuardsBombed(std::vector<Guard>& guards, int &points, Bomb bomb) 
{
    for (int guardIndex = 0; guardIndex < guards.size(); guardIndex++)
    {
        struct Location bombLoc1 = bomb.getLocation();
        
        if (guards[guardIndex].isGuardBombed(bomb)) {
            points += 5;
            guards.erase(guards.begin() + guardIndex);
            guardIndex--;
        }
    }
}
