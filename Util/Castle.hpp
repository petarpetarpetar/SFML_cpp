#ifndef CASTLE_HPP_INCLUDED
#define CASTLE_HPP_INCLUDED
#include "Coords.hpp"
#include "GameRules.cpp"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
enum BuildingType
{
    //standard buildings
    HOUSE = 1, //population increment according to number stated in gameRules
    SHOP = 2, //income increment
    FARM = 3, //food increment
    TOWER = 4, //def_bonus increment


    //special buildings, can only be made once
    MARKET = 11, // income increase greatly, but can be made only if meets specified requirements
    STONE_WALL = 12, // DEF_bonus increase ...
    SWORDMAKER = 13, //enables production of swordsmen
    SPEARMAKER = 14, //enables production of spears
    STABLE = 15, //enables production of horsemen
    FETCHER = 16, //enables production of archers
    TAX_MANAGER = 17 //bonus income for every shop.

};
class Castle
{
private:
    //Army garnison[]
    sf::Sprite image;
    std::string name;
    int def_bonus;
    int food;
    int money; //pasdkoasjd
    int currentLordID;
    int side;
    std::vector<BuildingType> buildings;//ID-s.
    int currentlyBuilding;
    int buildingProcess;
    int income;
    int population;
    bool sword_enable;
    bool spear_enable;
    bool horse_enable;
    bool archer_enable;
    Coords position;


public:
    //constructors
    Castle(int x,int y,std::string name);
    Castle();

    //getters
    std::string getName();

    int getDefBonus();

    int getFood();

    int getMoney();

    int getCurrentLord();

    int getSide();

    int getPopulation();

    int getIncome();

    Coords getPosition();

    sf::Sprite getImage();

    //setters
    void setName(std::string name);

    bool setCurrentLord(int newLord);

    bool setSide();

    bool setPosition(Coords newC);

    bool SetNewBuilding(BuildingType newB);

    bool setImage(sf::Texture texture);

    bool setImageScale(int a, int b=0);

    //other:
    bool increasePopulation(int change);

    bool addBuilding(BuildingType newB);

    bool updateParams(); //updates income, food and def_bonus

};


#endif // CASTLE_HPP_INCLUDED
