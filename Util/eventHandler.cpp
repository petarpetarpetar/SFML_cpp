#include "eventHandler.hpp"

eventHandler::eventHandler()
{
    std::cout << "created eventHandler\n";
}
eventHandler::~eventHandler()
{
    std::cout << "destroyed eventHandler\n";
}

void eventHandler::handle(sf::Event event,sf::RenderWindow& window,sf::Sprite sprites[10][2][10],Game g)
{
    if (event.type == sf::Event::Closed) window.close();
    switch(event.type)
            {
                case(sf::Event::Closed):
                    window.close();

                    break;

                case(sf::Event::MouseButtonPressed):
                    //there should be option to get what mouse button(left or right was pressed);
                    if(event.mouseButton.button == sf::Mouse::Right){
                        std::cout << "the right button was pressed" << std::endl;
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    }
                    if(event.mouseButton.button == sf::Mouse::Left){
                        if(sprites[0][1][0].getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
                        {
                            std::cout <<"clicked on lord"; //radi
                        }

                    }

                    break;

            }

}
