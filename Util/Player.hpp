#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
#include <vector>
#include <bits/stdc++.h>
#include "Lord.hpp"
#include "Castle.hpp"
class Player
{
private:
    int ID;
    int number_of_lords;
    int number_of_castles;
    std::string name;
    std::vector<Lord> lords;
    std::vector<Castle> castles;
    int money;

public:

    Player(int playerID);
    Player(int playerID,int number_of_lords, int number_of_castles,std::string name);
    int getNumLords();
    int getNumCastle();
    bool addCaste(Castle newC);
    bool addLord(Lord newL);
    Castle getCastle(int castleID);
    Lord getLord(int lordID);
    bool setName(std::string newN);
    std::string getName();
    int getMoney();
    bool addMoney(int val);


};


#endif // PLAYER_HPP_INCLUDED
