#include "Player.hpp"
Player::Player(int playerID)
{
    this->ID = playerID;
}

//yet to be defined
int Player::getNumLords(){
    return this->number_of_lords;
}
int Player::getNumCastle()
{
    return this->number_of_castles;
}

bool Player::addCaste(Castle newC)
{
    castles.push_back(newC);
}

bool Player::addLord(Lord newL)
{
    lords.push_back(newL);
}

Player::Player(int playerID,int number_of_lords, int number_of_castles,std::string name)
{
    this->ID = playerID;
    this->number_of_castles = number_of_castles;
    this->number_of_lords = number_of_lords;
    this->name_side1 = name;
}

Castle Player::getCastle(int castleID)
{
    return this->castles.at(castleID);
}

Lord Player::getLord(int lordID)
{
    return this->lords.at(lordID);
}
