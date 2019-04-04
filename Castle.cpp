#include "Castle.hpp"

Castle::Castle(int x, int y)
{
    this->position.setX(x);
    this->position.setY(y);
    //influenced by GameRules.cpp
    this->food = START_FOOD;
    this->def_bonus = START_DEF_BONUS;
    this->money = START_MONEY;
    this->population = START_POPULATION;
    this->sword_enable = false;
    this->spear_enable = false;
    this->archer_enable = false;
    this->horse_enable = false;

}
Castle::Castle()
{
    this->position.setX(30);
    this->position.setY(30);
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
Coords Castle::getPosition()
{
    return this->position;
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

int Castle::getIncome()
{
    return this->income;
}


bool Castle::SetNewBuilding(BuildingType newB)
{
    this->currentlyBuilding = newB;
    this->buildingProcess = 0;
}

bool Castle::addBuilding(BuildingType newB)
{
    buildings.push_back(newB);
}

bool Castle::updateParams() //updates income, food and def_bonus
{
    for(std::vector<BuildingType>::iterator it = buildings.begin(); it != buildings.end();++it)
    {
        int temp = *it;
        switch(temp)
        {
        case HOUSE:
            this->population += HOUSE_POPULATION_INC;
        break;

        case SHOP:
            this->income += SHOP_INCOME_INC;
        break;

        case FARM:
            this->food += FARM_FOOD_INC;
        break;

        case TOWER:
            this->def_bonus += TOWER_DEF_BONUS_INC;
        break;

        case MARKET:
            this->income += MARKET_INCOME_INC;
        break;

        case STONE_WALL:
            this->def_bonus += STONE_WALL_DEF_BONUS_INC;
        break;

        case SWORDMAKER:
            this->sword_enable = true;
        break;

        case SPEARMAKER:
            this->spear_enable = true;
        break;

        case STABLE:
            this->horse_enable = true;
        break;

        case FETCHER:
            this->archer_enable = true;
        break;
        case TAX_MANAGER:
            //still needs to be implemented, basically physical work... -.-
        break;

        }

    }
}
