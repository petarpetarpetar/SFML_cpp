#include "Game.hpp"

void Game::check()
{
     sf::Event event;
        while (window.pollEvent(event))
            handle(event);
}

void Game::draw()
{

    //std::cout <<"display loop========= \n";
    //std::cout <<"number of players:"<<getNumPlayers()<<std::endl;

    window.draw(grass);
    window.draw(side_menu);
    window.draw(coin_icon);
    window.draw(coin_text);
    for(int i=0;i<getNumPlayers();i++)
    {
        //std::cout <<"player["<<i<<"] castles: " << getNumCastle(i) <<std::endl;
        for(int j=0;j<getNumCastle(i);j++)
        {

            window.draw(sprites[i][0][j]);

        }

        //std::cout <<"player["<<i<<"] lords: " << getNumLords(i) << std::endl;
        for(int j=0;j<getNumLords(i);j++)
        {
            window.draw(sprites[i][1][j]);
        }
    }

    window.display();


}
void Game::handle(sf::Event event)
{

    switch(event.type)
            {
                case(sf::Event::Closed):
                    window.close();

                    break;

                case(sf::Event::MouseButtonPressed):
                    std::cout <<"click : " << event.mouseButton.x << " " << event.mouseButton.y <<std::endl;
                    if(event.mouseButton.button == sf::Mouse::Right){
                        std::cout << "the right button was pressed" << std::endl;}

                    if(event.mouseButton.button == sf::Mouse::Left){
                        //check if click contains a sprite (should be looped through every possible sprite
                        std::cout << sprites[0][1][0].getGlobalBounds().left << " " << sprites[0][1][0].getGlobalBounds().top;
                        std::cout << " " << sprites[0][1][0].getGlobalBounds().width << " " << sprites[0][1][0].getGlobalBounds().height << std::endl;
                        if(sprites[0][1][0].getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                        {
                            for(int i =0;i<getNumPlayers();i++)
                            {
                                for(int j = 0;j <getNumLords(i); j++)
                                {
                                    std::cout<<"debug";
                                        if(getNumLords(i)==0){continue;}
                                        Coords temp =getLord(i,j).getPosition();
                                        float spriteLocX;
                                        float spriteLocY;
                                        spriteLocX = sprites[i][1][j].getPosition().x;
                                        spriteLocY = sprites[i][1][j].getPosition().y;
                                        std::cout << "locX,locY: " << spriteLocX << "," << spriteLocY << std::endl;
                                        std::cout << "uporedjuj: " << temp.getX()<<","<<temp.getY() <<std::endl;
                                        if(spriteLocX == temp.getX() && spriteLocY == temp.getY())
                                        {
                                            std::cout << "returning from function.\n";
                                            selectL = (getLord(i,j));
                                            return;

                                        }
                                }
                                //or may it be castle
                            }
                        }
                    }

                    break;

            }

}

void Game::run()
{
    loadTextures();

    grass.setFillColor(sf::Color(30,180,10));
    side_menu_texture.setRepeated(true);
    side_menu.setTexture(side_menu_texture,true);
    side_menu.setTextureRect(sf::IntRect(0,0,WIDTH,40));

    font.loadFromFile("resources/fonts/MIROSLN.ttf");

    coin_text.setFont(font);
    coin_text.setPosition(5,5);
    coin_text.setScale(0.9,0.9);
    coin_text.setColor(sf::Color::Black);

    coin_icon.setTexture(coin_icon_texture,true);
    coin_icon.setPosition(100,5);
    coin_icon.setScale(0.2,0.2);
    int myId = 1; //temp fix. shall be passed by networking driver
    name.setFont(font);
    name.setString(getPlayer(myId).getName());
    name.setPosition(WIDTH/2,0);
    name.setScale(1.2,1.2);
    name.setColor(sf::Color::Black);


    for(int i=0;i<getNumPlayers();i++)
    {
        for(int j=0;j<getNumCastle(i);j++)
        {
            sprites[i][0][j].setTexture(castle_texture);
            sprites[i][0][j].setPosition(getCastle(i,j).getPosition().getX(),getCastle(i,j).getPosition().getY());
        }

        for(int j=0;j<getNumLords(i);j++)
        {
            sprites[i][1][j].setTexture(lord_texture);
            sprites[i][0][j].setPosition(getLord(i,j).getPosition().getX(),getLord(i,j).getPosition().getY());
        }
    }


}
Game::Game() : clock(), window(sf::VideoMode(WIDTH, HEIGHT), "Knights of Honor - Petar Markovic"), grass(sf::Vector2f(WIDTH,HEIGHT))
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
    players.at(playerID).addCastle(newC);
    return true;
}
/*
bool Game::addCastle(int playerID,int x,int y,std::string name)
{
    Castle c(int x,int y,std::string name);
    players.at(playerID).addCastle(c);
    return true;
}
*/
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

bool Game::isRunning()
{
    return window.isOpen();
}
