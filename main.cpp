#include <iostream>
#include "Game.hpp"
#include "Castle.hpp"
int main()
{
    long int up_count=0;
    Game game(4,4,"red","blue");
    game.updateTime();
    while(1){
        game.calcTimeDiff();
        if(game.getTDiff()>=1){std::cout << "UPDATE#" << up_count++ << std::endl; game.updateTime();break;}


    }
    return 0;
}
