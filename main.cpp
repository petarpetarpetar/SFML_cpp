#include <iostream>
#include "Game.hpp"
long int game_cycle=0;
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
int main()
{

    //initialize game window:

    sf::RenderWindow window(sf::VideoMode(1300, 650), "Knights of Honor - Petar Markovic");
    sf::RectangleShape grass(sf::Vector2f(1300,650)); //grass terrain shape

    grass.setFillColor(sf::Color::Green);

    sf::Sprite sprites[10][2][10];

    // #done - initialize game window

    //load all textures:

    sf::Texture castle_texture;
    if(!castle_texture.loadFromFile("castle_texture_1.png"))
    {
        std::cout <<"failed to load castle_texture_1.png"<<std::endl;
        return -1;
    }


    // #done - load all textures

    Game g;

    //this should be changed with just one load from file command

    Player p1(0,1,1,"ime1");
    Player p2(1,1,1,"ime2");
    g.addPlayer(p1);
    g.addPlayer(p2);
    Castle temp(10,10);
    g.addCastle(0,temp);

    sprites[0][0][0].setTexture(castle_texture);
    sprites[0][0][0].setScale(0.1,0.1);

    Castle temp_castle = g.getCastle(0,0);
    Coords temp_pos = g.getCastle(0,0).getPosition();


    sprites[0][0][0].setPosition(temp_pos.getX(),temp_pos.getY());

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


        for(int i =0; i < g.getNumPlayers();i++)
        {
            //draw all the castles on the map
            for(int j = 0; j < g.getPlayer(i).getNumCastle(); j++)
            {
                //window.draw(sprites[i][0][j]);
            }

            //draw all the lords on the map
            for(int j = 0; j < g.getPlayer(i).getNumLords(); j++)
            {
                //window.draw(sprites[i][1][j]);
            }
        }

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

