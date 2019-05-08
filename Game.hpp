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



    //replace all of this with:
    std::vector<Player> players;
    Clock clock;
public:

    Game();

    int getNumLords(int playerID);
    int getNumCastle(int playerID);
    Player getPlayer(int playerID);
    bool newPlayer();
    bool updateTime();
    bool calcTimeDiff();
    long int getTDiff();
    long int getCurrentTime();
    bool addPlayer(Player p);
    bool addCastle(int playedID,Castle newC);
    bool addLord(int playerID,Lord newL);
    int getNumPlayers();

    int getMoney(int PlayerID);
    std::string getPlayerName(int ID);
    bool setPlayerName(int ID, std::string newN);

    bool addMoney(int playerID,int val);
    Castle getCastle(int playerID, int CastleID);
    Lord getLord(int playerID, int lordID);

    std::string getCastleName(int playerID,int castleID);
    void setCastleName(int playerID,int castleID,std::string name);

};


#endif // GAME_HPP_INCLUDED
