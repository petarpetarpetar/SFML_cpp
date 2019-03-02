#include <iostream>
#include "Game.hpp"
#include "Castle.hpp"
#include <SFML/Graphics.hpp>
long int game_cycle=0;

int main()
{

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);

    int r=0,g=0,b=0;
    while (window.isOpen())
    {
        sf::Event event;


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
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

