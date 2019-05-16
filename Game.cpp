#include "Game.hpp"

void Game::check()
{
     sf::Event event;
        while (window.pollEvent(event))
            handle(event);
}

void Game::draw()
{
    //update everything
    //std::cout <<"display loop========= \n";
    //std::cout <<"number of players:"<<getNumPlayers()<<std::endl;

    if(selectC_flag){entity_name.setString(selectC.getName());}
    else if(selectL_flag){entity_name.setString(selectL.getName());}
    else {entity_name.setString("");}
    window.draw(grass);
    window.draw(side_menu);
    window.draw(coin_icon);
    window.draw(coin_text);
    window.draw(side_info);
    window.draw(name);
    window.draw(entity_name);
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
                        //first find to what spr
                        for(int i =0;i<getNumPlayers();i++)
                        {
                            for(int j =0;j<getNumLords(i);j++)
                            {

                                //std::cout << sprites[i][1][j].getGlobalBounds().left << " " << sprites[i][1][j].getGlobalBounds().top;
                                //std::cout << " " << sprites[i][1][j].getGlobalBounds().width << " " << sprites[i][1][j].getGlobalBounds().height << std::endl;

                                if(sprites[i][1][j].getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                                {
                                    std::cout <<"it suits to lord i/j : " << i << "/" << j <<std::endl;
                                        Coords temp = getLord(i,j).getPosition();
                                        std::cout <<"temp cords of lord = " << temp.getX()<<" " << temp.getY() <<std::endl;

                                            if(sprites[i][1][j].getPosition().x == temp.getX() && sprites[i][1][j].getPosition().y == temp.getY())
                                            {
                                                std::cout << "returning from function, found lord\n";
                                                selectL = (getLord(i,j));
                                                selectC_flag = false;
                                                selectL_flag = true;
                                                return;
                                            }
                                }
                            }
                        }
                            for(int i =0;i<getNumPlayers();i++)
                            {
                                for(int j =0;j<getNumCastle(i);j++)
                                {
                                    if(sprites[i][0][j].getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                                    {
                                        std::cout << "it suits to castle i/j : " << i << "/" << j <<std::endl;
                                        Coords temp = getCastle(i,j).getPosition();
                                        std::cout << "temp cords of castle = " << temp.getX() <<" "<< temp.getY() <<std::endl;
                                        if(sprites[i][0][j].getPosition().x == temp.getX())
                                            if(sprites[i][0][j].getPosition().y == temp.getY())
                                            {
                                                std::cout << "returning from function, found castle \n";
                                                selectC = (getCastle(i,j));
                                                selectC_flag = true;
                                                selectL_flag = false;
                                                return;
                                            }
                                        }
                                    }
                                }


                        //if clicked on grass
                        selectC_flag = false;
                        selectL_flag = false;
                        std::cout << "returning from function, found nothing.\n";
                        return;

                break;
            }
        }

}

void Game::run()
{

    for(int i=0;i<10;i++)
    {
        for(int j =0; j<10;j++)
        {
            sprites[i][0][j].setScale(0.2,0.2);
            sprites[i][1][j].setScale(0.1,0.1);
            //sprites[i][1][j].setOrigin(sf::Vector2f(sprites[i][1][j].getTexture()->getSize().x * 0.5 / 5,sprites[i][1][j].getTexture()->getSize().y * 0.5 / 5));
            //sprites[i][0][j].setOrigin(sf::Vector2f(sprites[i][0][j].getTexture()->getSize().x * 0.5 / 10,sprites[i][0][j].getTexture()->getSize().y * 0.5 / 10));
        }
    }
    loadTextures();
    grass.setFillColor(sf::Color(30,180,10));
    side_menu_texture.setRepeated(true);
    side_menu.setTexture(side_menu_texture,true);
    side_menu.setTextureRect(sf::IntRect(0,0,WIDTH,40));

    side_info_texture.setRepeated(true);
    side_info.setTexture(side_info_texture);
    side_info.setTextureRect(sf::IntRect(0,0,100,HEIGHT));
    side_info.setPosition(WIDTH-100,0);


    font.loadFromFile("resources/fonts/MIROSLN.ttf");
    int myId = 0; //temp fix. shall be passed by networking driver
    coin_text.setFont(font);
    coin_text.setPosition(5,5);
    coin_text.setScale(0.9,0.9);
    coin_text.setColor(sf::Color::Black);
    coin_text.setString(std::to_string(getMoney(myId)));
    coin_icon.setTexture(coin_icon_texture,true);
    coin_icon.setPosition(100,5);
    coin_icon.setScale(0.2,0.2);

    name.setFont(font);
    name.setString(getPlayer(myId).getName());
    name.setPosition(WIDTH/2,0);
    name.setScale(1.2,1.2);
    name.setColor(sf::Color::Black);

    entity_name.setFont(font);
    entity_name.setPosition(WIDTH-90,0);
    entity_name.setScale(0.9,0.9);
    entity_name.setColor(sf::Color::Black);


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
            sprites[i][1][j].setPosition(getLord(i,j).getPosition().getX(),getLord(i,j).getPosition().getY());
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
        std::cout << "error: failed to load graphics_castle.png"<<std::endl;
    if(!side_menu_texture.loadFromFile("resources/side_texture.jpg"))
        std::cout << "error:failed to load side_texture.jpg"<<std::endl;
    if(!lord_texture.loadFromFile("resources/JPG_graphics_lord.jpg"))
        std::cout << "error: failed to load JPG_graphics_lord.jpg"<<std::endl;
    if(!sultan_texture.loadFromFile("resources/sultan.jpg"))
        std::cout << "error: failed to load sultan.jpg\n";
    if(!coin_icon_texture.loadFromFile("resources/coin-icon.png"))
        std::cout << "error:failed to load coin-icon.png"<<std::endl;
    if(!side_info_texture.loadFromFile("resources/stone_texture.jpg"))
        std::cout << "error: failed to load stone_texture.jpg" <<std::endl;
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
    Lord temp;
    Coords pos;
    pos.setX(x);
    pos.setY(y);
    temp.setPos(pos);
    temp.setName(name); // ovo treba da uradis
    addLordModule(playerID,temp);
    return true;
}

bool Game::addCastleModule(int playerID,Castle newC)
{
    players.at(playerID).addCastle(newC);
    return true;
}

bool Game::addCastle(int playerID,int x,int y,std::string name)
{
    Castle temp;
    Coords pos(x,y);
    temp.setName(name);
    temp.setPosition(pos);
    addCastleModule(playerID,temp);

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


void update()
{
    //update everything
}


