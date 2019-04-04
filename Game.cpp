#include "Game.hpp"

Game::Game() : clock()
{
    std::cout << "a new game session started"<<std::endl;
}

long int Game::getCurrentTime()
{
    return clock.getTime();
}

int Game::getNumCastle(int playerID)
{
    return this->players.at(playerID).getNumCastle();
}

int Game::getNumLords(int playerID)
{
    return this->players.at(playerID).getNumLords();
}

bool Game::calcTimeDiff()
{
    clock.calcTimeDiff();
}

bool Game::updateTime()
{
    clock.updateTime();
}

long int Game::getTDiff()
{
    return clock.getTimeDiff();
}
Player Game::getPlayer(int playerID)
{
    return players.at(playerID);
}
bool Game::addCastle(int playerID,Castle newC)
{
    players.at(playerID).addCaste(newC);
}

bool Game::addLord(int playerID,Lord newL)
{
    players.at(playerID).addLord(newL);
}
bool Game::addPlayer(Player p)
{
    players.push_back(p);
}

Castle Game::getCastle(int playerID, int castleID)
{
    players.at(playerID).getCastle(castleID);
}
Lord Game::getLord(int playerID, int lordID)
{
    players.at(playerID).getLord(lordID);
}

