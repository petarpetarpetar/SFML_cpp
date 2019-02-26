#include "Coords.hpp"
Coords::Coords()
{
    x=0;
    y=0;
}
int Coords::getX()
{
    return this->x;
}
int Coords::getY()
{
    return this->y;
}
bool Coords::setX(int newX)
{
    this->x = newX;
}
bool Coords::setY(int newY)
{
    this->y = newY;
}
