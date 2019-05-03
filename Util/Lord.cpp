#include "Lord.hpp"

Lord::Lord(int posX,int posY, std::string _name)
{
    position.setX(posX);
    position.setY(posY);
    this->name = _name;
}
bool Lord::setSide(int _side)
{
    this->side = _side;
}

int Lord::getBattlesWon()
{
    return this->battlesWon;
}

int Lord::getMoveSpeed()
{
    return this->moveSpeed;
}

int Lord::getStatus()
{
    return this->_status;
}

Coords Lord::getPosition()
{
    return this->position;
}

bool Lord::setStatus(int newStatus)
{
    this->_status = newStatus;
}

bool Lord::incBattlesWon()
{
    this->battlesWon++;
}

bool Lord::setPos(Coords newPos)
{
    this->position.setX(newPos.getX());
    this->position.setY(newPos.getY());
}
