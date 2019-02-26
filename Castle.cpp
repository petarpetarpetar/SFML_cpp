#include "Castle.hpp"

Castle::Castle(int x, int y, int side)
{
    this->position.setX(x);
    this->position.setY(y);
    this->side = side;
    //influenced by GameRules.cpp
    this->food = START_FOOD;
    this->def_bonus = START_DEF_BONUS;
    this->money = START_MONEY;
    this->population = START_POPULATION;

}

int Castle::getDefBonus()
{
    return this->def_bonus;
}

int Castle::getFood()
{
    return this->food;
}

int Castle::getMoney()
{
    return this->money;
}

int Castle::getCurrentLord()
{
    return this->currentLordID;
}

bool Castle::setCurrentLord(int newLord)
{
    return this->currentLordID = newLord;
}

int Castle::getSide()
{
    return this->side;
}

int Castle::getPopulation()
{
    return this->population;
}

bool Castle::increasePopulation(int change)
{
   this->population+change;
}

bool Castle::setPosition(Coords newC)
{
    this->position.setX(newC.getX());
    this->position.setY(newC.getY());
}

bool Castle::getIncome()
{
    return this->income;
}

