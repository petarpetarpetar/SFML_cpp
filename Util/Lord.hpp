#ifndef LORD_HPP_INCLUDED
#define LORD_HPP_INCLUDED
#include "Coords.hpp"
#include "Army.hpp"
#include <iostream>
class Lord
{
private:
    Army army;


    int moveSpeed;
    int battlesWon;
    int side;
    int lastBattle;
    std::string name;
    Coords position;
    int _status; //alive or dead   mozda ide samo status _status nisam sig   0-dead, 1-alive, 2-in_castle

public:
    Lord(int posX, int posY, std::string _name );

    int getMoveSpeed();
    int getBattlesWon();
    int getStatus();
    Coords getPosition();
    bool setStatus(int newStatus);
    bool incBattlesWon();
    bool setPos(Coords newPos);
    bool setSide(int _side);

    //some army functions


};


#endif // LORD_HPP_INCLUDED
