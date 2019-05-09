#include "Game.hpp"

Game::Game() : clock(), window(sf::VideoMode(WIDTH, HEIGHT), "Knights of Honor - Petar Markovic")
{
    std::cout << "a new game session started"<<std::endl;
}

void Game::loadTextures()
{
    if(!castle_texture.loadFromFile("resources/graphics_castle.png"))
        std::cout <<"error: failed to load graphics_castle.png"<<std::endl;
    if(!side_menu_texture.loadFromFile("resources/side_texture.jpg"))
        std::cout <<"error:failed to load side_texture.jpg"<<std::endl;
    if(!lord_texture.loadFromFile("resources/JPG_graphics_lord.jpg"))
        std::cout << "error: failed to load JPG_graphics_lord.jpg"<<std::endl;
    if(!sultan_texture.loadFromFile("resources/sultan.jpg"))
        std::cout << "error: failed to load sultan.jpg\n";
    if(!coin_icon_texture.loadFromFile("resources/coin-icon.png"))
        std::cout <<"error:failed to load coin-icon.png"<<std::endl;

}
long int Game::getCurrentTime()
{
    return clock.getTime();
}

int Game::getNumCastle(int playerID)
{
    return this->players.at(playerID).getNumCastle();
}

int Game::getNumLords(int playerID)
{
    return this->players.at(playerID).getNumLords();
}

bool Game::calcTimeDiff()
{
    clock.calcTimeDiff();
    return true;
}

bool Game::updateTime()
{
    clock.updateTime();
    return true;
}

long int Game::getTDiff()
{
    return clock.getTimeDiff();
}

Player Game::getPlayer(int playerID)
{
    return players.at(playerID);
}

bool Game::addCastleModule(int playerID,Castle newC)
{
    players.at(playerID).addCaste(newC);
    return true;
}
bool Game::addCastle(int playerID,int x,int y,std::string name)
{
    Castle c(int x,int y,std::string name);
    players.at(playerID).addCaste(c);
    return true;
}

int Game::getNumPlayers()
{
    return this->players.size();
}

bool Game::addLordModule(int playerID,Lord newL)
{
    players.at(playerID).addLord(newL);
    return true;
}

bool Game::addLord(int playerID,int x,int y, std::string name)
{
    Lord temp(x,y,name);
    addLordModule(playerID,temp);
    return true;
}

bool Game::addPlayerModule(Player p)
{
    players.push_back(p);
    return true;
}

bool Game::addPlayer(int ID, std::string name)
{
    Player temp(ID,name);
    players.push_back(temp);
    return true;
}

Castle Game::getCastle(int playerID, int castleID)
{
    return players.at(playerID).getCastle(castleID);
}

Lord Game::getLord(int playerID, int lordID)
{
    return players.at(playerID).getLord(lordID);
}

std::string Game::getCastleName(int PlayerID,int CastleID)
{
    return this->players.at(PlayerID).getCastle(CastleID).getName();
}

void Game::setCastleName(int PlayerID,int CastleID, std::string name)
{
    players.at(PlayerID).setCastleName(CastleID,name);
}

std::string Game::getPlayerName(int ID)
{
    return players.at(ID).getName();
}

bool Game::setPlayerName(int ID, std::string newN)
{
    players.at(ID).setName(newN);
    return true;
}

int Game::getMoney(int PlayerID)
{
    return players.at(PlayerID).getMoney();
}

bool Game::addMoney(int PlayerID,int val)
{
    players.at(PlayerID).addMoney(val);
    return true;
}

