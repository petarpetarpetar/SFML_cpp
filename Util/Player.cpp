#include "Player.hpp"
Player::Player(int playerID)
{
    this->ID = playerID;
}

//yet to be defined
int Player::getNumLords(){
    return this->lords.size();
}
int Player::getNumCastle()
{
    return this->castles.size();
}

bool Player::addCaste(Castle newC)
{
    std::cout <<"newC pos : "<<newC.getPosition().getX()<<"|"<<newC.getPosition().getY()<<std::endl;
    std::cout <<"castle size 0: "<<castles.size()<<std::endl;
    std::cout <<"push_back occured"<<std::endl;
    castles.push_back(newC);
    std::cout <<"castle size 1: "<<castles.size()<<std::endl;
    std::cout << "pos in func: " << castles.at(0).getPosition().getX()<<std::endl;
}
std::string Player::getCastleName(int CastleID)
{
    return castles.at(CastleID).getName();
}
void Player::setCastleName(int CastleID, std::string name)
{
    castles.at(CastleID).setName(name);
}
bool Player::addLord(Lord newL)
{
    lords.push_back(newL);

}

Player::Player(int playerID,std::string name)
{
    this->ID = playerID;
    //this->number_of_castles = number_of_castles;
    //this->number_of_lords = number_of_lords;
    this->name = name;
}

int Player::getMoney()
{
    return this->money;
}
bool Player::addMoney(int val)
{
    this->money+=val;
}

Castle Player::getCastle(int castleID)
{
    return this->castles.at(castleID);
}

Lord Player::getLord(int lordID)
{
    return this->lords.at(lordID);
}

bool Player::setName(std::string newN)
{
    this->name = newN;
}
std::string Player::getName()
{
    return name;
}
