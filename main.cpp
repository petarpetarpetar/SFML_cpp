#include <iostream>
#include "Game.hpp"
long int game_cycle = 0;
int player_coutn = 0;
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
int main()
{

    //initialize game window:

    sf::RenderWindow window(sf::VideoMode(1340, 680), "Knights of Honor - Petar Markovic");
    sf::RectangleShape grass(sf::Vector2f(1340,680)); //grass terrain shape
    sf::RectangleShape side_menu(sf::Vector2f(1340,40));
    side_menu.setFillColor(sf::Color::Blue);
    grass.setFillColor(sf::Color(30,180,10));

    sf::Sprite sprites[10][2][10];

    // #done - initialize game window

    //load all textures:

    sf::Texture castle_texture;
    if(!castle_texture.loadFromFile("graphics_castle.png"))
    {
        std::cout <<"error: failed to load graphics_castle.png"<<std::endl;
        return -1;
    }
    std::cout << "done: Successfully loaded graphics_castle.png"<<std::endl;

    sf::Texture lord_texture;
    if(!lord_texture.loadFromFile("JPG_graphics_lord.jpg"))
    {
        std::cout <<"error: failed to load JPG_graphics_lord.jpg"<<std::endl;
    }
    std::cout <<"done: Successfully loaded JPG_graphics_lord.jpg"<<std::endl;


    // #done - load all textures

    Game g;

    //this should be changed with just one load from file command

    Player p1(0,1,1,"player1");
    Player p2(1,1,1,"player2");

    g.addPlayer(p1);
    g.addPlayer(p2);

    Castle temp(10,10);
    Lord tempL(300,300,"asad al husein quran");
    g.addCastle(0,temp);
    g.addLord(0,tempL);

    //castle
    sprites[0][0][0].setTexture(castle_texture);
    sprites[0][0][0].setScale(0.2,0.2);

    //Lord
    sprites[0][1][0].setTexture(lord_texture);
    sprites[0][1][0].setScale(0.2,0.2);

    Coords temp_pos = g.getCastle(0,0).getPosition();
    Coords temp_lord_c = g.getLord(0,0).getPosition();


    sprites[0][0][0].setPosition(temp_pos.getX(),temp_pos.getY());
    sprites[0][1][0].setPosition(temp_lord_c.getX(),temp_lord_c.getY());
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
        window.draw(side_menu);
        window.draw(sprites[0][1][0]);
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

