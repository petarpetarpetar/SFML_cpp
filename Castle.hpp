#ifndef CASTLE_HPP_INCLUDED
#define CASTLE_HPP_INCLUDED
#include "Coords.hpp"
#include "GameRules.cpp"
class Castle
{
private:
    //Army garnison[]
    int def_bonus;
    int food;
    int money;
    int currentLordID;
    int side;
    //Building buildings[]
    int currentlyBuilding;
    int buildingProcess;
    int income;
    int population;
    Coords position;


public:
    Castle(int,int,int);

    int getDefBonus();

    int getFood();

    int getMoney();

    int getCurrentLord(int newLord);

    bool setCurrentLord();

    int getSide();

    bool setSide();

    int getPopulation();

    bool increasePopulation();

    int getIncome();

    bool setPosition(Coords newC);

    //something to calculate def_bonus based on buildings
    //something to calculate income based on population and buildings

};


#endif // CASTLE_HPP_INCLUDED
