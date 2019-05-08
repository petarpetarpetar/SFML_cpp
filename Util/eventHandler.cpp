#include "eventHandler.hpp"

eventHandler::eventHandler()
{
    std::cout << "created eventHandler\n";
}
eventHandler::~eventHandler()
{
    std::cout << "destroyed eventHandler\n";
}

void eventHandler::handle(sf::Event event,sf::RenderWindow& window,sf::Sprite sprites[10][2][10],Game* g,Lord* selectL, Castle* selectC)
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
                            for(int i =0;i<g->getNumPlayers();i++)
                            {
                                for(int j = 0;j < g->getNumLords(i); j++)
                                {
                                    std::cout<<"debug";
                                        if(g->getNumLords(i)==0){continue;}
                                        Coords temp = g->getLord(i,j).getPosition();
                                        float spriteLocX;
                                        float spriteLocY;
                                        spriteLocX = sprites[i][1][j].getPosition().x;
                                        spriteLocY = sprites[i][1][j].getPosition().y;
                                        std::cout << "locX,locY: " << spriteLocX << "," << spriteLocY << std::endl;
                                        std::cout << "uporedjuj: " << temp.getX()<<","<<temp.getY() <<std::endl;
                                        if(spriteLocX == temp.getX() && spriteLocY == temp.getY())
                                        {
                                            std::cout << "returning from function.\n";
                                            *selectL = g->getLord(i,j);
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
