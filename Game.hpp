#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <iostream>
#include <vector>
#include "Util/Lord.hpp"
#include "Util/Clock.hpp"
#include "Util/Castle.hpp"
#include "Util/GameRules.cpp"
#include "Util/Player.hpp"

#include <SFML/Graphics.hpp>

class Game
{
private:


    sf::RenderWindow window;
    sf::Sprite sprites[10][2][10];
    sf::Sprite side_menu,coin_icon,side_info;
    sf::RectangleShape grass;
    sf::Font font;
    sf::Text coin_text;
    sf::Text name,entity_name;
    Lord selectL;
    bool selectL_flag=false;
    Castle selectC;
    bool selectC_flag=false;


    sf::Texture castle_texture,lord_texture,sultan_texture,side_menu_texture,coin_icon_texture,side_info_texture;
    std::vector<Player> players;
    Clock clock;

public:

    Game();

    //getters
    int getNumLords(int playerID);
    int getNumCastle(int playerID);
    long int getTDiff();
    long int getCurrentTime();
    int getNumPlayers();
    int getMoney(int PlayerID);
    std::string getCastleName(int playerID,int castleID);
    std::string getPlayerName(int ID);
    Castle getCastle(int playerID, int CastleID);
    Lord getLord(int playerID, int lordID);
    Player getPlayer(int playerID);

    //setters
    void setCastleName(int playerID,int castleID,std::string name);
    bool setPlayerName(int ID, std::string newN);

    //adding methods
    bool addPlayerModule(Player p);
    bool addPlayer(int ID, std::string name);

    bool addCastleModule(int playedID,Castle newC);
    bool addCastle(int playerID, int x, int y,std::string name);

    bool addLordModule(int playerID,Lord newL);
    bool addLord(int playerID, int x, int y, std::string name);

    bool addMoney(int playerID,int val);

    //other methods
    bool newPlayer();
    bool updateTime();
    bool calcTimeDiff();
    void loadTextures();
    void draw();
    void check();
    void handle(sf::Event event);
    void update();
    void run();
    bool isRunning();
    sf::RenderWindow getWin();
};


#endif // GAME_HPP_INCLUDED
