#include <iostream>
#include "Game.hpp"

long int game_cycle = 0;
int player_coutn = 0;
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Util/eventHandler.hpp"
int gamestate_temp = 0;
//0 - loading everything and players connecting
//1 - castle placement
//2 - game begins


int main()
{
    //sf::RectangleShape grass(sf::Vector2f(WIDTH, HEIGHT)); //grass terrain shape
    //grass.setFillColor(sf::Color(30,180,10));
    Game g;

    g.addPlayer(0,"petar");
    g.addPlayer(1,"enemy");
    g.addMoney(1,1000);
    g.addCastle(0,300,300,"dvorac1");
    g.addLord(0,300,800,"lord11");
    g.addCastle(1,500,500,"dvorac2");
    g.addLord(1,600,200,"lord22");

    //castle
    sprites[0][0][0].setTexture(castle_texture);
    sprites[0][0][0].setScale(0.2,0.2);

    //Lord
    sprites[0][1][0].setTexture(lord_texture);
    sprites[0][1][0].setScale(0.1,0.1);

    //sultan
    sprites[0][1][1].setTexture(sultan_texture);
    sprites[0][1][1].setScale(1,1);


    Coords temp_pos = g.getCastle(0,0).getPosition();
    Coords temp_lord_c = g.getLord(0,0).getPosition();


    sprites[0][0][0].setPosition(temp_pos.getX(),temp_pos.getY());
    sprites[0][1][0].setPosition(temp_lord_c.getX(),temp_lord_c.getY());
    sprites[0][1][1].setPosition(800,300);
    //idi kroz sve 0, n, 0 sprajtove i postavi da budu lord ili castle i slicno za 0,0,n


    //stats display - TEXT
    sf::Font font;
    sf::Text coin_text;
    font.loadFromFile("resources/fonts/MIROSLN.ttf");
    sf::Text name;
    coin_text.setFont(font);
    name.setFont(font);
    int myId=1;

    coin_text.setString(std::to_string(g.getMoney(myId)));
    coin_text.setPosition(5,5);
    coin_text.setScale(0.9,0.9);
    coin_text.setColor(sf::Color::Black);

    name.setString(g.getPlayer(myId).getName());
    name.setPosition(WIDTH/2,0);
    name.setScale(1.2,1.2);
    name.setColor(sf::Color::Black);

    side_menu_texture.setRepeated(true);
    side_menu.setTexture(side_menu_texture,true);
    side_menu.setTextureRect(sf::IntRect(0,0,WIDTH,40));
    coin_icon.setTexture(coin_icon_texture,true);
    coin_icon.setPosition(100,5);
    coin_icon.setScale(0.2,0.2);
    eventHandler handler;

    Lord selectL;
    bool selectL_flag=false;
    Castle selectC;
    bool selectC_flag=false;

    while (window.isOpen())
    {
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            sf::Event& event = ev;
            handler.handle(ev,winref,sprites,&g,&selectL,&selectC);



        }

        window.draw(grass);
        window.draw(side_menu);
        window.draw(sprites[0][0][0]);
        window.draw(sprites[0][1][0]);
        window.draw(sprites[0][1][1]);
        window.draw(coin_icon);
        window.draw(name);
        window.draw(coin_text);
        g.addMoney(1,2);
        coin_text.setString(std::to_string(g.getMoney(myId)));
        window.display();




        //ignore for now

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

