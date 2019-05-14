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
    Castle temp(100,100,"ugljevik");
    g.addCastleModule(0,temp);
    g.run();
    //g.addLord(0,300,800,"lord11");
    //g.addCastle(1,500,500,"dvorac2");
    //g.addLord(1,600,200,"lord22");
/*
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


    //stats display - TEXT

    // use:    coin_text.setString(std::to_string(g.getMoney(myId)));
*/



    while (g.isRunning())
    {
        //g check for events
        g.check();
        g.draw();
    }



        //ignore for now

    /**<
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
    */

    return 0;
}

    /*
    Game game(4,4,"red","blue");
    game.updateTime();
    while(1){
        game.calcTimeDiff();
        if(game.getTDiff()>=1){std::cout << "UPDATE#" << up_count++ << std::endl; game.updateTime();break;}


    }*/

