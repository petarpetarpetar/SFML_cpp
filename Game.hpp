#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <iostream>
#include "Clock.hpp"
class Game
{
private:
    int number_of_lords;
    int number_of_castles;
    std::string name_side1;
    std::string name_side2;
    Clock clock;

public:

    Game(int nL,int nC,std::string side1,std::string side2);
    int getNumLords();
    int getNumCastle();

    bool updateTime();
    bool calcTimeDiff();
    long int getTDiff();





};


#endif // GAME_HPP_INCLUDED
