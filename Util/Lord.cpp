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
Lord::Lord(int a)
{
    //idk what will empty lord look alike
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

sf::Sprite Lord::getImage()
{
    return this->image;
}
void Lord::setImage(sf::Texture texture)
{
    image.setTexture(texture);
}

void Lord::setImageScale(int a,int b)
{
    if(b==0)
        image.setScale(a,a);
    image.setScale(a,b);
    return;
}
