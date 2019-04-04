#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <iostream>
#include <vector>
#include "Lord.hpp"
#include "Clock.hpp"
#include "Castle.hpp"
#include "GameRules.cpp"
#include "Player.hpp"
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

    Castle getCastle(int playerID, int CastleID);
    Lord getLord(int playerID, int lordID);



};


#endif // GAME_HPP_INCLUDED
