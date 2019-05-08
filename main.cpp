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
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Knights of Honor - Petar Markovic");
    sf::RectangleShape grass(sf::Vector2f(WIDTH, HEIGHT)); //grass terrain shape
    grass.setFillColor(sf::Color(30,180,10));

    sf::Sprite sprites[10][2][10];
    sf::Sprite side_menu;
    sf::Sprite coin_icon;

    // #done - initialize game window

    //load all textures:

    sf::Texture castle_texture;
    if(!castle_texture.loadFromFile("resources/graphics_castle.png"))
    {
        std::cout <<"error: failed to load graphics_castle.png"<<std::endl;
        return -1;
    }
    std::cout << "done: Successfully loaded graphics_castle.png"<<std::endl;

    sf::Texture lord_texture;
    if(!lord_texture.loadFromFile("resources/JPG_graphics_lord.jpg"))
    {
        std::cout << "error: failed to load JPG_graphics_lord.jpg"<<std::endl;
    }
    sf::Texture sultan_texture;
    if(!sultan_texture.loadFromFile("resources/sultan.jpg"))
    {
        std::cout << "error: failed to load sultan.jpg\n";
    }

    sf::Texture side_menu_texture;
    if(!side_menu_texture.loadFromFile("resources/side_texture.jpg"))
    {
        std::cout <<"error:failed to load side_texture.jpg"<<std::endl;
    }
    std::cout <<"done: Successfully loaded JPG_graphics_lord.jpg"<<std::endl;

    sf::Texture coin_icon_texture;
    if(!coin_icon_texture.loadFromFile("resources/coin-icon.png"))
    {
        std::cout <<"error:failed to load coin-icon.png"<<std::endl;
    }

    // #done - load all textures

    Game g;
    //update everything using references.
    Game& gref = g;
    sf::RenderWindow& winref = window;



    //this should be changed with just one load from file command

    Player p1(0,"asd");
    Player p2(1,"petar");

    g.addPlayer(p1);
    g.addPlayer(p2);

    g.addMoney(1,1000);
    Castle temp(750,50);
    Lord tempL(700,300,"asad al husein quran");
    g.addCastle(0,temp);
    g.addLord(0,tempL);

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

