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
    std::cout <<"debug " << playerID<<std::endl;
    players.at(playerID).addCaste(newC);
}

int Game::getNumPlayers()
{
    return this->players.size();
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
    return players.at(playerID).getCastle(castleID);
}
Lord Game::getLord(int playerID, int lordID)
{
    return players.at(playerID).getLord(lordID);
}


std::string Game::getPlayerName(int ID)
{
    return players.at(ID).getName();
}

bool Game::setPlayerName(int ID, std::string newN)
{
    players.at(ID).setName(newN);
}

int Game::getMoney(int PlayerID)
{
    return players.at(PlayerID).getMoney();
}

bool Game::addMoney(int PlayerID,int val)
{
    players.at(PlayerID).addMoney(val);
}




