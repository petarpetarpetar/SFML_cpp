#ifndef LORD_HPP_INCLUDED
#define LORD_HPP_INCLUDED
#include "Coords.hpp"
#include "Army.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
class Lord
{
private:
    Army army;
    sf::Sprite image;
    int moveSpeed;
    int battlesWon;
    int side;
    int lastBattle;
    std::string name;
    Coords position;
    int _status; //alive or dead   mozda ide samo status _status nisam sig   0-dead, 1-alive, 2-in_castle

public:

    Lord(){std::cout <<"temp lord created"<<std::endl;}
    Lord(int posX, int posY, std::string _name );
    Lord(int a);
    sf::Sprite getImage();
    void setImage(sf::Texture texture);
    void setImageScale(int a,int b=0);
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
