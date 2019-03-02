#ifndef LORD_HPP_INCLUDED
#define LORD_HPP_INCLUDED
#include "Coords.hpp"
#include "Army.hpp"
#include <iostream>
class Lord
{
private:
    Army army;
    enum status
    {
        dead = 0,
        alive = 1,
        wounded = 2,
        imprisoned = 3
    };
    int moveSpeed;
    int battlesWon;
    int side;
    int lastBattle;
    std::string name;
    Coords pos;
    int _status; //alive or dead   mozda ide samo status _status nisam sig

public:
    Lord(int side,std::string name);

    int getMoveSpeed();
    int getBattlesWon();
    int getStatus();
    Coords getPos();

    bool setStatus(int newStatus);
    bool incBattlesWon();
    bool setPos(Coords newPos);
;
    //some army functions


};


#endif // LORD_HPP_INCLUDED
