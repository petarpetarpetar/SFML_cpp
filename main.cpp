#include <iostream>
#include "Game.hpp"
long int game_cycle=0;
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
int main()
{

    sf::RenderWindow window(sf::VideoMode(1300, 650), "Knights of Honor - Petar Markovic");

    sf::RectangleShape grass(sf::Vector2f(1300,650)); //proveri je li dobra matrica
    grass.setFillColor(sf::Color::Green);
    sf::Sprite sprites[10][10][10];



    // load all textures

    Game g;

    Player p1(0,1,1,"ime1");
    Player p2(1,1,1,"ime2");
    g.addPlayer(p1);
    g.addPlayer(p2);

    Castle temp(10,10);
    g.addCastle(0,temp);

    sf::Texture te;
    if(!te.loadFromFile("castle_texture_1.png"))
    {
        std::cout <<"failed to load castle_texture_1.png"<<std::endl;
        return -1;
    }
    sprites[0][0][0].setTexture(te);
    sprites[0][0][0].setScale(0.1,0.1);

    sprites[0][0][0].setPosition(100,100);

    //idi kroz sve 0, n, 0 sprajtove i postavi da budu lord ili castle i slicno za 0,0,n



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
             if (event.type == sf::Event::Closed)
                window.close();

        }

        window.draw(grass);
        window.draw(sprites[0][0][0]);
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

