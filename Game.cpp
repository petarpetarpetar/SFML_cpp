#include "Game.hpp"

Game::Game(int nL=4, int nC=4, std::string side1 = "s1", std::string side2 = "s2") : clock()
{
    this->name_side1 = side1;
    this->name_side2 = side2;
    this->number_of_castles = nC;
    this->number_of_lords = nL;
}

long int Game::getCurrentTime()
{
    return clock.getTime();
}

int Game::getNumCastle()
{
    return this->number_of_castles;
}

int Game::getNumLords()
{
    return this->number_of_lords;
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

bool Game::addCaste(Castle newC)
{
    castles.push_back(newC);
}

bool Game::addLord(Lord newL)
{
    lords.push_back(newL);
}
