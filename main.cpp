#include <iostream>
#include "Game.hpp"
#include "eventHandler.hpp"
long int game_cycle=0;

int main()
{

    sf::RenderWindow window(sf::VideoMode(1300, 650), "Knights of Honor - Petar Markovic");
    sf::RectangleShape shape(sf::Vector2f(1300,650));
    shape.setFillColor(sf::Color(10,140,0));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            updateEvents(sf::Event ev);
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}


    /*
    Game game(4,4,"red","blue");
    game.updateTime();
    while(1){
        game.calcTimeDiff();
        if(game.getTDiff()>=1){std::cout << "UPDATE#" << up_count++ << std::endl; game.updateTime();break;}


    }*/

