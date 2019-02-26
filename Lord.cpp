#include "Lord.hpp"

Lord::Lord(int side, std::string name)
{
    this->side = side;
    this->name = name;
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
    return this->status
}

Coords Lord::getPos()
{
    return this->pos;
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
    this->pos.setX(newPos.getX());
    this->pos.setY(newPos.getY());
}




    return this->pos;
}
